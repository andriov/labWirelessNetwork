#include <SPI.h> 
#include <MFRC522.h>
#include <SoftwareSerial.h> // ' set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(5, 6); // 'pin 10 as RX, pin 11 as TX'


#define RST_PIN 9
#define SS_PIN 10

int tones=2;
int led=7;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(led,OUTPUT);
  pinMode(tones, OUTPUT);
  wirelessNetworkYT.begin(9600); // 'communication at 9600 bps'
}

void loop(){
  
  if(!mfrc522.PICC_IsNewCardPresent())
      return;
  if(!mfrc522.PICC_ReadCardSerial())
      return;
   
   Serial.print("UID:");
   for(byte i=0;i<mfrc522.uid.size; i++){
      if(mfrc522.uid.uidByte[i]<0x10){
        Serial.print("0");    
      } else {
        Serial.print(" ");
      }
      Serial.print(mfrc522.uid.uidByte[i],HEX);
   }


   

   if(mfrc522.uid.uidByte[0]==0x35 && mfrc522.uid.uidByte[1]==0xC3 && mfrc522.uid.uidByte[2]==0x1D && mfrc522.uid.uidByte[3]==0xC3){
      wirelessNetworkYT.write("Acesso correcto\n"); // 'read serial monitor and send to Bluetooth'
      delay(1000);
     
   
   } else {
      wirelessNetworkYT.write("Acesso denegado\n");

     
   }

   
   Serial.println();
   mfrc522.PICC_HaltA();
}
