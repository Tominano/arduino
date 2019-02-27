void setup() 
{

  for (int i = 6; i <= 13; i++) {
      pinMode(i, OUTPUT);
      Serial.begin(9600);
      while (!Serial);
      Serial.println("Input 1 to 8  to turn on the leds or push the 9 and see tha magic delete, if you type 1--and the number what led you want to read--, you get that is ON or OFF");
      
    }
}


int j = 100;
void loop()

{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
     digitalWrite(13, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    if (state == 2)
    {
     digitalWrite(12, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    if (state == 3)
    {
     digitalWrite(11, HIGH);
     Serial.println("Command completed LED turned ON");
    }

 
    if (state == 4)
    {
     digitalWrite(10, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    
    if (state == 5)
    {
     digitalWrite(9, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    
    if (state == 6)
    {
     digitalWrite(8, HIGH);
     Serial.println("Command completed LED turned ON");
    }
    
    if (state == 7)
    {
     digitalWrite(7, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    if (state == 8)
    {
     digitalWrite(6, HIGH);
     Serial.println("Command completed LED turned ON");
    }
    
    if (state == 9)
    {

    for (int i = 6; i <= 13; i++) {
      if (j < 1){j = 1;}
      digitalWrite(i, HIGH);
        delay(j);
        j -=4;
          digitalWrite(i, LOW);
        delay(0);
      }

    }

    if (state == 10)
    {
     for (int i = 6; i <= 13; i++)
     digitalWrite(i, LOW);
     Serial.println("Command completed LED turned OFF");
    }

    if (state == 11)
      if (digitalRead(5) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

    if (state == 12)
      if (digitalRead(4) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

    if (state == 13)
      if (digitalRead(3) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

    if (state == 14)
      if (digitalRead(2) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

    if (state == 15)
      if (digitalRead(1) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

    if (state == 16)
      if (digitalRead(0) == LOW)
    {   Serial.println("OFF");}
      else {Serial.println("ON");}

  }
}
