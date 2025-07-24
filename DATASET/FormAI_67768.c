//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert decimal to binary
void decToBin(int n, int binary[]){
    int i = 0;
    while(n > 0){
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
}

// function to convert binary to decimal
int binToDec(int binary[], int len){
    int decimal = 0;
    for(int i = len-1; i >= 0; i--){
        decimal += binary[i] * pow(2, len-i-1);
    }
    return decimal;
}

int main(){
    // original data
    int data = 123;

    // convert data to binary
    int binary[8] = {0};
    decToBin(data, binary);

    // watermark data
    int watermark = 5;

    // convert watermark to binary
    int watermarkBinary[3] = {0};
    decToBin(watermark, watermarkBinary);

    // embed watermark into binary data
    int start = 2;
    for(int i = 0; i < 3; i++){
        binary[start+i] = watermarkBinary[i];
    }

    // convert binary data back to decimal
    int newData = binToDec(binary, 8);

    printf("Original data: %d\n", data);
    printf("Watermark: %d\n", watermark);
    printf("New data with watermark: %d\n", newData);

    return 0;
}