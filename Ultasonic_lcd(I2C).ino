#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
const int trigPin = 5;  //D1
const int echoPin = 4;  //D2
//Set the LCD address to 0x27 for 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

long duration;
int distance;

void setup()
{
  Serial.begin(9600);
  Wire.begin(0,2);
    // initialize the LCD
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
}
 
void loop()
{
//that is the sequence for the sensor to start reading 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

  //and here we calculate distance from it
distance= duration*0.034/2;
  //before displaying new value on LCD we have to clear it
lcd.clear();
  //here we display the value on the LCD
lcd.print("Distance: ");
lcd.print(distance);
lcd.print("cm");
  //delay 100 so we have around 10Hz of frequency of readings
delay(1000);
}
