void setup() 
{

  for (int i = 6; i <= 13; i++) {
      pinMode(i, OUTPUT);
      Serial.begin(9600);
      while (!Serial);
      Serial.println("Input 1 to 8  to turn on the leds or push the 9 and see tha magic delete, if you want to torn off all just type 10");
      
    }
}

int n;
int j = 100;
void loop()

{
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == n)
    {
     digitalWrite(n + 12, HIGH);
     Serial.println("Command completed LED turned ON");
    }

    
    for (int i = 6; i <= 13; i++) {
      if (j < 1){j = 1;}
      digitalWrite(i, HIGH);
      delay(j);
      j -=1;
          digitalWrite(i, LOW);
      delay(0);
      }

    }

  }
}
