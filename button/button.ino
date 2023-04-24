int ledPin = 5;
int buttonApin = 9;
bool zustand1 = false;


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
    delay(2000);
  }
  
  Serial.println(zustand1);
  if(zustand1 == true)
  {
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }


}