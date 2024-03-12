#include <SPI.h>
#include <RFID.h>
#include <Keyboard.h>

#define dogruLed 12
#define yanlisLed 13
int dogruKartID[5] = {195,88,37,173,19};
int kapamaKartID[5] ={195, 200, 217, 27, 201};
RFID rfid(10, 9);
void setup() {
 pinMode(dogruLed,OUTPUT);
 pinMode(yanlisLed,OUTPUT);
 SPI.begin();
 rfid.init();

}

void loop() {
  if(rfid.isCard())
  {
  if (rfid.readCardSerial())
  {
    if (rfid.serNum[0] == dogruKartID[0] &&
        rfid.serNum[1] == dogruKartID[1] &&
        rfid.serNum[2] == dogruKartID[2] &&
        rfid.serNum[3] == dogruKartID[3] &&
        rfid.serNum[4] == dogruKartID[4])
      {
        
        digitalWrite(dogruLed,HIGH);
        Keyboard.press(KEY_ESC);
        delay(50);
        Keyboard.releaseAll();
        delay(250);
        Keyboard.print("BİLGİSAYAR ŞİFRENİZ NE İSE BURAYA ONU GİRİN");
        Keyboard.press(KEY_RETURN);
        delay(50);
        Keyboard.releaseAll();
        delay(1000);
      }
    else
    {
      digitalWrite(yanlisLed,HIGH);
      delay(10);
      }
      digitalWrite(dogruLed,LOW);
      digitalWrite(yanlisLed,LOW);
    if (rfid.serNum[0] == kapamaKartID[0] &&
        rfid.serNum[1] == kapamaKartID[1] &&
        rfid.serNum[2] == kapamaKartID[2] &&
        rfid.serNum[3] == kapamaKartID[3] &&
        rfid.serNum[4] == kapamaKartID[4])
        { 
          Keyboard.press(KEY_LEFT_GUI);              
  Keyboard.press('l');                       
  Keyboard.releaseAll(); 
          }
  }
  }

}
