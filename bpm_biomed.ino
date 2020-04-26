int sp = A0;
float sv = 0;
int c = 0;
unsigned long starttime =0;
boolean counted = false;
int heartrate = 0;
void setup()
{
  Serial.begin(96000);
  pinMode(13, OUTPUT);
}
void loop()
{
  starttime = millis();
  while(millis()<starttime+10000)
  {
    sv=analogRead(sp);
    if(sv>80 && counted == false)
    {
      c++;
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
    }
    else if(sv<80)
    {
      counted = false;
      digitalWrite(13, LOW);  
    }
  }
heartrate = c*6;
Serial.println();
Serial.println(heartrate);
Serial.println();
}
