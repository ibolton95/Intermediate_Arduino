//LED Blink Revisited.ino

int led = 11;
int brightness = 0;
int fadeAmount = 5;

void setup() {
	Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, brightness); 
  for (int i = 0; i <= brightness/10; i++) {
  	Serial.print("x");
  	} 
  	Serial.println ();
   // turn the LED on (HIGH is the voltage level)
    brightness = brightness + fadeAmount;          // wait for a second
    if (brightness <= 0 || brightness >= 255) {
    	fadeAmount = -fadeAmount;   // turn the LED off by making the voltage LOW
    }
    delay(30);               // wait for a second
}
