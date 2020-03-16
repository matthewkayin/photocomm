bool* to_binary(int n, int r){
	bool *bin = new bool[r];
	int i;
	for(i = 0; n > 0; i++){
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
	for(i = 0; i < r; i++){
		num += (n[i] * pow(2, i));
	}
	return num;
}
