#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <math.h>

#include <DHT.h>
#define DHTPIN 17
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);



typedef struct O_meu_wifi
{
    String ssid;
    String password;
};

O_meu_wifi o_meu_wifi = {
    .ssid ="IEFP-Formacao",
    .password =""
};


typedef struct DHT11_1
{
  float temperatura;
  String estado_botao;
  int tempo_leitura;
  int ligado;
  int desligado;
};

DHT11_1 dht11;



unsigned long previous = 0;

enum State
  {
    Standby = 0,
    leitura
  };

State estado = Standby;



WebServer server(80);

void Root();


void Root_button() 
{
  dht11.estado_botao = "on";
  estado = leitura;
  Root();
}

void Root_button_off() {
  dht11.estado_botao = "off";
  estado = Standby;
  Root();
}


void setup()
{
 
  dht11.temperatura = 0.0;
  dht11.estado_botao = "off";
  dht11.tempo_leitura = 2000;
  dht11.ligado = 16;
  dht11.desligado = 4;
  
  Serial.begin(115200);
  pinMode(DHTPIN, INPUT);
  pinMode(dht11.ligado, OUTPUT);
  pinMode(dht11.desligado, OUTPUT);
  Serial.println(o_meu_wifi.ssid);
  WiFi.begin(o_meu_wifi.ssid.c_str(), o_meu_wifi.password.c_str());
  dht.begin();
  digitalWrite(dht11.ligado, LOW);
  digitalWrite(dht11.desligado, LOW);


  int tentativas = 0;
    while(WiFi.status() != WL_CONNECTED && tentativas <5)
    {
        tentativas++;
        delay(500);
        Serial.print("."); 
    }
    if(WiFi.status() != WL_CONNECTED)
    {
        Serial.print("not connected");
    }
    else
    {
        Serial.print("wifi connected: ");
        Serial.println(o_meu_wifi.ssid);
        Serial.println(WiFi.localIP());
    }

    server.on("/", Root);
    server.on("/button/on", Root_button);
    server.on("/button/off", Root_button_off);
    server.on("/temp", []() 
    {
      server.send(200, "text/plain", String(dht11.temperatura));
    });

    // conectar ao servidor
    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
  switch(estado)
  {
    case Standby:
      // aguardar pelo botao
      digitalWrite(dht11.ligado, LOW);
      digitalWrite(dht11.desligado, LOW);
      break;

    case leitura:
      // aqui deve ser feita a leitura do DHT11
      if (millis()- previous >= dht11.tempo_leitura)
      {
        dht11.temperatura = dht.readTemperature(); // Lendo temperatura do DHT11
        if(isnan(dht11.temperatura))
        {
          digitalWrite(dht11.desligado, HIGH);
          digitalWrite(dht11.ligado, LOW);
        }
        else
        {
          digitalWrite(dht11.desligado, LOW);
          digitalWrite(dht11.ligado, HIGH);
        }
        previous = millis();
      }
      

      break;
  }
  server.handleClient();
}

void Root()
{
  String pagina = R"rawliteral(
  <!DOCTYPE html>
  <html lang="en">
  <head>
     <meta charset="UTF-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>A interface</title>
     <style>
          html {
             font-family: Times;
             display: inline-block;
             margin: 0px auto;
             text-align: center;
         }

          .button {
             background-color: #4CAF50;
             border: none;
             color: white;
              padding: 16px 40px;
             text-decoration: none;
             font-size: 30px; 
              margin: 2px;
              cursor: pointer;
          }

          .green {
             background-color: green;
          }
             .blue
             {
               background-color: blue;
             }
      </style>

      <script>
        function atualizarTemperatura() 
        {
          fetch('/temp')
            .then(response => response.text())
            .then(temp =>
            {
              document.getElementById("temp").textContent = temp + " °C";
            });
        }

        
      setInterval(atualizarTemperatura, 2000);
      
      </script>
  </head>
  <body>
     <h1>Leitura do Sensor</h1>
  )rawliteral";

  if (dht11.estado_botao == "off") 
  {
    pagina += "<p><a href=\"/button/on\"><button class=\"button green\" id=\"btn\">ON</button></a></p>";
  } else {
    pagina += "<p><a href=\"/button/off\"><button class=\"button blue\" id=\"btn\">OFF</button></a></p>";
  }
  
  pagina += "<p>Estado do Botão: <span id=\"estado_botao\">" + dht11.estado_botao + "</span></p>";
  pagina += "<p><strong>Temperatura:</strong> <span id=\"temp\">" + String(dht11.temperatura) + " °C</span></p>";
  

  


  // Close the page
  pagina += "</body></html>";

  // Send it to the client
  server.send(200, "text/html", pagina);
}