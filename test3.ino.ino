#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Airtel_hoho";
const char* password = "Hoho@7618";
const char* serverName = "http://192.168.1.6:5000/api/rfid"; // Replace with your server URL

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Simulate RFID reading with a dummy user ID
  String userId = "1234ABCD";

  Serial.println("User ID: " + userId);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    String requestBody = "{\"uid\":\"" + userId + "\"}";
    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.println("Error on sending POST: " + String(httpResponseCode));
    }

    http.end();
  }

  delay(2000); // Adjust delay as needed
}
