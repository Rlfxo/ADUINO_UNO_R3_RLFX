#define RED_PIN   (11)
#define GREEN_PIN (10)
#define BLUE_PIN  (9)
#define ANALOG_IN (A0)

#define AIR (505)
#define WATER (260)
#define INTERVAL (AIR - WATER)

int soil_value = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED_PIN,  OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  soil_value = checkSoil();
  if(soil_value == -1 || soil_value > 100){
    setColor(0xFF,0x00,0x00);
  }else if(soil_value < 25){
    setColor(0x00,0x00,0xFF);
  }else {
    setColor(0x00,0xFF,0x00);
  }
  delay(100);
}

int checkSoil(void) {
  double val = 0;
  int soilMoistureValue = analogRead(ANALOG_IN);

  val = (AIR - soilMoistureValue);
  if(val < 0) return -1;
  
  val /= INTERVAL;
  val *= 100;

  Serial.print(val);
  Serial.println("%");
  return val;
}

void setColor(int R, int G,  int B) {
  analogWrite(RED_PIN, R);
  analogWrite(GREEN_PIN, G);
  analogWrite(BLUE_PIN, B);
}
