#define TRIGGER 4 // Define TRIGGER pin D2(corresponds to GPIO4 on the NodeMCU board)
#define ECHO    5 // Define ECHO pin D1(corresponds to GPIO5 on the NodeMCU board)
 
// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO

// The setup code will run only once for every time we run the program
void setup() {
  
  Serial.begin (9600); // Start the serial communication with the baudrate of 9600
  pinMode(TRIGGER, OUTPUT); // Define the TRIGGER pin as the output
  pinMode(ECHO, INPUT); // Define the ECHO pin as the output
}

// The loop code runs at an interval of 1 second as delay is taken as 1000ms
void loop() {
  
  long duration, distance; // Define variables to store the values of distance and duration
  digitalWrite(TRIGGER, LOW); 
  delayMicroseconds(2); 
  // Sets the TRIGGER HIGH (active) for 10 microseconds
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER, LOW);
  // Reads the echoPin, returns the soundwave travel in microseconds
  
  duration = pulseIn(ECHO, HIGH); // Calculates the duration
  distance = (duration/2) / 29.1; // Calculates the distance
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  // Displays the distance value
  
  delay(1000);
  // Prints the measured distance after every 1 second
}
