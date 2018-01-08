#include <Nefry.h>
#include <NefryIFTTT.h>
String Event, SecretKey;


int soundValueNow;
int soundValueBefore = 0;

void setup() {
  Nefry.setStoreTitle("SecretKey",0); //Nefry DataStoreのタイトルを指定
  Nefry.setStoreTitle("Event",1);     //Nefry DataStoreのタイトルを指定
  SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
  Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
  
  Nefry.println("Grove Sound sensor SETUP");
  
  Nefry.setLed(0,0,0);
  pinMode(A2,INPUT_PULLUP);//入力モード切り替え
}

void loop() {
  soundValueNow = analogRead(A2);
  
  Nefry.print("soundValueBefore=");
  Nefry.println(soundValueBefore);
  Nefry.print("soundValueNow=");
  Nefry.println(soundValueNow);
  
  if(soundValueBefore < 300){
    if(soundValueNow > 700){
      bool sendData = IFTTT.send(Event, SecretKey,"Nefry_LightON","響いているねえ、、、",(String)soundValueNow);//IFTTTにデータを送信
       }
      }
  
  soundValueBefore = soundValueNow;
  Nefry.print("soundValueBefore=");
  Nefry.println(soundValueBefore);
  Nefry.println("");
  
  Nefry.ndelay(10000);
}
