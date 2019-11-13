#include <OneWire.h> 
#include <DallasTemperature.h>

#define TEMP_PIN 23
#define TEMP_RESOLUTION 10

OneWire oneWire(TEMP_PIN); 
DallasTemperature sensors(&oneWire);

void setup(void) 
{
  Serial.begin(9600);
  
  Serial.print("Waiting for temperature sensor detection ...");

  while (sensors.getDeviceCount() == 0) {
    Serial.print(".");
    sensors.begin();
    delay(1000);
  }

  Serial.println();
  Serial.println();
  Serial.print("Temperature sensor count detected: ");
  Serial.println(sensors.getDeviceCount());
    
  DeviceAddress deviceAddress;
  sensors.getAddress(deviceAddress, 0);
  Serial.print("Temperature sensor model: ");
  Serial.println(deviceAddress[0]);

  Serial.print("Setting temperature resolution to: ");
  Serial.println(TEMP_RESOLUTION);
  sensors.setResolution(TEMP_RESOLUTION);
  
  Serial.println();
}

void loop(void) 
{
  Serial.println("Reading temp ... "); 
  sensors.requestTemperatures();

  Serial.print("Temperature is: "); 
  Serial.println(sensors.getTempCByIndex(0), 4);
  Serial.println();
  
  delay(3000);
}
