// Basic demo for readings from Adafruit SCD30
#include <Wire.h>
#include <Adafruit_SCD30.h>
#include <Adafruit_Sensor.h>

Adafruit_SCD30  scd30;
void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit SCD30 test!");

  // Try to initialize!
  if (!scd30.begin_I2C()) {

    Serial.println("Failed to find SCD30 chip");
    while (1) { delay(10); }
  }
  Serial.println("SCD30 Found!");
  if (!scd30.setMeasurementInterval(10)){
    Serial.println("Failed to set measurement interval");
    while(1){ delay(10);}
  }
  Serial.print("Read Interval: "); Serial.print(scd30.getMeasurementInterval()); Serial.println(" seconds");

}
void loop() {
  if(scd30.dataReady()){
    Serial.println("Data available!");
    scd30.read();

    Serial.print("Temperature: ");Serial.print(scd30.temperature);Serial.println(" degrees C");
    Serial.print("Relative Humidity: ");Serial.print(scd30.relative_humidity);Serial.println(" %");
    Serial.print("eCO2: ");Serial.print(scd30.eCO2, 3);Serial.println(" ppm");
    Serial.println("");
  } else {
    Serial.println("No data");
  }

    delay(1000);
}