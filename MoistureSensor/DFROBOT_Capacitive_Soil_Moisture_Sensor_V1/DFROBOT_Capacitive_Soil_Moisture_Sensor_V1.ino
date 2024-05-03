void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  val = analogRead(0);  //connect sensor to Analog 0
  Serial.println(val);  //print the value to serial port
  delay(100);
}
