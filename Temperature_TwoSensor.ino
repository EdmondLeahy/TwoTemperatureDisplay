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
// Delay value for setup 
setup_delay = 0.3;

void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Sensors.begin();
  Serial.print("WELCOME TO ELLIE JEAN!");
  delay(10*1000); //Print welcome for 10 seconds
  Serial.print("Initializing surfmobile.....");
  delay(setup_delay*1000);
  Serial.print("Calculating geoid.....");
  delay(setup_delay*1000);
  Serial.print("Giving up and using WGS84.....");
  delay(setup_delay*1000);
  Serial.print("Gettin funky.....");
  delay(setup_delay*1000);
}

void loop(void)
{ 
  // Keep previous temp
  t1 = Sensors.getTempCByIndex(0);
  t2 = Sensors.getTempCByIndex(1);
  // Send the command to get temperatures
  Sensors.requestTemperatures(); 
  // Find trend of values 
  // Not Here Yet
  // Print the values to the serial bus
  print_all_data(Sensors.getTempCByIndex(0), Sensors.getTempCByIndex(1), 
  //Update value every 5 sec.
  delay(5*1000);
}

void print_all_data(t1, t2)
{
  Serial.print("Outside Temperature is: ");
  Serial.print(t1);
  Serial.write(176);
  Serial.print(" C");
  Serial.print("   Inside Temperature is: ");
  Serial.print(t2);
  Serial.write(176);
  Serial.println(" C"); 
	
}
// void get_trend(t1, t2, t1p, t2p)
// {
// 	
// 	
// }