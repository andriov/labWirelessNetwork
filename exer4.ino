#include <SoftwareSerial.h> // ' set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'

String readString;

String value;
int led1 = 8;
int led2 = 3;
char DAT = 0;

void setup(){
  
  Serial.begin(9600); // ' serial monitor communication at 9600 bps'
  Serial.println("Done"); // 'write "Done" on the monitor'
  wirelessNetworkYT.begin(9600); // 'communication at 38400 bps'
  pinMode(led1, OUTPUT);
}
void loop(){
  if (wirelessNetworkYT.available()){ // ' if there is information available from module'
    while (wirelessNetworkYT.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    char c = DAT = wirelessNetworkYT.read(); // 'stores in DATO the character received from module'
    Serial.write(DAT);
    readString += c;
  }
  if(readString.equals("5") || readString.equals("encender")){
      digitalWrite(led1,HIGH);
      //readString="";
  }
  else if(readString.equals("4") || readString.equals("encender")){
      digitalWrite(led1,LOW);
      //readString="";
  }
  else if(readString.equals("2") || readString.equals("encender")){
      digitalWrite(led2,HIGH);
      //readString="";
  }
  else if(readString.equals("3") || readString.equals("encender")){
      digitalWrite(led2,LOW);
      //readString="";
  }
  readString="";
//if(Serial.available()) // 'information available from the serial monitor'
  //wirelessNetworkYT.write(Serial.read()); // 'read serial monitor and send to Bluetooth'

  
  }
}
