double sensorValue=0;
double sensorValue1=0;
int crosscount=0;
int climbhill=0;
double VmaxD=0;
double VeffD;
double Veff;
int analogInput = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;
int relay1 = 12;
int relay2 = 11;
void setup() {
pinMode(analogInput, INPUT);
Serial.begin(9600);
pinMode(relay1,OUTPUT);
}
void loop() {
sensorValue1=sensorValue;
delay(100);
sensorValue = analogRead(A0);
if (sensorValue>sensorValue1 && sensorValue>511)
 {
   climbhill=1;
   VmaxD=sensorValue;
 }
if (sensorValue<sensorValue1 && climbhill==1)
 {
   climbhill=0;
   VmaxD=sensorValue1;
   VeffD=VmaxD/sqrt(2);
   Veff=(((VeffD-420.76)/-90.24)*-210.2)+210.2;
   Serial.println(Veff);
   VmaxD=0;
 }
 {
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  Serial.print("INPUT Voltage= ");
  Serial.println(vin, 2);
  delay(100);
 }
 {
  if(Veff>=100&&vin>=10)
   {
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,LOW);
   }
 else if(Veff>=100&&vin<10)
  {
   digitalWrite(relay1,LOW);
   digitalWrite(relay2,HIGH);
  }
     else if(Veff<100&&vin>9)
     {
      digitalWrite(relay1,LOW);
      digitalWrite(relay2,HIGH);
     }
     else
    {
      digitalWrite(relay1,LOW);
      digitalWrite(relay2,HIGH);
    }     
 }
}
