int outvec[] = {};
int pinvec[] = {};
int j = 100;

void setup() {
    for(int j = 0; j < 7; j++)  /*Fill the outvec*/
    int outvec[] = {j};

  for(int i = 7; i <= 13; i++){ 
      pinMode(pinvec[i], OUTPUT);  /*Fill the pinvec and set those like outputs*/
      }    
      Serial.begin(9600);
      while (!Serial);
      Serial.println("Input 1 to 7  to turn on the leds or push the 8 and see tha magic delete or push the 9 and look at the runing light.");
      Serial.println("If you type 1--and the number what led you want to read--, you can see the LED status is ON or OFF");
}

void loop() 

{
  if (Serial.available())   /* https://www.arduino.cc/reference/en/language/functions/communication/serial/available/ */
  {
    int state = Serial.parseInt();   /*This is the reading from the serial*/


    if (pinvec[state]== state +6)
    {
     digitalWrite(pinvec[state], HIGH);   /*You can turn on the LEDs one by one*/
     Serial.println("Command completed LED turned ON");
    }


    if (state == 8)
    {

      for (int i = 7; i <= 13; i++) {
        if (j < 1){j = 1;}
          digitalWrite(i, HIGH);   /*You can turn OFF the whole panel with a runing light */
            delay(j);
              j -=1;
                digitalWrite(i, LOW);
                  delay(0);
      } 

       }

    if (state == 9)
    {

    for (int i = 7; i <= 13; i++) {
      if (j < 1){j = 1;}
      digitalWrite(i, HIGH);   /*You can turn ON the whole panel with a runing light */
        delay(j);
        j -=4;
          digitalWrite(i, HIGH);
        delay(0);
      }

    }

    if (state == 10)
    {
     for (int i = 7; i <= 13; i++)
     digitalWrite(i, LOW);          /*You can turn OFF every LEDs*/
     Serial.println("Command completed LEDs turned OFF");
    }


    if (outvec[state-11]== state-11)
    {
     digitalRead(pinvec[state - 11] == LOW);    /*You can scan outputs, what is their status*/
     Serial.println("This output is NOT working now, this LED is turned OFF!");}
      else {Serial.println("This output is WORKING now, this LED is turned ON!");}


  }
}
