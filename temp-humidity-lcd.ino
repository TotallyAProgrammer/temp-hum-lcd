/*
 This program is based off of a Liquid Crystal Example. But instead of using that, I
 re-did some of the code to work better, and to output data from a DHT11.

    PINOUT
  LCD:
RS: 4
Enable : 2
d0 6
d1 7
d2 8
d3 9
d4 10
d5 11
d6 12
d7 13

  DHT11:
out 5
 */
// include the library code:
#include <dht.h>
#include <LiquidCrystal.h>

#define DHT11_PIN 5

dht DHT;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 4, en = 2, d0 = 6, d1 = 7, d2 = 8, d3 = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); //Only change this if you know what your are doing.
}

void loop() {
        // Humidiy And Temperture DHT11
        int chk = DHT.read11(DHT11_PIN);
        delay(2000); //DO NOT LOWER THIS DELAY! If it is changed to a lower value, the DHT11 will NOT work right.

        lcd.clear();
        String converted;
        converted = DHT.temperature * 1.8 + 32; //Comment this line out for celsius
        // This section is for the preparing of text so it can be put onto the lcd
        String sone = "Temp: ";
        String stwo = sone + converted;
        String sthree = "Humidity: ";
        String spercent = "%";
        String sfour = sthree + DHT.humidity + spercent;
        //Print the previous values to the LCD
        lcd.print(stwo);
        lcd.print((char)223); //Print the temp symbol 
        lcd.print(" F"); //Comment this line out and uncomment the next lin for celsius label
//        lcd.print(" C");
        lcd.setCursor(0,1);
        lcd.print(sfour);
}
