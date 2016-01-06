/*
This sketch demonstrates how to send data from a Host
to a Device in a Gazell network.

Button A on the Host is used to toggle the Green led
on the Device.

Since the Device must initiate communication, the
device "polls" the Host evey 200ms.
*/

#include <RFduinoGZLL.h>

device_t role = DEVICE0;

// pin for the Green Led
int datalen =-1;
int green_led = 3;
String inputString = "";
void setup()
{
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);

  // start the GZLL stack
  RFduinoGZLL.begin(role);
}

void loop()
{
  String firstVal, secondVal;
//  delay(20);

if(inputString == ""){
  Serial.print("NO DATA");
  }
  if(inputString != ""){




//
int commaIndex = inputString.indexOf(',');
int secondCommaIndex = inputString.indexOf(',', commaIndex+1);
int thirdCommaIndex = inputString.indexOf(',', commaIndex+2);

String IDValue = inputString.substring(0, commaIndex);
String value1 = inputString.substring(commaIndex+1, secondCommaIndex);
String value3 = inputString.substring(thirdCommaIndex);
String value2 = value3.substring(',',1);
int commaIndex2 = value2.indexOf(',');
String value4 = value2.substring(0,commaIndex2);
int final = value2.indexOf(',', commaIndex2+2);
String value5 = value2.substring(commaIndex2+1);


char ybuf[32];
char pbuf[32];
char rbuf[32];
value1.toCharArray(ybuf, sizeof(ybuf));
value4.toCharArray(pbuf, sizeof(pbuf));
value5.toCharArray(rbuf, sizeof(rbuf));
//float y = atof(ybuf);
//float p = atof(pbuf);
//float r = atof(rbuf);

//Serial.println(inputString);

//Serial.println(y);
//Serial.println(p);
//Serial.println(r);
if((inputString[2]=='A')||(inputString[2]=='a')||(inputString[2]=='b')||(inputString[2]=='c')||(inputString[2]=='d')||(inputString[2]=='e')||(inputString[2]=='f')){
//  

  Serial.print(inputString[2]);
Serial.print(",");

for (int i=0;i< value1.length(); i++){
  if((value1[i]=='-')||(value1[i]=='.')||((value1[i]>='0')&&(value1[i]<='9'))){
  Serial.print(value1[i]);
  }
  }
  Serial.print(",");

 for (int i=0;i< value4.length(); i++){
  if((value4[i]=='-')||(value4[i]=='.')||((value4[i]>='0')&&(value4[i]<='9'))){
  Serial.print(value4[i]);
  }
  }
  Serial.print(",");

  for (int i=0;i< value5.length(); i++){
  if((value5[i]=='-')||(value5[i]=='.')||((value5[i]>='0')&&(value5[i]<='9'))){
  Serial.print(value5[i]);
  }
  }
  
  Serial.println("");
}
//Serial.println(value1);
//Serial.println(value4);
//Serial.println(value5);


//Serial.println(IDValue);
//    Serial.println(value1);
//    Serial.println(value2);
//    Serial.println(value3);     
   



}
//inputString = "";
  // request the state from the Host (send a 0 byte payload)
  Serial.println(datalen);
  delay(9);
//  RFduinoGZLL.sendToHost("a");
//  delay(10);
//  RFduinoGZLL.sendToHost("b");
//    delay(10);
    RFduinoGZLL.sendToHost("c");
    delay(9);
//  RFduinoGZLL.sendToHost("d");
//    delay(10);
//    RFduinoGZLL.sendToHost("e");
//    delay(10);
  RFduinoGZLL.sendToHost("f");
//  delay(9);


}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{

  
  datalen=len;
  // ignore acknowledgement without payload
  if (len >0)
  {
//    Serial.println(data);
    inputString=data;
    
    
  }
//  if (len ==0)
//  {
////    Serial.println(data);
//    inputString="";
//    
//    
//  }
  
}
