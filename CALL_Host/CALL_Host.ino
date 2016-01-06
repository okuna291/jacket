/*
This sketch demonstrates how to send data from a Host
to a Device in a Gazell network.

Button A on the Host is used to toggle the Green led
on the Device.

Since the Device must initiate communication, the
device "polls" the Host evey 200ms.
*/

#include <RFduinoGZLL.h>
device_t role = HOST;
int devID=97;
char mydata[25];
String inputString = ""; // a string to hold incoming data
String inputStringOut = ""; 
boolean stringComplete = false;  // whether the string is complete


void setup()
{
  inputString.reserve(200);
  RFduinoGZLL.begin(role);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}




void loop()
{
  //  Serial.println("A");
digitalWrite(2,LOW);
  digitalWrite(3,LOW);
//  delay(25);
  serialEvent(); //call the function
  // print the string when a newline arrives:
  char mydata[25]; // declare mydata array+
  if (stringComplete) {
    Serial.println(inputString);
    inputString.toCharArray(mydata, 25);
    inputStringOut=inputString;
    digitalWrite(2,HIGH);
//    RFduinoGZLL.sendToHost(mydata, 25); // send buffer to host other rfduino
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == 97) {
      stringComplete = true;
      digitalWrite(3,HIGH);
    }
    else     inputString += inChar;
  }
}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{
  // piggyback the current Host Button A state on the acknowledgement sent
  // back to the Device
//  digitalWrite(3,LOW);
//  if(data[0]==devID){
//  RFduinoGZLL.sendToDevice(device, mydata);}
//  digitalWrite(3,HIGH);
}

