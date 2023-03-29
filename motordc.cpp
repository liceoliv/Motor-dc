#define motor1pin1  3 // pin1 rotação sentido horário
#define motor2pin1 2

#define sensore1 8
#define sensore2 9

const int vel = 6;  //pino para definir velocidade do motor 1
const int vel1 = 5;  //motor 2

void setup() {
  
  pinMode(motor1pin1, OUTPUT);  //define entradas e saidas
  pinMode(motor2pin1, OUTPUT);
  pinMode(sensore1, INPUT_PULLUP);
  pinMode(sensore2, INPUT_PULLUP);
  pinMode(vel, OUTPUT);
  pinMode(vel1, OUTPUT);
}

void loop() {

  int sensorest2=digitalRead(sensore2); //variável que armazena valor dos sensores
  int sensorest1=digitalRead(sensore1);

 /* if(sensorest1==LOW && sensorest2==LOW || sensorest1==HIGH && sensorest2==LOW){ //condição de quando o motor deve girar
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor2pin1, HIGH); 
    analogWrite(vel, 80); //escolhe velocidade
    analogWrite(vel1, 200);
  }
  */
   if(sensorest1==LOW && sensorest2==LOW){ //condição de quando o motor deve girar
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin1, LOW); 
    analogWrite(vel, 80); //escolhe velocidade
    analogWrite(vel1, 200);
  }
    if(sensorest1==LOW && sensorest2==HIGH || sensorest1==HIGH && sensorest2==HIGH){
    digitalWrite(motor1pin1, HIGH); //horário 
    digitalWrite(motor2pin1, HIGH); //horário 
    analogWrite(vel, 80);
    analogWrite(vel1, 200);
  }
    if(sensorest1==HIGH && sensorest2==LOW){
    digitalWrite(motor1pin1, HIGH); //horário 
    digitalWrite(motor2pin1, LOW); //horário 
    analogWrite(vel, 80);
    analogWrite(vel1, 200);

  }
}

/* tabela verdade 
   s1|s2| m1   |  m2
    0|0 | low  | low
    0|1 | high | high
    1|0 | high | low
    1|1 | high | high
    
    no sensor que utilizei, 0 vale como objeto no caminho, e 1 sem objeto no caminho
