#define RED   (11)
#define GREEN (10)
#define BLUE  (9)

void setup() {
  pinMode(RED,  OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  setColor(0xFF, 0x00, 0x00);
  delay(1000);
  setColor(0x00, 0xFF, 0x00);
  delay(1000);
  setColor(0x00, 0x00, 0xFF);
  delay(1000);
  setColor(0xFF, 0xFF, 0xFF);
  delay(1000);
  setColor(0x00, 0x00, 0x00);
  delay(1000);
}

void setColor(int R, int G,  int B) {
  analogWrite(RED, R);
  analogWrite(GREEN, G);
  analogWrite(BLUE, B);
}
