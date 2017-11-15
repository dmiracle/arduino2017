#define RED 5
#define GREEN 6

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int joystick;
  int red, green;
  joystick = analogRead(A0);
  if (joystick > 512) {
    green = map(joystick, 512, 1024, 0, 255);
    red = 0;
  }
  else {
    red = map(joystick, 0, 512, -255, 0);
    red = -1 * red;
    green = 0;
  }
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  Serial.println(joystick);
}
