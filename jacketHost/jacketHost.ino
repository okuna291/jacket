/*
This sketch demonstrates how to send data from a Device
to a Host in a Gazell network.

The host and upto 3 devices should have the RGB shield
attached.  When Button A on a Device is pressed, the
associated led on the Host will toggle.  Device1 is
associated with the Red led, Device2 with the Green led
and Device3 with the Blue led.

The Green led on the Device will blink to indicate
that an acknowledgement from the Host was received.
*/

#include <RFduinoGZLL.h>

device_t role = HOST;

// pin for the Green Led
String sstr,sstr1, sstr2, sstr3, sstr4, sstr5, sstr6;

void setup()
{
Serial.begin(9600);
  // start the GZLL stack  
  RFduinoGZLL.begin(role);
}

void loop()
{
  Serial.flush();
  if(sstr!="")  Serial.println(sstr);
  if(sstr1!="")  Serial.println(sstr1);
  if(sstr2!="")  Serial.println(sstr2);
  if(sstr3!="")  Serial.println(sstr3);
  if(sstr4!="")  Serial.println(sstr4);
  sstr="";
  sstr1="";
  sstr2="";
  sstr3="";
  sstr4="";
}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{
  sstr=data;
}
