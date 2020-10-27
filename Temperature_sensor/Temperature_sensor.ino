/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi
 modified 26 OCT 2020
 by Aman Singh
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
 ***this link is deprecated***

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
   mlx.begin();  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("A bit show off");
  lcd.setCursor(0, 1);
  lcd.print("Code Dev. Aman");
  delay(3000);
}

void loop() {
  float error = 7;
  
  float ambient = mlx.readAmbientTempF() + error;
  float object = mlx.readObjectTempF() + error;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Ambient: ");
  lcd.setCursor(9, 0);
  lcd.print(ambient);
  lcd.setCursor(0, 1);
  lcd.print("Object: ");
  lcd.setCursor(9, 1);
  lcd.print(object);

  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC() + error); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC() + error); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF() + error); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF() + error); Serial.println("*F");
  Serial.print(mlx.readObjectTempF());
  delay(500);
}
