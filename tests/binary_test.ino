
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

		if(remaining >= pow(2, r - i - 1)){

			ret_val[i] = 1;
			remaining -= pow(2, r - i - 1);

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
void binTest(int bitSize){
    //set start/end values for given bitSize
    int max = pow(2, bitSize - 1) - 1;
    int i = -(pow(2, bitSize - 1) - 1);        
    
    
    for (; i <= max; i++){
        int binary = to_int(to_binary(i, bitSize), bitSize);        
        std::cout << binary << std::endl;
        
        if (binary != i){
            Serial.println("TEST FAILED!");
            Serial.print("Binary value: ");
            Serial.print(binary);
            Serial.print("\tEXPECTED VALUE: ");
            Serial.println(i);
            break;
        }
        
    }
}



loop(){

}