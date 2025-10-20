#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Wi-Fi credentials
const char* ssid = "";
const char* password = "";

// Slider struct for PWM
struct Slider {
  int pin;
  String value;
  int pchannel;
  int brightness;
};

Slider slider1 ={
  .pin = 17,
  .value = "0",
  .pchannel = 0,
  .brightness = 0
};

Slider slider2 ={
  .pin = 4,
  .value = "0",
  .pchannel = 1,
  .brightness = 0
};

Slider slider3 ={
  .pin = 16,
  .value = "0",
  .pchannel = 2,
  .brightness = 0
};

int freq = 5000;
int resolution = 8;

AsyncWebServer server(80);

// HTML + JS interface
const char* html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>RGB LED Control</title>
  <style>
    body { font-family: Arial; padding: 20px; }
    .slider { width: 300px; }
    label { font-weight: bold; }
  </style>
</head>
<body>
  <h2>RGB Light Control</h2>

  <label>Red</label><br>
  <p>Value: <span id="val1">%SLIDERVALUE1%</span></p>
  <input type="range" oninput="setBrightness(this)" id="slider1" min="0" max="255" value="%SLIDERVALUE1%" step="1" class="slider"><br><br>

  <label>Green</label><br>
  <p>Value: <span id="val2">%SLIDERVALUE2%</span></p>
  <input type="range" oninput="setBrightness(this)" id="slider2" min="0" max="255" value="%SLIDERVALUE2%" step="1" class="slider"><br><br>

  <label>Blue</label><br>
  <p>Value: <span id="val3">%SLIDERVALUE3%</span></p>
  <input type="range" oninput="setBrightness(this)" id="slider3" min="0" max="255" value="%SLIDERVALUE3%" step="1" class="slider"><br><br>

  <script>
    function setBrightness(element) {
      var id = element.id;
      var value = element.value;

      document.getElementById("val1").innerText = document.getElementById("slider1").value;
      document.getElementById("val2").innerText = document.getElementById("slider2").value;
      document.getElementById("val3").innerText = document.getElementById("slider3").value;

      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/" + id + "?value=" + value, true);
      xhr.send();
    }
  </script>
</body>
</html>
)rawliteral";

// Replace placeholders in HTML
String processor(const String& var) {
  if (var == "SLIDERVALUE1") return String(slider1.brightness);
  if (var == "SLIDERVALUE2") return String(slider2.brightness);
  if (var == "SLIDERVALUE3") return String(slider3.brightness);
  return String();
}

void setup() {
  Serial.begin(115200);

  // Setup PWM channels
  ledcSetup(slider1.pchannel, freq, resolution);
  ledcAttachPin(slider1.pin, slider1.pchannel);
  ledcSetup(slider2.pchannel, freq, resolution);
  ledcAttachPin(slider2.pin, slider2.pchannel);
  ledcSetup(slider3.pchannel, freq, resolution);
  ledcAttachPin(slider3.pin, slider3.pchannel);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  // Serve web interface
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", html, processor);
  });

  // Individual slider routes
  server.on("/slider1", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
      slider1.value = request->getParam("value")->value();
      slider1.brightness = slider1.value.toInt();
      ledcWrite(slider1.pchannel, slider1.brightness);
      request->send(200, "text/plain", "Red set to " + slider1.value);
    }
  });

  server.on("/slider2", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
      slider2.value = request->getParam("value")->value();
      slider2.brightness = slider2.value.toInt();
      ledcWrite(slider2.pchannel, slider2.brightness);
      request->send(200, "text/plain", "Green set to " + slider2.value);
    }
  });

  server.on("/slider3", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
      slider3.value = request->getParam("value")->value();
      slider3.brightness = slider3.value.toInt();
      ledcWrite(slider3.pchannel, slider3.brightness);
      request->send(200, "text/plain", "Blue set to " + slider3.value);
    }
  });

  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Not Found");
  });

  server.begin();
}

void loop() {
  // Nothing needed here for async server
}
