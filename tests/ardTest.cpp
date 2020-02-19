#include <iostream>
#include <fstream>
#include "serial.hpp"


void compare(int num1, int num2);

int main(){

    Serial arduino;
    std::string* msg;
    bool opened = arduino.open(msg);
    int rec = 0;
    int sent = 0;
    std::cout << *msg << std::endl;

    
    for (int i = 0; i < 1024; i++){
        std::cout << i << std::endl;
        if(opened){
            sent = i;
            arduino.write(sent);
            rec = arduino.read();
            compare(sent, rec);
        }
        else{
            //TODO: deal with unopened serial
            //break;
        } 
    }
    return 0;
}

void compare(int sent, int received){
    if (sent == received){
        std::cout  << "OK!" << std::endl;
    }
    else{
        std::cout << "TEST FAILED!" << std::endl;
        std::cout << "SENT : " << sent;
        std::cout << "RECEIVED: " << received << std::endl;
    }
}