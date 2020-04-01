#include <TridentTD_LineNotify.h>

#define LED 2
#define SENSOR 4
#define DELAY 500
#define SSID        "PostWiFi"
#define PASSWORD    "123456789"
#define LINE_TOKEN  "2GYnKwcYIkHoncb4RZ4t3dWR8Vlh7yqQ4uBN6vgxPIW"

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  Serial.println("Sensor start");
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);              // wait for a second
  
  // read the value from the sensor:
  sensorValue = analogRead(SENSOR);
  Serial.print("Value: "); Serial.println(sensorValue);
  if(sensorValue>600){
    Serial.print("Value: "); Serial.println(sensorValue);
    LINE.notify("Gas Leak แก๊สรั่ว หรือลืมปิดแก๊ส");
  }
  else if(sensorValue>800){
    Serial.print("Value: "); Serial.println(sensorValue);
    LINE.notify("อากาศมีควันหรือแก๊สมากเกินไป");
  }
  else if(sensorValue>1000){
    Serial.print("Value: "); Serial.println(sensorValue);
    LINE.notify("อันตราย อย่าทำให้เกิดประกายไฟ");
  }
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);
}
