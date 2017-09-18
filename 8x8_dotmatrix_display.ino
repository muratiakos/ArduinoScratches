
#define pinTrigger 13
#define pinEcho 12
// 42BC1E36
// 8DF5A7GH
// Row PIN wiring
const char row[8] = {
  // 1,  2,  3, 4,  5,  6, 7, 8
     18, 15, 5, 14, 9,  4, 11, 6
};

// Column pin wiring
const char col[8] = {
  // A, B, C,  D,  E,  F,  G, H
     10,16, 17, 7,  19, 8, 12, 13
     
};

char _ = 0;
char o = 1;

// 2-dimensional array of pixels:
char heart[8][8] = {
  {_,_,_,_,_,_,_,_}, 
  {_,o,o,_,_,o,o,_}, 
  {o,_,_,o,o,_,_,o}, 
  {o,_,_,_,_,_,_,o}, 
  {o,_,_,_,_,_,_,o}, 
  {_,o,_,_,_,_,o,_}, 
  {_,_,o,_,_,o,_,_}, 
  {_,_,_,o,o,_,_,_}
};

char full_heart[8][8] = {
  {_,_,_,_,_,_,_,_}, 
  {_,o,o,_,_,o,o,_}, 
  {o,o,o,o,o,o,o,o}, 
  {o,o,o,o,o,o,o,o}, 
  {o,o,o,o,o,o,o,o}, 
  {_,o,o,o,o,o,o,_}, 
  {_,_,o,o,o,o,_,_}, 
  {_,_,_,o,o,_,_,_}
};


void setup() {
  Serial.begin (9600);
  
  // Initialize HC-SRO4
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (char thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    
    //ALL OFF
    digitalWrite(col[thisPin], LOW);
    digitalWrite(row[thisPin], HIGH);
  }
}

void loop() {
  // read input:
  //readSensors();

  // draw the screen:
  refreshScreen();
}

void readSensors() {
  // turn off the last position:
  //pixels[x][y] = HIGH;
  // read the sensors for X and Y values:
  //x = 7 - map(analogRead(A0), 0, 1023, 0, 7);
  //y = map(analogRead(A1), 0, 1023, 0, 7);
  // set the new pixel position low so that the LED will turn on
  // in the next screen refresh:
  //pixels[x][y] = LOW;

}

void refreshScreen() {
  show_screen(full_heart);
}

void show_screen(char screen[8][8]) {
   for (char thisRow = 0; thisRow < 8; thisRow++) {
    for (char thisCol = 0; thisCol < 8; thisCol++) {
      
      if (screen[thisRow][thisCol] == 1)
        pixel_on(thisRow, thisCol);
      pixel_off(thisRow, thisCol);
    }
  }
}

void pixel_off(char x, char y) {
  digitalWrite(row[x], HIGH);
  digitalWrite(col[y], LOW);
}
void pixel_on(char x, char y) {
  digitalWrite(row[x], LOW);
  digitalWrite(col[y], HIGH);
}

#define led 11
#define led2 10

/*
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
*/
