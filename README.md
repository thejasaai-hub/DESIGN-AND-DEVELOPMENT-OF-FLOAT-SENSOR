# Float Sensor IoT Project

## Overview
This project is focused on the **design and development of a float sensor** for real-time detection of objects in waterways or liquid immersion levels. The system enhances safety and security within waterways and ecosystems by leveraging IoT technologies for **real-time data acquisition**, **storage on Firebase**, and **visualization through a mobile application**.

### Key Features:
- **Real-Time Detection**: Detects objects or floatable materials within waterways.
- **IoT Integration**: Transmits data using an ESP32 and stores it on Firebase for easy monitoring and analysis.
- **GPS Tracking**: Uses GPS to record and transmit the location of the sensor.
- **Mobile App Integration**: A user-friendly interface to monitor the float sensor’s readings in real-time.

## Components Used:
1. **ESP32**: The microcontroller used to handle sensor data and transmit it over Wi-Fi.
2. **Capacitance Float Sensor**: Detects the presence or absence of floatable objects in water by measuring immersion levels.
3. **Signal Conditioning Circuit**: Conditions the output from the sensor to make it readable by the ESP32.
4. **GPS Module (GY-GPSV3-NEO)**: Provides location data of the sensor in real time.
5. **PCB Design**: The hardware design for compact and durable deployment of the sensor.
6. **Arduino IDE**: Used to program the ESP32 and handle sensor readings.
7. **Firebase**: Stores sensor data, GPS location, and relay information in a Realtime Database.
8. **Mobile Application**: Displays the data from Firebase, allowing remote monitoring and control.

## Hardware Setup:
1. **Capacitance Float Sensor**: Connect the output to the signal conditioning circuit.
2. **Signal Conditioning Circuit**: The output is fed to the ESP32 for processing.
3. **GPS Module**: Connect the GPS module to the ESP32 (RX/TX pins) for capturing location data.
4. **ESP32**: Connect to a Wi-Fi network and transmit the data to Firebase.
5. **PCB**: Assemble the components on the PCB for a robust setup.

## Software Setup:
### Arduino IDE:
1. **Install Libraries**:
   - Install the **TinyGPS++** library for GPS integration.
   - Install the **FirebaseESP32** library for Firebase connectivity.
2. **Upload Code**:
   - Open the `float_sensor.ino` file in Arduino IDE.
   - Replace the Wi-Fi credentials and Firebase authentication details in the code:
     ```cpp
     #define WIFI_SSID "Your_WiFi_SSID"
     #define WIFI_PASSWORD "Your_WiFi_Password"
     #define FIREBASE_HOST "Your_Firebase_Host"
     #define FIREBASE_AUTH "Your_Firebase_Auth_Key"
     ```
   - Connect the ESP32 to your computer and upload the code to the board.

### Firebase Setup:
1. **Create Firebase Realtime Database**:
   - Go to [Firebase](https://console.firebase.google.com/) and create a new project.
   - Set up a Realtime Database and obtain the **FIREBASE_HOST** and **FIREBASE_AUTH** credentials.
2. **Add Firebase Credentials**:
   - Insert the Firebase credentials into the code where indicated.
   
### Mobile Application:
The data from the float sensor, including GPS coordinates and sensor readings, is sent to Firebase, where it can be retrieved and displayed on a mobile application. The app will provide real-time data visualization for users monitoring the float sensor system.

## Data Flow:
- **Capacitance Sensor**: Measures immersion levels and sends data to the ESP32.
- **ESP32**: Processes the sensor data, captures GPS coordinates, and transmits the information to Firebase.
- **Firebase**: Stores sensor readings, GPS data, and relay status.
- **Mobile App**: Retrieves and visualizes the data, providing users with real-time tracking of the sensor.

## Data Stored in Firebase:
The system stores the following data in Firebase:
- **/husky/relay**: The status of the relay, if applicable (e.g., "ON" or "OFF").
- **/husky/faceid**: Frequency value calculated from the float sensor, representing immersion level.
- **/husky/lat**: The latitude of the sensor's location.
- **/husky/lon**: The longitude of the sensor's location.

## Future Improvements:
- **Solar Power Integration**: Adding solar power for continuous monitoring in remote locations.
- **AI and Machine Learning**: Analyzing data trends to predict object movement or environmental changes.
- **Mobile Notifications**: Implement push notifications to alert users when certain thresholds are reached (e.g., water levels).

## License:
This project is licensed under the [MIT License](LICENSE).

## Contact:
For any questions or collaboration opportunities, please reach out at [thejastheju5453@gmail.com].

