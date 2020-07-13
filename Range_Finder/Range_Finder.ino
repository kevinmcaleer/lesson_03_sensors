// Lesson 03 Sensors
// www.smarsfan.com/play/lessons/lesson_03_sensors

// set the Rangefinder pins
#define echoPin 8 
#define trigPin 7  

// set the variables for ping duration and measured distance
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:

  // setup the Pin modes for the range finder
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR07");
  Serial.println("with Arduino UNO R3");
}

void loop() {
  // put your main code here, to run repeatedly:

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
