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

void loop() 
{

  if (digitalRead(buttonApin) == LOW)
  {
    Serial.println("Pressed...");

    zustand1 =! zustand1;
    delay(200);
  }
  
  Serial.println(zustand1);
  if(zustand1 == true)
  {
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }

  if(Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
    if(Incoming_value == '1')
    {
      zustand1 = true;
    }else if(Incoming_value == '0'){
      zustand1 = false;
    }

  }

}