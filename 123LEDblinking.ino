//Blinking LED's//
int ledPin = 13;
int ledPin1 =12;
int ledPin2 = 11;
int ledPin3 = 10;
int ledPin4 = 9;
void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
}
void loop(){
  digitalWrite(ledPin,HIGH);
  delay(500);
   digitalWrite(ledPin1,HIGH);
   delay(400);
    digitalWrite(ledPin2,HIGH);
    delay(300);
     digitalWrite(ledPin3,HIGH);
     delay(200);
      digitalWrite(ledPin4,HIGH);
      delay(100);
      digitalWrite(ledPin,LOW);
      delay(100);
      digitalWrite(ledPin1,LOW);
      delay(100);
      digitalWrite(ledPin2,LOW);
      delay(100);
      digitalWrite(ledPin3,LOW);
      delay(100);
      digitalWrite(ledPin4,LOW);
      delay(100);
      digitalWrite(ledPin4,HIGH);
      delay(100);
       digitalWrite(ledPin3,HIGH);
       delay(90);
        digitalWrite(ledPin2,HIGH);
        delay(80);
         digitalWrite(ledPin1,HIGH);
         delay(70);
          digitalWrite(ledPin1,HIGH);
          delay(60);
}




  

 
