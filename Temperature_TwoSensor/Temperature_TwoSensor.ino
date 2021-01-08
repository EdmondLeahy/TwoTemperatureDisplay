/* Arduino DS18B20 temp sensor tutorial
   More info: http://www.ardumotive.com/how-to-use-the-ds18b20-temperature-sensor-en.html
   Date: 19/6/2015 // www.ardumotive.com */


//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

//Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 7
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature Sensors(&oneWire);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Delay value for setup 
double setup_delay = 0.5*1000;
double t1, t2;
// 33
void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Sensors.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(40, 2);
  lcd.setCursor(8, 0);
  lcd.print("WELCOME TO ELLIE JEAN!");
  delay(1*1000); //Print welcome for 10 seconds
  lcd.setCursor(4, 1);
  lcd.print(".....Initializing surfmobile.....");
  delay(setup_delay);
  lcd.setCursor(4, 1);
  lcd.print("..........Raising Sails..........");
  delay(setup_delay);
  lcd.setCursor(4, 1);
  lcd.print("........Calculating geoid........");
  delay(setup_delay);
  lcd.setCursor(4, 1);
  lcd.print("....Giving up and using WGS84....");
  delay(ssetup_delay);
  lcd.setCursor(4, 1);
  lcd.print(".........Gettin funky.........");
  delay(setup_delay);
  lcd.clear();
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
  lcd.setCursor(0, 0);
  lcd.print("Outside Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Inside Temp: ");
  print_all_data(Sensors.getTempCByIndex(0), Sensors.getTempCByIndex(1));
  //Print trend
  print_trend(t1, t2, Sensors.getTempCByIndex(0), Sensors.getTempCByIndex(1));
  //Update value every 5 sec.
  delay(0.5*1000);
}

int print_all_data(double t1, double t2)
{
//  //Outside Temp
//  lcd.setCursor(0, 0);
//  lcd.print("Outside Temperature is: ");
  lcd.setCursor(15, 0);
  lcd.print(t1);
  lcd.write((char)223);
  lcd.print(" C");
  lcd.setCursor(15, 1);
  //lcd.print("Inside Temperature is: ");
  lcd.print(t2);
  lcd.write(223);
  lcd.print(" C");
	return 1;
}

int print_trend(double t1, double t2, double t1p, double t2p)
{
  lcd.setCursor(27, 0);
  lcd.print(get_trend(t1, t1p));
  lcd.setCursor(27, 1);
  lcd.print(get_trend(t2, t2p));  
}

String get_trend(double t1, double t1p)
{
  String result;
 	if(t1>t1p)
   {
    result = "and falling ";
   }
  else if(t1<t1p)
  {
   result = "and rising  ";
  }
  else
  {
   result = "and constant";
  }
 	return result;
}
