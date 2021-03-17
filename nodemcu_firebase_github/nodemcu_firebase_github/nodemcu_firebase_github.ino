#include <FirebaseESP8266.h>
#include  <ESP8266WiFi.h>

#define ssid ""  //WiFi SSID
#define password ""  //WiFi Password
#define FIREBASE_HOST ""       //Firebase Project URL Remove "https:" , "\" and "/"
#define FIREBASE_AUTH ""      //Firebase Auth Token

FirebaseData firebaseData;

//If using Relay Module
int Device_1 = D6; //initialize D6 Pin
int Device_2 = D0; //initialize D0 Pin
int Device_3 = D1; //initialize D1 Pin
int Device_4 = D2; //initialize D2 Pin



void setup() {
  
 Serial.begin(9600);
   WiFi.begin (ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    pinMode(Device_1,OUTPUT);//initialize the Device OUTPUT  
    pinMode(Device_2,OUTPUT);//initialize the Device OUTPUT  
    pinMode(Device_3,OUTPUT);//initialize the Device OUTPUT  
   // pinMode(Device_4,OUTPUT);//initialize the Device OUTPUT  

}

void loop() {
  
  if (Firebase.get(firebaseData,"/iottry2/D1")) {
    if (firebaseData.dataType() == "string") {
      String  De1 = firebaseData.stringData();
          if (De1=="1"){
              digitalWrite(Device_1,LOW); //Device1 is ON
              Serial.println("done1");
          }
          else if (De1=="0"){
              digitalWrite(Device_1,HIGH);//Device1 if OFF
              Serial.println("done 2");
            }}}
 if (Firebase.get(firebaseData,"/iottry2/D2")) {
    if (firebaseData.dataType() == "string") {
      String De2 = firebaseData.stringData();
          if (De2=="1"){
              digitalWrite(Device_2,LOW);//Device2 is ON
          }
              else if (De2=="0"){
              digitalWrite(Device_2,HIGH);// Device2 os OFF
            }}}
  if (Firebase.get(firebaseData,"/iottry2/D3")) {
    if (firebaseData.dataType() == "string") {
      String De3 = firebaseData.stringData();
          if (De3=="1"){
              digitalWrite(Device_3,LOW);//Device3 is ON
          }
              else if (De3=="0"){
              digitalWrite(Device_3,HIGH);//Device3 is OFF
            }}}
                      
  if (Firebase.get(firebaseData,"/iottry2/D4")) {
    if (firebaseData.dataType() == "string") {
      String De4 = firebaseData.stringData();
          if (De4=="1"){
              digitalWrite(Device_4,HIGH);//Device4 is ON
          }
              else if (De4=="0"){
              digitalWrite(Device_4,LOW);//Device4 is OFF
            }}}

  }
