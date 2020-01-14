#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.  
// If 0x27 doesn't work, try 0x3F.

int potPin = A0;       // Analog pin 0 for the LED brightness potentiometer
int ledPin = 6;        // LED Digital Pin with PWM
int potValue = 0;      // variable to store the value coming from the potentiometer
int brightness = 0;    // converts the potValue into a brightness 
int pBari = 0;         // progress bar
             // foor loop

//progress bar character for brightness



void setup() {
	Serial.begin(9600);
  // setup our led as an OUTPUT
  pinMode(ledPin, OUTPUT); 
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  lcd.init();
  
  lcd.backlight();
  // Print a message to the LCD
  lcd.print(" LED Brightness");
  //Create the progress bar character
  lcd.createChar(0, pBari);
}

void loop() {
  // clears the LCD screen
  lcd.clear();

  lcd.setCursor(0,0);
  // Print a message to the LCD
  lcd.print("LED Brightness");
  //set the cursor to line number 2
  lcd.setCursor(0,1);
  // read the value from the potentiometer
  potValue = analogRead(potPin);    
  
  Serial.println(potValue);
  // turns the potValue into a brightness for the LED
  brightness=map(potValue, 0, 1024, 0, 255); 
  //lights up the LED according to the bightness
  analogWrite(ledPin, brightness); 
  // turns the brighness into a percentage for the bar 
  pBari=map(brightness, 0, 255, 0, 10);
  //prints the progress bar
  
  {
    lcd.setCursor(0, 1);   
    lcd.print(pBari);  
  }
  // delays 750 ms
  delay(750);        
}
