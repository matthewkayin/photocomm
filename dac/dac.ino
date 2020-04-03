// #include <Wire.h> <-- you might need to uncomment this
#include <Adafruit_MCP4725.h>

// Change this value to change the sine wave frequency
const int frequency = 440;

unsigned long before_time = 0;
const long SECOND = 1000000;
const long SAMPLE_TIME = SECOND / frequency;
const float STEP_SIZE = (2.0 * PI) / frequency;

float current_theta = 2.0 * PI;
int current_direction = -1;

Adafruit_MCP4725 dac;

void setup(){

    // For MCP4725A0 the address is 0x60 or 0x61
    // For MCP4725A2 the address is 0x64 or 0x65
    dac.begin(0x62);

    before_time = micros();
}


void loop(){

    if(micros() - before_time >= SAMPLE_TIME){

        // update the theta by step size amount
        current_theta += STEP_SIZE * current_direction;
        if(current_direction == -1 && current_theta <= 0){

            current_theta = -current_theta;
            current_direction *= -1;

        }else if(current_direction == 1 && current_theta >= 2.0 * PI){

            current_theta = (2.0 * PI) - (current_theta - (2.0 * PI));
            current_direction *= -1;
        }

        // convert theta to voltage. sine value of -1 is 0 and sine value of 1 is 4095
        uint32_t dac_out_voltage = (uint32_t)((sin(current_theta) + 1) * (4095.0 / 2.0));
        dac.setVoltage(dac_out_voltage, false);

        before_time += SAMPLE_TIME;
    }
}
