/* Arduino DS18B20 temp sensor tutorial
   More info: http://www.ardumotive.com/how-to-use-the-ds18b20-temperature-sensor-en.html
   Date: 19/6/2015 // www.ardumotive.com */


//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

//Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature Sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Sensors.begin();
}

void loop(void)
{ 
  // Send the command to get temperatures
  Sensors.requestTemperatures(); 
  // Print the values to the serial bus
  Serial.print("Outside Temperature is: ");
  Serial.print(Sensors.getTempCByIndex(0));
  Serial.write(176);
  Serial.print(" C");
  Serial.print("   Inside Temperature is: ");
  Serial.print(Sensors.getTempCByIndex(1));
  Serial.write(176);
  Serial.println(" C"); 
  //Update value every 5 sec.
  delay(5*1000);
}
