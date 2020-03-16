
/*  Set function generator to Ampl 4.75 Vpp,
    and Offset of 2.500 Vdc. Then we can vary the frequency.
    This program can read the wave and pass that to the led over a PWM pinMode
    Increase the baudrate we can write to Serial quicker.*/


const int IR = 8;
const int BUTTON = 2;
int time_interval = 1000;

bool ir_on = true;
bool btnState = false;

void setup() {

    pinMode(LED_BUILTIN, OUTPUT); 
    pinMode(BUTTON, INPUT);
    pinMode(IR, OUTPUT);
    Serial.begin(9600);
      
}

void loop() {

    btnState = digitalRead(BUTTON);

    while(btnState){
        if(ir_on){
            digitalWrite(LED_BUILTIN, LOW);
            digitalWrite(IR, LOW);
        
        }else{
            digitalWrite(LED_BUILTIN, HIGH);
            digitalWrite(IR, HIGH);
        
        }
        ir_on = !ir_on;
        btnState = digitalRead(BUTTON);
        
        delay(1000);
        if (!btnState){
            break;
        }
    }    
}

 