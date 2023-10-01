// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int startDistance = 999;
int reps;
bool repAdded = true;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin to high
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  Serial.print("startDistance: ");
  Serial.println(startDistance);
  
  //set startDistance
  if (distance < startDistance){
    startDistance = distance;
  } 

}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin to high
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  Serial.print("Reps: ");
  Serial.println(reps);

  //if rep has already been added and we are still at start position, do not add another rep
  if (repAdded && distance >= startDistance - 5 && distance <= startDistance + 5){
    //do not add a rep
  } else {
    //allow rep to be added
    repAdded = false;
  }

  //if current distance is within 5 of the startDistance, add a rep
  if (distance >= startDistance - 5 && distance <= startDistance + 5 && !repAdded) {
    reps++;
    repAdded = true;
  }

}