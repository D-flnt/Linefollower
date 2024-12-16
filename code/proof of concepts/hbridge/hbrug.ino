//POC pwm sturing motoren (aparte snelheids regeling)

const int Motorleft= 3;
const int Motorright= 5;

void setup() {
Serial.begin(9600);
pinMode(Motorleft, OUTPUT);
pinMode(Motorright, OUTPUT);

}

void loop() {


for (int i = 0; i <= 255; i+=5)
{
  analogWrite(Motorleft, i);
  delay(30);
}
for (int i = 0; i <= 255; i+=5)
{
  analogWrite(Motorright, i);
  delay(30);
}

for (int i = 255; i >= 0; i -= 5) 
{
  analogWrite(Motorleft, i);
  delay(30);
}
for (int i = 255; i >= 0; i -= 5) 
{
  analogWrite(Motorright, i);
  delay(30);
}
}
