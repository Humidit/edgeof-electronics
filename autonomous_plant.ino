int led =12;
void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
 int sensorValue= analogRead(A0);
 Serial.println(sensorValue);
 delay(200);
 if(sensorValue <=500)
  digitalWrite(led,HIGH);
 else
  digitalWrite(led,LOW);
  
   
}
 
 
