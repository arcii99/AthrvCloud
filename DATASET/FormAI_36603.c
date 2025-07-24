//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the binary representation of a character
char* getBinary(char c){
    char* binary = (char*) malloc(sizeof(char)*8);
    for(int i = 0; i < 8; i++){
        binary[7-i] = (c & (1 << i)) ? '1' : '0';
    }
    return binary;
}

// Function to get the character from binary data
char getCharacter(char* binary){
    char c = 0;
    for(int i = 0; i < 8; i++){
        c |= (binary[i] == '1') ? (1 << (7-i)) : 0;
    }
    return c;
}

// Function to generate the watermark
char* generateWatermark(char* message, char* password){
    char* watermark = (char*) malloc(sizeof(char)*strlen(message));
    int passwordIndex = 0;
    for(int i = 0; i < strlen(message); i++){
        watermark[i] = message[i] ^ password[passwordIndex];
        passwordIndex++;
        if(passwordIndex == strlen(password)){
            passwordIndex = 0;
        }
    }
    return watermark;
}

// Function to extract the watermark from the message
char* extractWatermark(char* message, char* password){
    char* watermark = (char*) malloc(sizeof(char)*strlen(message));
    int passwordIndex = 0;
    for(int i = 0; i < strlen(message); i++){
        watermark[i] = message[i] ^ password[passwordIndex];
        passwordIndex++;
        if(passwordIndex == strlen(password)){
            passwordIndex = 0;
        }
    }
    return watermark;
}

int main(){
    char* message = "This is my secret message!";
    char* password = "SuperSecretCode";
    char* watermark = generateWatermark(message, password);
    printf("Message: %s\n", message);
    printf("Password: %s\n", password);
    printf("Watermark: ");
    for(int i = 0; i < strlen(watermark); i++){
        printf("%c", watermark[i]);
    }
    printf("\n");
    printf("Binary Watermark: ");
    for(int i = 0; i < strlen(watermark); i++){
        printf("%s", getBinary(watermark[i]));
    }
    printf("\n");
    char* extractedWatermark = extractWatermark(watermark, password);
    printf("Extracted Watermark: ");
    for(int i = 0; i < strlen(extractedWatermark); i++){
        printf("%c", extractedWatermark[i]);
    }
    printf("\n");
    return 0;
}