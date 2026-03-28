/**
 * ============================================================
 *  ESP32 Free API Caller Template
 *  Author  : Augustine
 *  Version : 1.0.0
 *  Board   : ESP32 Dev Module / Arduino Nano ESP32
 * ============================================================
 *
 *  Call any FREE public API (no API key needed) from ESP32.
 *  Just swap the URL and update parseResponse() to match
 *  the JSON fields of your chosen API.
 *
 *  DEPENDENCIES (install from Library Manager):
 *    - ArduinoJson by Benoit Blanchon
 *
 * ============================================================
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// ------------------------------------------------------------
//  CONFIG — Only 3 things to change
// ------------------------------------------------------------

const char* WIFI_SSID     = "Your_WiFi_Name";     // Your WiFi name
const char* WIFI_PASSWORD = "Your_WiFi_Password"; // Your WiFi password

// Paste any free API URL here — see README for options
const char* API_URL = "https://v2.jokeapi.dev/joke/Any?type=single";

// How often to fetch in milliseconds (15000 = 15 seconds)
const int FETCH_INTERVAL = 15000;

// ------------------------------------------------------------
//  SETUP
// ------------------------------------------------------------

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n=============================");
  Serial.println("  ESP32 Free API Template");
  Serial.println("=============================\n");

  connectToWiFi();
  callAPI(); // Call once immediately on startup
}

// ------------------------------------------------------------
//  LOOP
// ------------------------------------------------------------

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    callAPI();
  } else {
    Serial.println("[!] WiFi lost. Reconnecting...");
    connectToWiFi();
  }

  delay(FETCH_INTERVAL);
}

// ------------------------------------------------------------
//  Connect to WiFi
// ------------------------------------------------------------

void connectToWiFi() {
  Serial.print("[WiFi] Connecting to: ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {
      Serial.println("\n[!] Could not connect. Check your WiFi name and password.");
      return;
    }
  }

  Serial.println("\n[WiFi] Connected!");
  Serial.print("[WiFi] IP Address: ");
  Serial.println(WiFi.localIP());
}

// ------------------------------------------------------------
//  Call the API (GET request)
// ------------------------------------------------------------

void callAPI() {
  Serial.println("\n[API] Fetching data...");

  WiFiClientSecure client;
  client.setInsecure(); // Fine for free/hobby APIs

  HTTPClient http;
  http.begin(client, API_URL);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.GET();
  Serial.print("[API] Status Code: ");
  Serial.println(httpCode);

  if (httpCode == 200) {
    String rawResponse = http.getString();
    parseResponse(rawResponse);
  } else {
    Serial.println("[API] Request failed.");
  }

  http.end();
}

// ------------------------------------------------------------
//  Parse the JSON response
//  👇 THIS IS THE ONLY SECTION YOU CHANGE PER API
// ------------------------------------------------------------

void parseResponse(String rawJson) {
  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, rawJson);

  if (error) {
    Serial.print("[JSON] Parse error: ");
    Serial.println(error.c_str());
    return;
  }

  // ============================================================
  //  SWAP COMMENT BLOCKS BELOW TO MATCH YOUR CHOSEN API
  // ============================================================

  // ------------------------------------------------------------
  //  1. JOKE API (current default)
  //     URL: https://v2.jokeapi.dev/joke/Any?type=single
  // ------------------------------------------------------------
  const char* joke = doc["joke"];
  Serial.println("-----------------------------");
  Serial.print("JOKE: ");
  Serial.println(joke);
  Serial.println("-----------------------------");


  // ------------------------------------------------------------
  //  2. DOG FACT API
  //     URL: https://dog-api.kinduff.com/api/facts?number=1
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* fact = doc["facts"][0];
  // Serial.println("DOG FACT: " + String(fact));


  // ------------------------------------------------------------
  //  3. CAT FACT API
  //     URL: https://catfact.ninja/fact
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* fact = doc["fact"];
  // Serial.println("CAT FACT: " + String(fact));


  // ------------------------------------------------------------
  //  4. RANDOM USER API (generates fake user profiles)
  //     URL: https://randomuser.me/api/
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* firstName = doc["results"][0]["name"]["first"];
  // const char* lastName  = doc["results"][0]["name"]["last"];
  // const char* country   = doc["results"][0]["location"]["country"];
  // Serial.println("Name: " + String(firstName) + " " + String(lastName));
  // Serial.println("Country: " + String(country));


  // ------------------------------------------------------------
  //  5. BORED API (suggests random activities)
  //     URL: https://www.boredapi.com/api/activity
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* activity = doc["activity"];
  // const char* type     = doc["type"];
  // Serial.println("Activity: " + String(activity));
  // Serial.println("Type: " + String(type));


  // ------------------------------------------------------------
  //  6. NUMBER TRIVIA API
  //     URL: http://numbersapi.com/random/trivia?json
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* text   = doc["text"];
  // int         number = doc["number"];
  // Serial.println("Number: " + String(number));
  // Serial.println("Fact: " + String(text));


  // ------------------------------------------------------------
  //  7. ISS LOCATION API (real-time space station position)
  //     URL: http://api.open-notify.org/iss-now.json
  //     Uncomment below and comment out section 1 above
  // ------------------------------------------------------------
  // const char* lat = doc["iss_position"]["latitude"];
  // const char* lon = doc["iss_position"]["longitude"];
  // Serial.println("ISS Latitude:  " + String(lat));
  // Serial.println("ISS Longitude: " + String(lon));
}
