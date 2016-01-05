
//Mux control pins
int s0 = 4;
int s1 = 5;
int s2 = 7;
int s3 = 8;

//Mux in "SIG" pin
int SIG_pin = A7;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);


   pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  Serial.begin(9600);
}

void loop() {
           
  MUX();
  FLASH();
}


int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}



void MUX()
{
  Serial.print("CHANEL 10= ");
  Serial.println(readMux(1));
  Serial.print("CHANEL 9= ");
  Serial.println(readMux(5));
  Serial.print("CHANEL 8= ");
  Serial.println(readMux(14));
    Serial.print("CHANEL 7= ");
  Serial.println(readMux(10));
   Serial.print("CHANEL 6= ");
  Serial.println(readMux(6));

    delay(500);
  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346
//  for(int i = 0; i < 16; i ++){
//    Serial.print("Value at channel ");
//    Serial.print(i);
//    Serial.print("is : ");
//    Serial.println(readMux(i));
//    delay(50);
//  }
}
void FLASH(){
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, HIGH); 
  delay(10);              // wait for a second
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
  delay(10);
  }
