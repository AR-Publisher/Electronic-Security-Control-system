#define trigPin 2
#define echoPin 3
#define buzzer 7
#define LED 4

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
   pinMode(LED, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  //digitalWrite(SolenoidPin, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance= ");
  Serial.print(distance);
  Serial.println("  cm");
  delay(10);
  if(distance < 10)
  {digitalWrite(buzzer,HIGH );}
  else
  {digitalWrite( buzzer, LOW);}
  if(distance < 10)
  {digitalWrite(LED,HIGH );
    delay(100);
  }
  else
  {digitalWrite( LED, LOW);}
  
}
