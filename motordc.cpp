#define motor1pin1  3 // pin1 rotação sentido horário
#define motor2pin1 2

#define sensore1 8
#define sensore2 9

const int vel = 6;  //motor 1
const int vel1 = 5;  //motor 2

void setup() {
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(sensore1, INPUT_PULLUP);
  pinMode(sensore2, INPUT_PULLUP);
  pinMode(vel, OUTPUT);
  pinMode(vel1, OUTPUT);
}

void loop() {

  int sensorest2=digitalRead(sensore2);
  int sensorest1=digitalRead(sensore1);

  if(sensorest1==LOW && sensorest2==LOW || sensorest1==HIGH && sensorest2==LOW){
    digitalWrite(motor1pin1, HIGH); //horário 
    digitalWrite(motor2pin1, HIGH); //horário 
    analogWrite(vel, 80);
    analogWrite(vel1, 200);
  }
    if(sensorest1==LOW && sensorest2==HIGH){
    digitalWrite(motor1pin1, HIGH); //horário 
    digitalWrite(motor2pin1, LOW); //horário 
    analogWrite(vel, 80);
  }
    if(sensorest1==HIGH && sensorest2==HIGH){
    digitalWrite(motor1pin1, LOW); //horário 
    digitalWrite(motor2pin1, LOW); //horário 
    analogWrite(vel, 80);
    analogWrite(vel1, 200);

  }
}
