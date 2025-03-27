# esp32-webserver

This ESP32 web server serves HTML/text files stored on an SD card over WiFi. You can access these files from any device on the network or remotely via port forwarding.  

#### **🛠 Features**  
Serves files (e.g., `index.html`) from an SD card  
Uses **ESPAsyncWebServer** for handling HTTP requests  
Supports dynamic file serving for `.html`, `.txt`, etc.  

---

### **Setup & Run**  

#### **1. Clone the Repo & Install Dependencies**  
```bash
git clone <repo-link>
cd esp32-webserver
```

#### **2. Install Required Libraries**  
For **Arduino IDE**, install:  
- `ESPAsyncWebServer`
- `AsyncTCP`
- `SD`
- `SPI`

For **PlatformIO (VS Code)**, add to `platformio.ini`:  
```ini
lib_deps =
    me-no-dev/ESP Async WebServer
    me-no-dev/AsyncTCP
```

#### **3. Wire the SD Card Module (SPI Mode)**  
| **SD Card Module** | **ESP32** |
|--------------------|----------|
| VCC | **3.3V** |
| GND | **GND** |
| CS | **GPIO 5** |
| MOSI | **GPIO 23** |
| MISO | **GPIO 19** |
| SCK | **GPIO 18** |

#### **4. Prepare SD Card**  
1. Format as **FAT32**.  
2. Add an `index.html` file:  
   ```html
   <h1>Hello from ESP32!</h1>
   ```
3. Insert SD card into module.  

#### **5. Upload & Run**  
For **Arduino IDE**:  
1. Select **ESP32 Dev Module** in **Tools → Board**.  
2. Set **115200 baud rate** in Serial Monitor.  
3. Click **Upload**.  

For **PlatformIO**:  
```bash
pio run --target upload
pio device monitor
```

#### **6. Access Web Server**  
Find the ESP32 IP in the **Serial Monitor** and open:  
```
http://<ESP32_IP>
```

To access **remotely**, set up **port forwarding** on your router.  

---
