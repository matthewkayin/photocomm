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
		cout << "ERROR OUT OF RANGE!";
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
