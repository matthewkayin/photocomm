#include <iostream>
#include <math.h>


/*
I add my test code, I know it's simple but I thought the way these functions are suppose to work is you pass in r as the size of bits its
suppose to be. So say we want 8 in 5 bits which is 00010 so in the to_int we pass in 5 as r since that's what the value is so it checks
to see if the last bool bin[r-1] is 1 then it is negative if it's a 0 it is positive. Positive number won't have an issue but negative will
say -8 in 4 bits 0001 so to_int checks bin[r-1] since it's a 1 it returns sum*-1.
because if our limit is [8] bits then like you said it'll be a range from
-255 to only 127 since the last bit has to be a 0 to be considered positive we can't go over 127.
also in you test code it passes 8 bits to to_int everytime and like I said the way I have it is that it checks the last bit to see if it's
positive or not and that would affect it such as if we want -8 out of 8 bits 00010000 = 8.
I might be overthinking it, so please let me know what you think. 
*/
bool* to_binary(int n, int r){
	bool *bin = new bool[8];
	int i, j;
	if(n < 0){
	    n = n * -1;
	}
	for(i = 0; n > 0; i++){
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
	for(i = 0; i < r; i++){
		num += (n[i] * pow(2, i));
	}
	if(n[r-1] == 1){
		return num * -1;
	}
	return num;
}

int main(){

    bool succeeds_all = true;

    int r = 8;
    for(int i = -std::pow(2, r - 1); i <= std::pow(2, r - 1); i++){

        bool* output = to_binary(i, r);
        bool success = to_int(output, r) == i;
        if(!success){

            std::cout << "Functions failed on n = " << i << std::endl;
            std::cout << "Binary value was = ";
            for(int j = 0; j < r; j++){

                std::cout << output[j];
            }
            std::cout << std::endl;
            std::cout << "to_int value was = " << to_int(output, r) << std::endl;
            succeeds_all = false;
            break;
        }
    }

    if(succeeds_all){

        std::cout << "Tests passed!" << std::endl;
    }

    return 0;
}

/*
int main(){

    bool *bin = new bool[8];
    
    bin = to_binary(8, 5);
    for(int i = 0; i < 5; i++){
        std::cout << bin[i];
    }
    
    std::cout << std::endl << to_int(bin, 5) << std::endl;
    
    bin = to_binary(-8, 4);
    for(int i = 0; i < 4; i++){
        std::cout << bin[i];
    }
    
    std::cout << std::endl << to_int(bin, 4) << std::endl;
    
    bin = to_binary(127, 8);
    for(int i = 0; i < 8; i++){
        std::cout << bin[i];
    }
    
    std::cout << std::endl << to_int(bin, 8) << std::endl;
    
    bin = to_binary(-127, 7);
    for(int i = 0; i < 7; i++){
        std::cout << bin[i];
    }
    
    std::cout << std::endl << to_int(bin, 7) << std::endl;
    
    bin = to_binary(-255, 8);
    for(int i = 0; i < 8; i++){
        std::cout << bin[i];
    }
    
    std::cout << std::endl << to_int(bin, 8) << std::endl;

    return 0;
}
*/
