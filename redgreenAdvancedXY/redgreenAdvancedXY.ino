#define RED 5
#define GREEN 6
#define BUTTON 7
#define BOX 20

int joystickY;
int joystickX;
bool button;
int js_restX = 0;
int js_restY = 0;
int red, green;
short loopdex = 0;
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);

  ////////// SET X RESTING POSITION
  for (i = 0; i < BOX; i++) {
    js_restX += analogRead(A0);
    js_restY += analogRead(A1);
  }
  js_restX = floor(js_restX / BOX);
  js_restY = floor(js_restX / BOX);
}

void loop() {
  joystickX = analogRead(A0);
  joystickY = analogRead(A1);

  //// SET REST POSITION WITH BUTTON
  button = digitalRead(BUTTON);
  if (button) {
    js_restX = 0;
    js_restY = 0;
    for (i = 0; i < BOX; i++) {
      js_restX += analogRead(A0);
      js_restY += analogRead(A1);
    }
    js_restX = floor(js_restX / BOX);
    js_restY = floor(js_restX / BOX);
  }

  green = map(joystickX, 0, 1024, 0, 255);
  red = map(joystickY, 0, 1024, 0, 255);

  analogWrite(RED, red);
  analogWrite(GREEN, green);

  /// REPORT TO SERIAL TERMINAL EVERY 1000 ITERATIONS
  if (loopdex % 1000 == 0)
  {
    Serial.print(loopdex);
    Serial.print("\t");
    Serial.print(joystickX);
    Serial.print("\t");
    Serial.println(joystickY);
  }
  loopdex++;
}


