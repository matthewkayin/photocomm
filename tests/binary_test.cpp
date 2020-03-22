#include <iostream>
#include <cmath>

int num = 0;
int numSize = 0;

bool* to_binary(int n, int r){
	bool *bin = new bool[r];
	int i;
	if(n < 0){
		bin[0] = 1;
	} else { bin[0] = 0; }
	for(i = 1; n > 0; i++){
		bin[i] = n % 2;
		n = n /2;
	}
	if(i > r){
		std::cout << "ERROR OUT OF RANGE!";
		return NULL;
	}
	return bin;
}

int to_int(bool* n, int r){
	int num = 0, i;
	for(i = 0; i < r-1; i++){
		num += (n[i] * pow(2, i));
	}
	if(n[r-1] == 1){
		return num * -1;
	}
	return num;
}
void binTest(int binary, int expected){
    
    if (binary != expected){
        /* Serial.println("TEST FAILED!");
        Serial.print("Binary value: ");
        Serial.print(binary);
        Serial.print("\tEXPECTED VALUE: ");
        Serial.println(expected); */
        std::cout << "TEST FAILED!\n";
        std::cout << "Binary value: " << binary << "\tEXPECTED VALUE: " << expected << std::endl;
    
    }else{
        //Serial.println("TEST PASSED!");
        std::cout << "OK ";
    }
}

void checkNumbers(int num, int bitSize){
    
    int i = 0;
    int max = 0;

    if (num < 0){
        i = -pow(2, bitSize - 1); //TODO: replace with arduino exponent 
        max = pow(2, bitSize - 1) - 1; //TODO: replace with arduino exponent 
    }else{
        i = 0;
        max = pow(2, bitSize) - 1; //TODO: replace with arduino exponent 
    }
    bool* n; 
    for (;i <= max; i++){
        n = to_binary(i, bitSize);
        binTest(to_int(n, i), i);
        //std::cout <<  i << std::endl;
    }
}



int main(){
//loop(){
   
    //checkNumbers(-5, 10);
    
    bool* n = new bool[4];
    
    n = to_binary(4, 4);
    
    for (int i = 0; i < 4; i++){
        std::cout << n[i];
    }
   
    return 0;
}