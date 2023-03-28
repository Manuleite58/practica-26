// C++ code
//
/*Este programa o que fai e detectar obxectos que esten
mais proximos a 12cm e avisar cun zumbador*/

#define zumbador 13
const int EchoPin = 9;
const int TriggerPin = 8;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(zumbador, OUTPUT);
}

void loop() {
proximo();
  }

bool proximo(){
if(medirDistancia() < 12) zumba();
  else noZumba();
  delay(50);
}
float medirDistancia(){  
  
  long duracion, distanceCm;
  
   digitalWrite(TriggerPin, LOW);
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duracion = pulseIn(EchoPin, HIGH);
   
   distanceCm = duracion * 10 / 292/ 2;
   return distanceCm;
}
void zumba(){
    digitalWrite(zumbador, HIGH);
    delay(50);
  }
  void noZumba(){
    digitalWrite(zumbador, LOW);
    delay(50);
  }
