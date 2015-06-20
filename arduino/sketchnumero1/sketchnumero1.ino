
#define pinRed 5
#define pinGreen 6
#define pinBlue 7
#define FluxoAtivo 2
#define ReleAtivo 8 
#define LigarFluxo 10
#define ledON LOW
#define ledOFF HIGH
#define ligado HIGH
#define desligado LOW



void setup() {
  // put your setup code here, to run once:
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pinBlue, OUTPUT);
    pinMode(2, INPUT);
    pinMode(ReleAtivo, INPUT);
    pinMode(LigarFluxo, OUTPUT);
    digitalWrite(pinRed,ledON);
    digitalWrite(pinGreen,ledOFF);
    digitalWrite(pinBlue,ledOFF); 
  // PararFluxoAgua();
 Serial.begin(9600);
 attachInterrupt(0,fluxo,CHANGE);
 
 }

void loop() {
// digitalWrite(pinRed,ledOFF);
  
  
 
}

void fluxo()
{
  digitalWrite(pinRed,digitalRead(2));
}


boolean ReleLigado()
{
  if(digitalRead(ReleAtivo) == LOW)
  {
    return true;
  }
  else
  {
     return false; 
  }
}

boolean AguaPassando()
{
 if(digitalRead(FluxoAtivo) == HIGH)
  {
      return true; 
  }
  else
  {
      return false;
  }
}

void LiberarFluxoAgua()
{
  digitalWrite(LigarFluxo, LOW);
}

void PararFluxoAgua()
{
  digitalWrite(LigarFluxo, HIGH);
}
