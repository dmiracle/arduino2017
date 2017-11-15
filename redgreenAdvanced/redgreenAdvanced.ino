#define RED 5
#define GREEN 6
#define BUTTON 7
#define BOX 20

int joystick;
bool button;
int js_rest = 0;
int red, green;
short loopdex = 0;
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
  for (i = 0; i < BOX; i++) {
    js_rest += analogRead(A0);
  }
  js_rest = floor(js_rest / BOX);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystick = analogRead(A0);
  button = digitalRead(BUTTON);
  if (button) {
    js_rest = 0;
    for (i = 0; i < BOX; i++) {
      js_rest += analogRead(A0);
    }
    js_rest = floor(js_rest / BOX);
  }
  if (joystick > js_rest) {
    green = map(joystick, js_rest, 1024, 0, 255);
    red = 0;
  }
  else {
    red = map(joystick, 0, js_rest, -255, 0);
    red = -1 * red;
    green = 0;
  }
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  if (loopdex % 1000 == 0)
  {
    Serial.print(loopdex);
    Serial.print("\t");    
    Serial.print(js_rest);
    Serial.print("\t");
    Serial.println(joystick);
  }
  loopdex++;
}


