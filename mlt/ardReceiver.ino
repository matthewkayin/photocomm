const int BUTTON = 2; //digital in
const int RECEIVER = 0; //digital in
const int DAC_IN = A1; //analog in
const int MIC = A0; // microphone analog in

const int LED = 8; //PWM out
const int SPKR = 11; //Speaker - PWM out
const int DAC_OUT = 13; //digital to analog converter - digital out

int data = 0;
bool btnState = false;

void setup(){
    //pinMode(RECEIVER, INPUT);
    //pinMode(MIC, INPUT);
    pinMode(BUTTON, INPUT);
    
    //This input not yet used
        //pinMode(DAC_IN, INPUT);

    //used as an indicator light
    pinMode(LED_BUILTIN, OUTPUT);
    
    //These output pins not yet used
        //pinMode(SKPR, OUTPUT);
        //pinMode(LED, OUTPUT);
        //pinMode(DAC_OUT, OUTPUT);
    
    Serial.begin(38400);

}

void loop(){
    btnState = digitalRead(BUTTON);
    data = analogRead(MIC);
    
       
    
    while (btnState){
        //button is down, so we transmit

        //do some compression here
        digitalWrite(LED_BUILTIN, HIGH);
        btnState = digitalRead(BUTTON);

        if (!btnState){
            digitalWrite(LED_BUILTIN, LOW);
            break;
        }
    }

    while (!btnState){
        //button is not pressed, so listen
        data = digitalRead(RECEIVER);
        
        //decompress here

        //convert data to analog

        //output data to Speaker over PWM pin
        analogWrite(SPKR, data);
        btnState = digitalRead(BUTTON);
    }
     

}