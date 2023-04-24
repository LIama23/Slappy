int ledPin = 5;
int ledPin2 = 6;
int buttonApin = 9;
int buttonApin2 = 10;
bool device1 = false;
bool device2 = false;
char Incoming_value = 0;


void setup() 
{
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonApin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello World");
}

void master()
{
  Serial.println("Master runs...");
  device1 = true;
  device2 = false;
  while(true)
  {
    if (digitalRead(buttonApin) == LOW)
    {
      Serial.println("Button 1 pressed...");
      device1 = false;
      device2 = true;
      delay(200);
      Serial.print("Device1: ");
      Serial.println(device1);
      Serial.print("Device2: ");
      Serial.println(device2);
    }
    if (digitalRead(buttonApin2) == LOW)
    {
      Serial.println("Button 2 pressed...");
      device1 = true;
      device2 = false;
      delay(200);
      Serial.print("Device1: ");
      Serial.println(device1);
      Serial.print("Device2: ");
      Serial.println(device2);
    }
    

    if(device1 == true)
    {
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }

    if(device2 == true)
    {
      digitalWrite(ledPin2, HIGH);
    }else{
      digitalWrite(ledPin2, LOW);
    }

    if(Serial.available() > 0)
    {
      Incoming_value = Serial.read();
      if(Incoming_value == '1')
      {
        device1 = true;
        Serial.print("Device1: ");
        Serial.println(device1);

      }else if(Incoming_value == '0')
      {
        device1 = false;
        Serial.print("Device1: ");
        Serial.println(device1);

      }else if(Incoming_value == '3')
      {
        master();
      }else if(Incoming_value == '4')
      {
        device2 = true;
        Serial.print("Device2: ");
        Serial.println(device2);
      }else if(Incoming_value == '5')
      {
        device2 = false;
        Serial.print("Device2: ");
        Serial.println(device2);
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
