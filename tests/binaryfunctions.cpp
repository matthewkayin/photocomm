#include <iostream>
#include <math.h>

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
