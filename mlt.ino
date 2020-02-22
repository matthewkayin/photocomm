
/*  Set function generator to Ampl 4.75 Vpp,
    and Offset of 2.500 Vdc. Then we can vary the frequency.
    This program can read the wave and pass that to the led over a PWM pinMode
    Increase the baudrate we can write to Serial quicker.

*/
int led = 9;
int wave = A0;

int received = 0;

void setup(){
    pinMode(wave, INPUT);
    
    pinMode(led, OUTPUT);
    //Serial.begin(112500);
}


void loop(){

    received = analogRead(wave);
    analogWrite(led, received);

}
