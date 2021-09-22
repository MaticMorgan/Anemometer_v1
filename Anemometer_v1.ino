const int windPin = A0;

int windMax = 0;
int windTemp = 0;
int wind;

// this function returns the highest analog reading from the pin in the last 5 seconds
int wind_speed() {
  windMax = 0;
  for ( int i = 0; i < 50; i++ ) {
    windTemp = analogRead(windPin);
    if ( windTemp > windMax ) {
      windMax = windTemp;
    }
    delay(100);
  }

  return windMax;

}


void setup() {

  pinMode(windPin, INPUT);
  Serial.begin(9600);

}


void loop() {

  wind = ( 10*wind_speed() + 55 ) / 59; //calculating the speed of wind in km/h
  Serial.print("The speed of wind is: ");
  Serial.print(wind);
  Serial.println(" km/h");

}


