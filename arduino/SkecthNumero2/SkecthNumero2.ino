

#define sensorhumidade A0
#define ledGreen 6 
#define ledRed 5
#define ledBlue 7
#define releligado 8
#define ligarrele 2

int humidade = 0;        

void setup() {
  // initialize serial communications at 9600 bps:
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledBlue, OUTPUT);
    pinMode(releligado, INPUT);
    pinMode(ligarrele, OUTPUT);
    LedsOff();
  
    
    
    
    Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  int leitura = analogRead(sensorhumidade);
   if(humidade != leitura)
  {
  humidade = leitura;
  HumidadeSolo();  
  }
  
  ReleLigado();
  
  
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.print(humidade);
  //Serial.print("\t output = ");
  //Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

void LigarRele()
{
  digitalWrite(ligarrele,LOW);
  
  
}

void DesligarRele()
{
  digitalWrite(ligarrele,HIGH);
}

void LedsOff()
{
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, HIGH); 
}

void ReleLigado()
{
 if(digitalRead(releligado) == LOW)
{
 Serial.print("RELE: LIGADO");
} 
else
{
 Serial.print("RELE: DESLIGADO"); 
}
 
 
  
}


void HumidadeSolo()
{
 
  LedsOff();
  
 if(humidade < 500)
{
  digitalWrite(ledGreen,LOW);
 DesligarRele();
}
else 
{
  digitalWrite(ledRed,LOW);
  LigarRele();
}
}
