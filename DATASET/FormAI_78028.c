//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

// A function to convert decimal to binary
void decimalToBinary(int num, int binary[]){
    int index = 8;
    while(num > 0){
        binary[index--] = num % 2;
        num /= 2;
    }
}

// A function to convert binary to decimal
int binaryToDecimal(int binary[]){
    int num = 0, base = 1;
    for(int i = 7; i >= 0; i--){
        num += binary[i] * base;
        base *= 2;
    }
    return num;
}

// A function to encode the message into the image
void encode(char image[], char message[]){
    int len = strlen(message);
    int binaryMessage[len * 8]; // Array to store binary value of message
    for(int i = 0; i < len; i++){
        // Convert each char into decimal and then to binary
        decimalToBinary((int) message[i], &binaryMessage[i * 8]);
    }
    
    FILE *fp = fopen(image, "rb+");
    if(fp == NULL){
        printf("Error opening image file!\n");
        return;
    }
    
    int pixel[3];
    // Skip the header of the image, we only need to encode the message in the pixels
    fseek(fp, 54, SEEK_SET);
    for(int i = 0; i < len * 8; i++){
        // Read 3 bytes (1 pixel) from the image
        fread(pixel, sizeof(int), 3, fp);
        int bit = 0;
        if(binaryMessage[i] == 1){
            bit = 1;
        }
        // Encode the bit in the last bit of the pixel's blue component
        pixel[2] = (pixel[2] & 0xFE) | bit;
        // Write back the modified pixel to the image
        fseek(fp, -3, SEEK_CUR);
        fwrite(pixel, sizeof(int), 3, fp);
    }
    fclose(fp);
    printf("Message encoded successfully!\n");
}

// A function to decode the message from the image
void decode(char image[], char message[]){
    FILE *fp = fopen(image, "rb");
    if(fp == NULL){
        printf("Error opening image file!\n");
        return;
    }
    
    int pixel[3];
    // Skip the header of the image, we only need to decode the message from the pixels
    fseek(fp, 54, SEEK_SET);
    int binaryMessage[MAX_LENGTH * 8]; // Array to store binary value of decoded message
    int index = 0;
    while(1){
        // Read 3 bytes (1 pixel) from the image
        fread(pixel, sizeof(int), 3, fp);
        // Get the last bit of the pixel's blue component
        int bit = pixel[2] & 0x01;
        // Convert the bit to decimal and then to binary
        decimalToBinary(bit, &binaryMessage[index]);
        index++;
        if(index == MAX_LENGTH * 8 || !bit){ // Stop decoding when the maximum length is reached or when the last two bits are 0
            break;
        }
    }
    fclose(fp);
    int len = index / 8;
    for(int i = 0; i < len; i++){
        // Convert each 8 bits (1 byte) of binary message to decimal and then to char
        message[i] = binaryToDecimal(&binaryMessage[i * 8]);
    }
    printf("Decoded message: %s\n", message);
}

int main(){
    char image[] = "image.bmp";
    char message[] = "Hello, world! This is a secret message.";
    char decodedMessage[MAX_LENGTH] = {0};
    
    // Encode the message into the image
    encode(image, message);
    // Decode the message from the image
    decode(image, decodedMessage);
    
    return 0;
}