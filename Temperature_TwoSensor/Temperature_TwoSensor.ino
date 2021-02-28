/* Arduino DS18B20 temp sensor tutorial
   More info: http://www.ardumotive.com/how-to-use-the-ds18b20-temperature-sensor-en.html
   Date: 19/6/2015 // www.ardumotive.com */
/*
                            _.-="_-         _
                         _.-="   _-          | ||"""""""---._______     __..
             ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
      __.--""     __        ,'    ELLIE JEAN     o \           __        [__|
 __-""=======.--""  ""--.=================================.--""  ""--.=======:
]       [w] : /        \ : |========================|    : /        \ :  [w] :
V___________:|          |: |========================|    :|          |:   _-"
 V__________: \        / :_|=======================/_____: \        / :__-"
 -----------'  "-____-"  `-------------------------------'  "-____-"

 */

//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

//Data wire is plugged into pin 8 on the Arduino
#define ONE_WIRE_BUS 8
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature Sensors(&oneWire);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Delay value for setup 
double setup_delay = 0.5*1000;
double t1, t2;
double update_int = 1; // seconds
int i = 0;
// 33
void setup(void)
{
  Serial.begin(9600); //Begin serial communication
  Sensors.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(40, 2);
  lcd.setCursor(8, 0);
  lcd.print("WELCOME TO ELLIE JEAN!");
  delay(1*1000); //Show the welcome screen
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
  lcd.print("....Giving up and using EGM96....");
  delay(setup_delay);
  lcd.setCursor(4, 1);
  lcd.print(".........Gettin funky.........");
  delay(setup_delay);
  lcd.clear();
}

void loop(void)
{ 
  Sensors.requestTemperatures(); 
  
  // Print the values to the LCD
  Sensors.requestTemperatures();
  print_all_data(Sensors.getTempCByIndex(0), Sensors.getTempCByIndex(1));
  //Update delay
  delay(update_int*1000);
  
  i++;
  if (i%300 == 0){
    lcd.clear();
  }
}

/* 


|       Inside:     |       Outside:     |   
|      +29.5 *C     |      -14.2 *C      |

 
 */

void print_all_data(double t1, double t2)
{
  // TOP ROW
  //Inside Temp
  lcd.setCursor(8, 0);
  lcd.print("Inside:");
  //Outside Temp
  lcd.setCursor(26,0);
  lcd.print("Outside:");

  // BOTTOM ROW
  // Internal
  lcd.setCursor(7,1);
  lcd.print("      ");
  lcd.setCursor(7,1);
  if(t1 > 0) {
    lcd.print("+ ");
  }
  // Inside
  lcd.print(t1,1);
  lcd.write((char)223);
  lcd.print(" C       ");


  // External
  lcd.setCursor(25,1);
  lcd.print("      ");
  lcd.setCursor(25,1);
  if(t2 > 0) {
    lcd.print("+ ");
  }
  lcd.print(t2,1);
  lcd.write((char)223);
  lcd.print(" C       ");

  
  // Print the deviders
  lcd.setCursor(0,0);
  lcd.print("|");
  lcd.setCursor(0,1);
  lcd.print("|");
  lcd.setCursor(20,0);
  lcd.print("|");
  lcd.setCursor(20,1);
  lcd.print("|");
  lcd.setCursor(39,0);
  lcd.print("|");
  lcd.setCursor(39,1);
  lcd.print("|");
}
