# ESP32 Free API Caller Template 🌐

Call any free public API from an ESP32 — no API key needed.  
Built and tested by Augustine Caleb.

---

## How to Use

1. Open `ESP32_Free_API.ino` in Arduino IDE
2. Change these 3 lines at the top:
```cpp
const char* WIFI_SSID     = "Your_WiFi_Name";
const char* WIFI_PASSWORD = "Your_WiFi_Password";
const char* API_URL       = "paste your chosen API URL here";
```
3. Scroll to `parseResponse()` and uncomment the block that matches your API
4. Upload → Open Serial Monitor at **115200 baud** → Press RST

---

## Free APIs Included

| # | API | What It Returns | URL to paste |
|---|-----|----------------|--------------|
| 1 | **JokeAPI** | Random jokes | `https://v2.jokeapi.dev/joke/Any?type=single` |
| 2 | **Dog Fact API** | Random dog facts | `https://dog-api.kinduff.com/api/facts?number=1` |
| 3 | **Cat Fact API** | Random cat facts | `https://catfact.ninja/fact` |
| 4 | **Random User API** | Fake user profiles | `https://randomuser.me/api/` |
| 5 | **Bored API** | Random activity ideas | `https://www.boredapi.com/api/activity` |
| 6 | **Number Trivia** | Fun facts about numbers | `http://numbersapi.com/random/trivia?json` |
| 7 | **ISS Location** | Real-time space station GPS | `http://api.open-notify.org/iss-now.json` |

---

## Switching APIs (3 steps)

**Step 1** — Paste the new URL in the config:
```cpp
const char* API_URL = "https://catfact.ninja/fact";
```

**Step 2** — In `parseResponse()`, comment out the current block:
```cpp
// const char* joke = doc["joke"];   ← add // in front
// Serial.println(joke);
```

**Step 3** — Uncomment the new block:
```cpp
const char* fact = doc["fact"];      ← remove the //
Serial.println("CAT FACT: " + String(fact));
```

---

## Serial Monitor Output Example

```
=============================
  ESP32 Free API Template
=============================

[WiFi] Connecting to: MyNetwork
..........
[WiFi] Connected!
[WiFi] IP Address: 192.168.1.105

[API] Fetching data...
[API] Status Code: 200
-----------------------------
JOKE: Why do Java developers wear glasses? Because they don't C#.
-----------------------------
```

---

## Dependencies

Install from **Sketch → Include Library → Manage Libraries**:
- **ArduinoJson** by Benoit Blanchon

---

## Board Setup (First Time)

1. **File → Preferences** → Add to Boards Manager URL:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
2. **Tools → Board → Boards Manager** → Search `esp32` → Install **esp32 by Espressif Systems**
3. **Tools → Board → ESP32 Dev Module**
4. **Tools → Port** → Select your COM port

---

## License
MIT — free to use and modify.
