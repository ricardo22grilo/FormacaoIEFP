#include <Arduino.h>

/*  
  Rui Santos & Sara Santos - Random Nerd Tutorials
  https://RandomNerdTutorials.com/esp32-web-server-beginners-guide/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Vodafone-DC6F76";
const char* password = "AxjJZdf5Pn";

// Assign output variables to GPIO pins
const int output2 = 2;

String output2State = "off";


// Create a web server object
WebServer server(80);


// Function to handle the root URL and show the current states
void handleRoot()
 {
  String html = R"rawliteral(<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel=\"icon\" href=\"data:,\">
  <style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
  .button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}
  .button2 { background-color: #555555; }</style></head>
  <body><h1>Ricardo's ESP32 Web Server</h1>)rawliteral";

  // Display GPIO 2 controls
  html += "<p>GPIO 2 - State " + output2State + "</p>";
  if (output2State == "off") {
    html += "<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>";
  } else {
    html += "<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>";
  }

  

  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Function to handle turning GPIO 26 on
void handleGPIO2On() 
{
  output2State = "on";
  digitalWrite(output2, HIGH);
  handleRoot();
}

// Function to handle turning GPIO 26 off
void handleGPIO2Off() 
{
  output2State = "off";
  digitalWrite(output2, LOW);
  handleRoot();
}


void setup() 
{
  Serial.begin(115200);

  // Initialize the output variables as outputs
  pinMode(output2, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output2, LOW);

  // Connect to Wi-Fi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set up the web server to handle different routes
  server.on("/", handleRoot);
  server.on("/2/on", handleGPIO2On);
  server.on("/2/off", handleGPIO2Off);

  // Start the web server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() 
{
  // Handle incoming client requests
  server.handleClient();
}