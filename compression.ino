void setup(){

    Serial.begin(9600);
}

void loop(){

    int* source = new int[8];
    for(int i = 0; i < 8; i++){

        source[i] = 900 + (i * 20);
    }
    int* compressed = compress(source, 8, 8, 4);
    int* decompressed = decompress(compressed, 8, 8, 4);
    for(int i = 0; i < 8; i++){

        Serial.print(decompressed[i]);
        if(i != 7){

            Serial.print(", ");
        }
    }
    Serial.print("\n");

    delay(1000);
}


/*
Compresses an array of integers using lossy compression

Compression method, Discrete Cosine Transform type II
https://en.wikipedia.org/wiki/Discrete_cosine_transform

@param data - the data to be compressed, values should range from 0 to 1023
@param N - the length of the data array
@param r - each compressed data point will be representable by an unsigned int of r bits
@param d - the amount of compressed values to keep. This will be the length of the returned
            array. N-d values will therefore be left out and assumed to be 0 during decompression
            This works because the most important values in the DCT are towards the front of the
            array
*/
int* compress(int* data, int N, int r, int d){

    const int shift = (int)(1023 / 2);
    const long int MAX_VALUE = shift * N;
    const int scaler = pow(2, r - 1);

    int* compressed_data = new int[d];

    for(int k = 0; k < d; k++){

        // Compress the value using the Discrete Cosine Transform
        long int value = 0;
        for(int n = 0; n < N; n++){

            value += max(data[n] - 1 - shift, -shift) * cos((PI / N) * (n + 0.5) * k);
        }

        // Shrink the value to be representable in r bits
        compressed_data[k] = (int)(scaler * ((float)value / MAX_VALUE));
    }

    return compressed_data;
}

/*
Decompresses an array of integers using lossy compression

Compression method, Discrete Cosine Transform type III
https://en.wikipedia.org/wiki/Discrete_cosine_transform

@param data - the data to be compressed, values should range from -r^n-1 to r^n-1
@param N - the length of the resulting decompressed array
@param r - the size in bits of each data point when it was original compressed
@param d - the size of the array given. if d is less than N, N-d 0s will be added
            to the end of the array before decompression is performed
*/
int* decompress(int* data, int N, int r, int d){

    const int shift = (int)(1023 / 2);
    const long int MAX_VALUE = shift * N;
    const int scaler = pow(2, r - 1);

    long int* unshrunk_data = new long int[N];
    for(int i = 0; i < N; i++){

        if(i < d){

            unshrunk_data[i] = (long int)((data[i] * MAX_VALUE) / scaler);

        }else{

            unshrunk_data[i] = 0;
        }
    }

    int* decompressed_data = new int[N];
    for(int k = 0; k < N; k++){

        long int value = 0.5 * unshrunk_data[0];
        for(int n = 1; n < N; n++){

            value += unshrunk_data[n] * cos((PI / N) * n * (k + 0.5));
        }

        value *= (2.0 / N);
        decompressed_data[k] = (int)(value + shift);
    }

    return decompressed_data;
}
