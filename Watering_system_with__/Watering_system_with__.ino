int sensor = A4;
int relay = 12;
int moisture = 1000;
int redled = 10;
int blueled = 9;
int greenled = 8;
int buzzer = 11;
int Float_switch = 3;
int sensorValue;
int percentValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(blueled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(Float_switch,INPUT_PULLUP);
  digitalWrite(relay, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(sensor);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);

int percentValue = map(sensorValue, 300, 1023, 100, 0);
Serial.print("\nPercentValue: ");
Serial.print(percentValue);
Serial.println("%");
delay(1000);

if (sensorValue > moisture) 
{
  digitalWrite(relay, LOW);
   digitalWrite(blueled, LOW);
   digitalWrite(redled, HIGH);
   Serial.println("Water Pump is ON ");
   Serial.println("Moisture : Dry ");
  delay(1000);
 } 
 else
 {
  digitalWrite(relay, HIGH);
  digitalWrite(blueled, HIGH);
   digitalWrite(redled, LOW);
  Serial.println("Water Pump is OFF");
   Serial.println("Moisture : Wet");
   delay(1000);
 }
  if(digitalRead(Float_switch) == HIGH){
  digitalWrite(greenled,HIGH);
  digitalWrite(buzzer,LOW);
 }
  else
  {
 digitalWrite(greenled,LOW);
  digitalWrite(buzzer,HIGH);
 tone(buzzer,150,1000);
 delay(1000);
 noTone(buzzer);

  }
}
