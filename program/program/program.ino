int ledPin = 5;
int buttonApin = 9;
bool zustand1 = false;
char Incoming_value = 0;


void setup() 
{
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello World");
}

void master()
{
  Serial.println("Master runs...");
  zustand1 = false;
  bool device2 = false;
  while(true)
  {
    if (digitalRead(buttonApin) == LOW)
    {
      Serial.println("Button 1 pressed...");
      zustand1 =! zustand1;
      delay(200);
      Serial.print("Device1: ");
      Serial.println(zustand1);
    }
    

    if(zustand1 == true)
    {
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }
    if(Serial.available() > 0)
    {
      Incoming_value = Serial.read();
      if(Incoming_value == '1')
      {
        zustand1 = true;
        Serial.print("Device1: ");
        Serial.println(zustand1);

      }else if(Incoming_value == '0')
      {
        zustand1 = false;
        Serial.print("Device1: ");
        Serial.println(zustand1);

      }else if(Incoming_value == '3')
      {
        master();
      }
    }
    for(int counter = 0; counter < 3; counter++)
    {
      

    }
  }
}

void loop() 
{

  if(Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
    if(Incoming_value == '3')
    {
      master();
    }
  }
    



}
