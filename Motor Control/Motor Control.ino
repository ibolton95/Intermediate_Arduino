int potPin = A0;
int motor = 6;
int digitalValue;

void setup () {
  pinMode(motor,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop () {
  int sensorValue;
  sensorValue = analogRead(potPin);
  Serial.println(sensorValue);
  digitalValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.println(digitalValue);
  analogWrite(motor,digitalValue);

}