int sensor = A4;
int relay = 12;
int moisture = 1000;
int redled = 10;
int blueled = 9;
int greenled = 8;
int buzzer = 11;
int Float_switch = 3;
void setup() 
{
  pinMode(relay, OUTPUT); //Set pin 12 as OUTPUT pin, to send signal to relay
  pinMode(sensor, INPUT_PULLUP); //Set pin A4 as INPUT_PULLUP pin, to send signal to moisture sensor
  pinMode(blueled, OUTPUT); //Set pin 9 as OUTPUT pin, to send signal to led light blue
  pinMode(redled, OUTPUT); //Set pin 10 as OUTPUT pin, to send signal to led light red
  pinMode(greenled,OUTPUT); //Set pin 8 as OUTPUT pin, to send signal to led light green
  pinMode(buzzer,OUTPUT); //Set pin 11 as OUTPUT pin, to send signal to buzzer
  pinMode(Float_switch,INPUT_PULLUP); //Set pin 3 as INPUT_PULLUP pin, to send signal to Float switch
  digitalWrite(relay, HIGH); //if soil moisture sensor provides HIGH value send HIGH value to relay
  Serial.begin(9600);
}

void loop() 
{
  
int sensorValue = analogRead(sensor);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);

int percentValue = map(sensorValue, 300, 1023, 100, 0);
Serial.print("\nPercentValue: ");
Serial.print(percentValue);
Serial.println("%");
delay(1000);

if (sensorValue > moisture) //start to water the plant
{
  digitalWrite(relay, LOW); 
   digitalWrite(blueled, LOW);
   digitalWrite(redled, HIGH);
   Serial.println("Water Pump is ON ");
   Serial.println("Moisture : Dry ");
  delay(1000);
 } 
 else //stop watering the plants
 {
  digitalWrite(relay, HIGH);
  digitalWrite(blueled, HIGH);
   digitalWrite(redled, LOW);
  Serial.println("Water Pump is OFF");
   Serial.println("Moisture : Wet");
   delay(5000);
 }
  if(digitalRead(Float_switch) == HIGH)
  { 
  digitalWrite(greenled,HIGH);
  digitalWrite(buzzer,LOW);
 }
  else
  {
 digitalWrite(greenled,LOW);
  digitalWrite(buzzer,HIGH);
 tone(buzzer,150,1000);
 delay(1000);
 //noTone(buzzer);

  }
}
