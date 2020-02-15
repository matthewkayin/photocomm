#include <Wire.h>
//#include <SoftwareSerial.h>

const int MIC1 = A0;

void setup(){
    pinMode(MIC1, INPUT);

    Serial.begin(57600);
    Wire.begin();
    
}

void loop(){

    int x = analogRead(MIC1);
    Serial.print("x: ");
    Serial.println(x);

    //change value range from 10 bit to 8 bit
    map(x, 0, 1023, 0, 255);

}
