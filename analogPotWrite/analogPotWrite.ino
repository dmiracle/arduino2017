void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int joystick = analogRead(A0);
  int pos = map(joystick, 0, 1024, 0, 255);
  analogWrite(9, pos);
  Serial.print(joystick);
  Serial.print("\t");
  Serial.println(pos);
}
