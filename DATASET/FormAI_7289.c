//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 100

// Function to get the binary equivalent of an integer
char* int2bin(int n, int num_bits) {
    char* bin_str = (char*) malloc(num_bits + 1);
    int mask = 1 << num_bits - 1;
    for (int i = 0; i < num_bits; i++) {
        bin_str[i] = ((n & mask) == 0) ? '0' : '1';
        mask >>= 1;
    }
    bin_str[num_bits] = '\0';
    return bin_str;
}

// Function to convert a binary string to an integer
int bin2int(char* bin_str) {
    int num_bits = strlen(bin_str);
    int num = 0;
    for (int i = 0; i < num_bits; i++) {
        num <<= 1;
        num += (bin_str[i] == '1' ? 1 : 0);
    }
    return num;
}

// Function to encode data using the watermark
void encode(char* data, char* watermark, int num_bits) {
    int watermark_size = strlen(watermark);
    int j = 0;
    for (int i = 0; i < strlen(data); i++) {
        if (j == watermark_size) {
            j = 0;
        }
        char* bin_str_data = int2bin(data[i], 8);
        char* bin_str_watermark = int2bin(watermark[j], num_bits);
        for (int k = 0; k < num_bits; k++) {
            if (bin_str_watermark[k] == '1') {
                bin_str_data[k] = (bin_str_data[k] == '1' ? '0' : '1');
            }
        }
        data[i] = (char) bin2int(bin_str_data);
        j++;
    }
}

// Function to decode the watermark from encoded data
void decode(char* encoded_data, char* decoded_watermark, int num_bits) {
    int watermark_size = strlen(decoded_watermark);
    int j = 0;
    for (int i = 0; i < strlen(encoded_data); i++) {
        if (j == watermark_size) {
            j = 0;
        }
        char* bin_str_data = int2bin(encoded_data[i], 8);
        char* bin_str_watermark = (char*) malloc(num_bits + 1);
        for (int k = 0; k < num_bits; k++) {
            bin_str_watermark[k] = bin_str_data[k];
            if (decoded_watermark[j] == '1') {
                bin_str_watermark[k] = (bin_str_watermark[k] == '1' ? '0' : '1');
            }
            j++;
            if (j == watermark_size) {
                j = 0;
            }
        }
        bin_str_watermark[num_bits] = '\0';
        decoded_watermark[j] = (char) bin2int(bin_str_watermark);
    }
}

int main() {
    char data[DATA_SIZE] = "Hello World!";
    char watermark[] = "1010";
    printf("Original Data: %s\n", data);
    encode(data, watermark, strlen(watermark));
    printf("Encoded Data: %s\n", data);
    char decoded_watermark[strlen(watermark) + 1];
    decoded_watermark[strlen(watermark)] = '\0';
    decode(data, decoded_watermark, strlen(watermark));
    printf("Decoded Watermark: %s\n", decoded_watermark);
    return 0;
}