#include "./libraries/SevSeg-master/SevSeg.h"

SevSeg sevseg;

unsigned long before_time = 0;
const long SECOND = 1000;
const int frequency = 1;
const long SAMPLE_TIME = SECOND / frequency;

const int MIC1 = A0;

void setup(){

    pinMode(MIC1, INPUT);

    byte num_digits = 4;
    // byte digit_pins[] = {10, 11, 12, 13};
    byte digit_pins[] = {13, 12, 11, 10};
    byte segment_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

    bool resistors_on_segments = true;
    bool update_with_delays_in = false;
    bool leading_zeros = true;
    byte hardware_config = COMMON_CATHODE;
    sevseg.begin(hardware_config, num_digits, digit_pins, segment_pins, resistors_on_segments, update_with_delays_in, leading_zeros);
    sevseg.setBrightness(90);

    before_time = millis();
}

void loop(){

    unsigned long elapsed = millis() - before_time;
    if(elapsed >= SAMPLE_TIME){

        int signal_counter = analogRead(MIC1);
        sevseg.setNumber(signal_counter);
        before_time += SAMPLE_TIME;
    }

    sevseg.refreshDisplay();
}
