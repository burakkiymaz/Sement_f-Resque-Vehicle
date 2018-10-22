#include <math.h>

int state = 0;
int motorRun = 0;
int counter = 0;
double mean = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

/*
** In this function calculating mean value of temperature for detecting temperature decrease
*/

double Termistor(int analogRead)
{
  // calculating analog value to true value
  double temperature;
  temperature = log(((10240000 / analogRead) - 10000));
  temperature = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperature * temperature )) * temperature );
  temperature = temperature - 273.15;
  return temperature;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void motor(){
  counter += 1;
  Serial.println(counter);
  if (counter < 10){
    Serial.println("Running");
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else{
    Serial.println("Stopped");
    digitalWrite(3, LOW);
    digitalWrite(4,HIGH);
  }
}

void loop()
{

  int value;
  double temperature;
  value = analogRead(A0);
  temperature = Termistor(value);
  /*if (state == 0){
    state = 1;
    delay(20000);
  }*/
  for (int i = 0; i < 100; i++){
    value = analogRead(A0);
    mean = Termistor(value);
  }
  if(temperature < mean){
    Serial.println(temperature);
    digitalWrite(2, HIGH);
    /*Temperature decreased*/
    motor();
  }
  delay(450);
} 
