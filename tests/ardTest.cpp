#include <iostream>
#include <fstream>
#include <cmath>
#include "serial.hpp"

//constants for sine wave
const float AMP = 10;
const float FREQ = 100;
const float PHASE = 0.0;
const int SAMPLE_RATE = 44100;
const float TIME_CHANGE = 1.0 / SAMPLE_RATE;
const int BUFFSIZE = 500;

void compare(int num1, int num2);
void sineWaveGen(double* arr, int size);

int main(){

    Serial arduino;
    std::string* msg;
    bool opened = arduino.open(msg);
    int rec = 0;
    int sent = 0;
    std::cout << *msg << std::endl;

    

    double *monoBuffer = new double[BUFFSIZE];
     
    sineWaveGen(monoBuffer, BUFFSIZE);

    //if(opened){
        for (int i = 0; i < BUFFSIZE; i++){
        std::cout << monoBuffer[i] << std::endl;

        //arduino.write(monoBuffer[i]);
        //rec = arduino.read();
        //compare(sent, rec);
        }

    //}
    //else{
        //TODO: deal with unopened serial
    //} 
    
    return 0;
}

void compare(int sent, int received){
    if (sent == received){
        std::cout  << "OK!" << std::endl;
    }
    else{
        std::cout << "TEST FAILED!" << std::endl;
        std::cout << "SENT : " << sent << '\t';
        std::cout << "RECEIVED: " << received << std::endl;
    }
}

void sineWaveGen(double* arr, int size){

    float time = 0.0;
    
    for (int sample = 0; sample < size; sample++){
        
        double value = AMP * sin(2 * (2 * M_PI) * FREQ * time + PHASE);
        arr[sample] = value;
        
        time += TIME_CHANGE;
           
    }
}