#include <iostream>
#include <math.h>

bool* to_binary(int n, int r){
	bool *bin = new bool[r];
	int i;
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
		num += (n[i] * std::pow(2, i));
	}
	return num;
}

int main(){

    int n = 2;
    bool* output = to_binary(n, 8);
    for(int i = 0; i < 8; i++){

        std::cout << output[i];
    }
    std::cout << std::endl;
    bool success = to_int(output, 8) == n;

    std::cout << success << std::endl;

    return 0;
}
