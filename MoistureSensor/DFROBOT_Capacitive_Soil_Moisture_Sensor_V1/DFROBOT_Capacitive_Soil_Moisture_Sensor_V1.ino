#define AIR (505)
#define WATER (260)
#define INTERVAL (AIR - WATER)

int soilMoistureValue = 0;
double val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(A0);

  val = (AIR - soilMoistureValue);
  val < 0 ? val *= -1 : val *= 1;
  val /= INTERVAL;

  Serial.print(val*100);
  Serial.println("%");

  delay(100);
}
