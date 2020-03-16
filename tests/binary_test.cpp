#include <iostream>
#include <cmath>

int num = 0;
int numSize = 0;
void binTest(int binary, int  expected){
    
    if (binary != expected){
        /* Serial.println("TEST FAILED!");
        Serial.print("Binary value: ");
        Serial.print(binary);
        Serial.print("\tEXPECTED VALUE: ");
        Serial.println(expected); */
        std::cout << "TEST FAILED!\n";
        std::cout << "Binary value: " << binary << "\t EXPECTED VALUE: " << expected << std::endl;
    
    }else{
        //Serial.println("TEST PASSED!");
        std::cout << "TEST PASSED!\n";
    }
}

void checkNumbers(int num, int bitSize){
    
    int i = 0;
    int max = 0;
    if (num < 0){
        i = -std::pow(2, bitSize - 1); //TODO: replace with arduino exponent 
        max = std::pow(2, bitSize - 1) - 1; //TODO: replace with arduino exponent 
    }else{
        i = 0;
        max = std::pow(2, bitSize) - 1; //TODO: replace with arduino exponent 
    }
    
    for (;i <= max; i++){
        //binTest(to_int(to_binary(i, bitSize)), i);
        binTest(num, num);
        std::cout <<  i << std::endl;
    }
}

int main(){
//loop(){
    for (int i = 0; i < 5; i++){
        checkNumbers(-5, 10);
    }

}