#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

// WiFi Credentials
const char* ssid = "Mvk";
const char* password = "123456789";

// Server URL
const char* serverName = "http://192.168.169.27:5000/api/rfid"; 

// Define SoftwareSerial for RFID Reader (D4 as RX)
SoftwareSerial RFID(D4, D3);  // RX = D4, TX not connected

WiFiClient client;
String lastUID = "";  // Store last UID to prevent duplicates

void setup() {
  Serial.begin(115200);  // Debugging
  RFID.begin(9600);      // EM-18 RFID operates at 9600 baud rate

  // Connecting to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  String uid = readRFID();  // Read UID from RFID Reader

  if (uid.length() > 0 && uid != lastUID) {  // Only send new UID
    Serial.println("Scanned UID: " + uid);
    lastUID = uid;

    if (WiFi.status() == WL_CONNECTED) {
      sendRFIDData(uid);
    }
  }

  delay(1000);  // Avoid continuous requests
}

// Function to read RFID data
String readRFID() {
  String uid = "";

  while (RFID.available()) {  // Read data from EM-18
    char c = RFID.read();
    if (c != '\n' && c != '\r') {  // Ignore newline characters
      uid += c;
    }
  }

  if (uid.length() == 12) {  // EM-18 UID is usually 12 characters
    return uid;
  }

  return "";  // Return empty if invalid
}

// Function to send RFID data to server
void sendRFIDData(String uid) {
  HTTPClient http;
  http.begin(client, serverName);
  http.addHeader("Content-Type", "application/json");

  String requestBody = "{\"uid\":\"" + uid + "\"}";
  int httpResponseCode = http.POST(requestBody);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response: " + response);
  } else {
    Serial.println("Error on sending POST: " + String(httpResponseCode));
  }

  http.end();
}
