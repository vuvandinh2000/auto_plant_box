#include <dht.h>

dht DHT;

#define led 2
#define pump 3
#define fan 4
#define photo 5
#define dht11 6
#define title 7
#define touch 8
#define buzzer 9
#define light 10
#define ground A5

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
  pinMode(pump, OUTPUT);
  digitalWrite(pump, LOW);

  pinMode(photo, INPUT);
  pinMode(touch, INPUT);
  pinMode(title, INPUT);
  pinMode(light, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(ground, INPUT);
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //PUMP CONTROL
    int val_gnd = analogRead(ground);
    Serial.print("Do am dat = "); Serial.println(val_gnd);
    if (val_gnd >= 900) {
      Serial.println("AAAAAAAAAAAAAAAAAAAA");
      digitalWrite(pump, LOW);
    }
    else {
      digitalWrite(pump, HIGH);
    }
  //END PUMP CONTROL
  
  //TILTE - BUZZER CONTROL
    bool val_tilt = digitalRead(title);
    if(val_tilt!=1){              
      val_tilt = 1;              
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1sec 

      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1sec 
    }
  //END TITLE - BUZZER CONTROL
  //TOUCH CONTROL
    bool val_touch = digitalRead(touch);
    if (val_touch == 1) {
      digitalWrite(light, HIGH);
    }
    else {
      digitalWrite(light, LOW);
    }
  //END TOUCH CONTROL

  //DHT11 CONTROL
    int chk = DHT.read11(dht11);
    Serial.print("Nhiet do = "); Serial.println(DHT.temperature);
    if (DHT.temperature <= 35) {
      digitalWrite(fan, LOW);
    }
    else {
      digitalWrite(fan, HIGH);
    }
  //END DHT11 CONTROL

  //LED CONTROL
    //photo_state: 0 - light, 1 - dark
    bool photo_state = digitalRead(photo);
    if (photo_state == 0) {
      //Troi sang
      digitalWrite(led, HIGH);
    }
    else {
      //Troi toi
      digitalWrite(led, LOW);
    }
  //END LED CONTROL
}
