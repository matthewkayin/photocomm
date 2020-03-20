#include <iostream>
#include <math.h>

bool* to_binary(int n, int r){

	bool* ret_val = new bool[8];
	int remaining = n;
	if(remaining < 0){

		ret_val[0] = 1;
		remaining *= -1;

	}else{

		ret_val[0] = 0;
	}

	for(int i = 1; i < r; i++){

		if(remaining >= std::pow(2, r - i - 1)){

			ret_val[i] = 1;
			remaining -= std::pow(2, r - i - 1);

		}else{

			ret_val[i] = 0;
		}
	}

	return ret_val;
}

int to_int(bool* n, int r){

	int sum = 0;
	for(int i = 1; i < r; i++){

		sum += n[i] * std::pow(2, r - i - 1);
	}
	if(n[0]){

		sum *= -1;
	}

	return sum;
}

int main(){

    bool succeeds_all = true;

    int r = 8;
    for(int i = -std::pow(2, r - 1) + 1; i <= std::pow(2, r - 1) - 1; i++){

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
