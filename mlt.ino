#include "./libraries/SevSeg-master/SevSeg.h"
#include <Wire.h> //For synchronous communication


SevSeg sevseg;

unsigned long before_time = 0;
const long SECOND = 1000;
const int frequency = 10;
const long SAMPLE_TIME = SECOND / frequency;

int analog_values[256];
int analog_index = 0;

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

    Serial.begin(9600);
}

/*void received(int bytesRead){
 *  while (1 < Wire.available()){ //loop through all but the last
 *      char c = Wire.read(); //receive byte as a character.
 *  }                      
 *  int x = Wire.read(); //receive byte as an int
 *}
 *
 * void requested(){
 *      Wire.write("hello "); //send the 6 byte message requested
 * }

*/
void loop(){
    //we can either start the bus here on in the setup function.
    //  need to discuss pros/cons
    //Wire.begin(x);//join i2c bus. where x = optional 7-bit slave address


    /*Basic sending structure is dependant on who is the master
     *if master is writer:
     *  
     *  writer (master):
     *      1. Wire.beginTransmission(slave_addr); //slave_addr is 7-bit address of slave being sent to
     *      2. Wire.write(str); //str can be a byte, string, array of data. if str is an array, also need to include # of bytes to be sent
     *      3. Wire.endTransmission(stop); //Sends the message queued by write(), and either re starts transmission or releases bus if stop is true
     *  
     *  receiver (slave):
     *      1. Wire.begin(4); //joins bus as slave with address #4
     *      2. Wire.onReceive(received); // received (declared above) is a function that should be called when slave device receives transmission.
     *                   
     * if master is reader:
     *  
     *  writer (slave):
     *      1. Wire.begin(2); //Join i2c bus as a slave with address #4
     *      2. Wire.onRequest(requested); //requested (declared above) is a function to be called when
     *      3. requested sends the data
     *      
     *  receiver (master):
     *      1. Wire.begin(); //join i2c bus as master
     *      2. Wire.request(2, numBytes); //request 6 bytes of data from slave #2
     *      3. while(Wire.available()){ //slave may send fewer bytes than requested
     *              char c = Wire.read(); //receive byte as character 
     *         }
     *      
    */  
    unsigned long elapsed = millis() - before_time;
    if(elapsed >= SAMPLE_TIME){

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

        //float value = (signal_counter * 5.0) / 1024.0;
        //sevseg.setNumber(value, 3);
        before_time += SAMPLE_TIME;
    }

    //sevseg.refreshDisplay();
}
