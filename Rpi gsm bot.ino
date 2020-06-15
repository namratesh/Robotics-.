int led = 13;  // the pin that the LED is atteched to

pir_led = 12
ultra_led = 11
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
#define trigPin 3
#define echoPin 6

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
        
}


void loop()
{ ultra();
  pir();
 
}


void pir(){
  int sensor = digitalRead(sensor);
  if (sensor == 1) {
    Serial.println("motion detected");
    digitalWrite(led, LOW);
    digitalWrite(pir_led,LOW);

  }}

void ultra(){
   long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance <= 50 ){
    digitalWrite(led, HIGH);
    digitalWrite(ultra_led,HIGH);
    
    Serial.println(distance);
    Serial.println("cm");
  }
  else {
    Serial.print(distance);
    Serial.println("cm");
  }
  delay(500);
  


 
  }
