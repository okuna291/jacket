#include <RFduinoGZLL.h> // include rfduino library
device_t role = DEVICE2; // set Device name... DEVICE2 to DEVICE7 / HOST
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  RFduinoGZLL.txPowerLevel = 0;
  RFduinoGZLL.begin(role); // begin BLE communications
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}
void loop() {
//  Serial.println("A");
digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(25);
  serialEvent(); //call the function
  // print the string when a newline arrives:
  char mydata[25]; // declare mydata array+
  if (stringComplete) {
    Serial.println(inputString);
    inputString.toCharArray(mydata, 25);
    digitalWrite(2,HIGH);
    RFduinoGZLL.sendToHost(mydata, 25); // send buffer to host other rfduino
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
void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len) // this function receives BLE communications
{

}
