
int outvec[] = {};
int pinvec[] = {};
int j = 100;


void setup() 
{
  for(int j = 0; j < 7; j++)
    int outvec[] = {j};
  

  for(int i = 7; i <= 13; i++){ 
      pinMode(pinvec[i], OUTPUT);
      }    
      Serial.begin(9600);
      while (!Serial);
      Serial.println("Input 1 to 7  to turn on the leds or push the 8 and see tha magic delete or push the 9 and look at the runing light.If you type 1--and the number what led you want to read--, you get that is ON or OFF");
}
void loop()

{
  if (Serial.available()) 
  {
    int state = Serial.parseInt();
    
    
    if (pinvec[state]== state +6)
    {
     digitalWrite(pinvec[state], HIGH);
     Serial.println("Command completed LED turned ON");
    }


    if (state == 8)
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
    
    if (state == 9)
    {

    for (int i = 6; i <= 13; i++) {
      if (j < 1){j = 1;}
      digitalWrite(i, HIGH);
        delay(j);
        j -=4;
          digitalWrite(i, HIGH);
        delay(0);
      }

    }

    if (state == 10)
    {
     for (int i = 6; i <= 13; i++)
     digitalWrite(i, LOW);
     Serial.println("Command completed LED turned OFF");
    }


    if (outvec[state-11]== state-11)
    {
     digitalRead(pinvec[state - 11] == LOW);
     Serial.println("OFF");}
      else {Serial.println("ON");}


  }
}

  
