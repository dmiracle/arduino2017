#define RED 5
#define GREEN 6
#define BUTTON 7
#define BOX 5

const int yPin = 12;
const int accelMin = 3700;
const int accelMax = 6200;
int accelMid = (accelMax + accelMin) / 2;;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer as inputs:
  pinMode(yPin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);
  //pinMode(yPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // variables to read the pulse widths:
  int pulseX, pulseY;
  int red, green;
  bool button;
  //int accelMid = (accelMax + accelMin) / 2;

  pulseY = pulseIn(yPin, HIGH);
  if (pulseY > accelMid) {
    green = map(pulseY, accelMid, accelMax, 0, 255);
    red = 0;
  }
  else {
    red = map(pulseY, accelMin, accelMid, -255, 0);
    red = -1 * red;
    green = 0;
  }
  analogWrite(RED, red);
  analogWrite(GREEN, green);


  Serial.print(pulseY);
  Serial.print("\t");
  Serial.print(accelMid);
  Serial.print("\t");
  Serial.print(red);
  Serial.print("\t");
  Serial.print(green);
  Serial.println();

  delay(100);
  button = digitalRead(BUTTON);
  if (button) {
    accelMid = 0;
    for (int i = 0; i < BOX; i++) {
      accelMid +=  pulseIn(yPin, HIGH);
    }
    accelMid = floor(accelMid / BOX);
  }
}
