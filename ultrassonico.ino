//roboultrassonico.ino

//robo anda e para quando estiver a 10 sentimetros de algum obstáculo

#include "Ultrasonic.h"
#include "Servo.h"

Servo ServoD;
Servo ServoE;

int echoPino = 12;
int trigPino = 13;
long duracao = 0;
long distancia = 0;

void setup() {
	ServoD.attach(6);
	ServoE.attach(5);
	pinMode(echoPino, INPUT);
	pinMode(trigPino, OUTPUT);
}

void loop() {

//pino trigger com um pulso baixo LOW (desligado)
digitalWrite(trigPino, LOW);
// delay de 10 microssegundos
delayMicroseconds(10);
//pino trigger com pulso HIGH (ligado)
digitalWrite(trigPino, HIGH);
//delay de 10 microssegundos
delayMicroseconds(10);
//pino trigger com um pulso baixo LOW (desligado) novamente
digitalWrite(trigPino, LOW);
//a função pulseInt verifica o tempo que o pino ECHO ficou HIGH
//calculando assim a duração do tráfego do sinal
duracao = pulseIn(echoPino,HIGH);
//cálculo baseado em: distância = duração/58.
distancia = duracao/58;
	
	if(distancia < 10){
	    ServoD.write(90);
		ServoE.write(90);
		delay(1000);// Robô para

	} else {
	    ServoD.write(0);
		ServoE.write(180);
		delay(1000);// Robô anda
	}
}

