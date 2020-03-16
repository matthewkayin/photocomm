unsigned long before_time = 0;
const long SECOND = 1000;
const int frequency = 10;
const long SAMPLE_TIME = SECOND / frequency;

int analog_values[256];
int analog_index = 0;

const int MIC1 = A0;

void setup(){

    pinMode(MIC1, INPUT);

    Serial.begin(9600);

    before_time = millis();
}


void loop(){

        int signal_counter = analogRead(MIC1);
        analog_values[analog_index] = signal_counter;
        analog_index++;

        if(analog_index == 256){

            for(int i = 0; i < 256; i++){

                Serial.print(analog_values[i]);
                Serial.print(" ");
            }

            Serial.print("\n");

            analog_index = 0;
        }

        before_time += SAMPLE_TIME;
    }

    received = analogRead(wave);
    analogWrite(led, received);
}
