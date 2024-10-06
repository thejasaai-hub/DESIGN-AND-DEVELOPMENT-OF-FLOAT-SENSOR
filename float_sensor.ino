#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "gasiot-3062f-default-rtdb.firebaseio.com/" //Without http:// or https:// schemes
#define FIREBASE_AUTH "kjnnGmOp5zAEadyK0KFrwa5u4fGo0lXh4QaNmYFO"
#define WIFI_SSID "Enter your Wifi Name"
#define WIFI_PASSWORD "Enter your Password"

FirebaseData firebaseData;
FirebaseData faceidData;

String relay; // Initialize relay variable
int targetFaceID = 0; // Initialize targetFaceID variable

static const int RXPin = 4;  // Connect GPS TX to GPIO4 (D2) on ESP8266
static const int TXPin = 5;  // Connect GPS RX to GPIO5 (D1) on ESP8266
static const uint32_t GPSBaud = 9600;
const int pin = 2; // Input signal connected to Pin 12 of Arduino

float pulseHigh; 
float pulseLow; 
float pulseTotal; 
float frequency; 

// The TinyGPS++ object
TinyGPSPlus gps;

// The software serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
   pinMode(pin, INPUT);
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0) {
    gps.encode(ss.read());
    if (gps.location.isUpdated()) {
      Serial.print("Latitude= ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= ");
      Serial.println(gps.location.lng(), 6);
      
      // Store latitude and longitude in variables
      double latitude = gps.location.lat();
      double longitude = gps.location.lng();
      
      pulseHigh = pulseIn(pin, HIGH);
      pulseLow = pulseIn(pin, LOW);
      pulseTotal = pulseHigh + pulseLow; // Time period of the pulse in microseconds
      frequency = 1000000 / pulseTotal;
      
      // Convert targetFaceID to String before setting it to Firebase
      String faceIDString = String(frequency);

      // Set values to Firebase
      if (Firebase.setString(firebaseData, "/husky/relay", relay)) {
        // Success
      } else {
        // Failed to set relay
        Serial.println("Failed to set relay");
        Serial.println("Reason: " + firebaseData.errorReason());
      }

      if (Firebase.setString(faceidData, "/husky/faceid", faceIDString)) {
        // Success
      } else {
        // Failed to set face ID
        Serial.println("Failed to set face ID");
        Serial.println("Reason: " + firebaseData.errorReason());
      }

      if (Firebase.setString(firebaseData, "/husky/lat", String(latitude))) {
        // Success
      } else {
        // Failed to set latitude
        Serial.println("Failed to set latitude");
        Serial.println("Reason: " + firebaseData.errorReason());
      }

      if (Firebase.setString(faceidData, "/husky/lon", String(longitude))) {
        // Success
      } else {
        // Failed to set longitude
        Serial.println("Failed to set longitude");
        Serial.println("Reason: " + firebaseData.errorReason());
      }
    }
  }
}
