#include <math.h>

int durum = 0;
int motorCalis = 0;
int counter = 0;
double ortalama = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

double Termistor(int analogOkuma)
{
  double sicaklik;
  sicaklik = log(((10240000 / analogOkuma) - 10000));
  sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik )) * sicaklik );
  sicaklik = sicaklik - 273.15;
  return sicaklik;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void motor(){
  counter += 1;
  Serial.println(counter);
  if (counter < 10){
    Serial.println("Calisiyor");
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else{
    Serial.println("Durdu");
    digitalWrite(3, LOW);
    digitalWrite(4,HIGH);
  }
}

void loop()
{

  int deger;
  double sicaklik;
  deger = analogRead(A0);
  sicaklik = Termistor(deger);
  /*if (durum == 0){
    durum = 1;
    delay(20000);
  }*/
  for (int i = 0; i < 100; i++){
    deger = analogRead(A0);
    ortalama = Termistor(deger);
  }
  if(sicaklik < ortalama){
    Serial.println(sicaklik);
    digitalWrite(2, HIGH);
    Serial.println("Suyun altında");

    motor();
  }
  delay(450);
} 
