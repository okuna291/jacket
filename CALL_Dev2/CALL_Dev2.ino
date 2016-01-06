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
//  delay(20);
  if(inputString != ""){
   
Serial.println(inputString);


}
//inputString = "";
  // request the state from the Host (send a 0 byte payload)
  delay(10);
  RFduinoGZLL.sendToHost("a");
  delay(10);
  RFduinoGZLL.sendToHost("b");
    delay(10);
    RFduinoGZLL.sendToHost("c");
    delay(10);
  RFduinoGZLL.sendToHost("d");
    delay(10);
    RFduinoGZLL.sendToHost("e");
    delay(10);
  RFduinoGZLL.sendToHost("f");
  delay(10);


}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{

//  Serial.println(len);
  // ignore acknowledgement without payload
  if (len >0)
  {
//    Serial.println(data);
    inputString=data;
    
  }
}
