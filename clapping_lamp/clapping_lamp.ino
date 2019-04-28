int ledPin=9;
int sensorPin=7;

boolean val = 0; // sensor HIGH or LOW
boolean status_lights = false;

// for counting and calibrating clap
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  //Serial.begin(9600);
}
  
void loop (){
  int status_sensor = digitalRead(sensorPin);
  
  if (status_sensor == 1){
    if (clap == 0){
      detection_range_start = detection_range = millis();
      clap++; 
    } else if (clap > 0 && millis()-detection_range >= 100){
      detection_range = millis();
      clap++;
      //Serial.print("counting clap: ");
      //Serial.println(clap);
    }
  }
  
  if (millis()-detection_range_start >= 600){
    if (clap == 2){ 
      if (!status_lights){
        digitalWrite(ledPin, HIGH);
        status_lights = true;
        clap = 0;
      } else if (status_lights){
        status_lights = false;
        digitalWrite(ledPin, LOW);
      }
    }
    clap = 0;
  }
}
