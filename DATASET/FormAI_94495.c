//FormAI DATASET v1.0 Category: QR code reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500

void printQRCode(char* qrCode) {
    //This function prints the QR code provided
    
    printf("\n\nQR Code:\n\n");
    
    int len = strlen(qrCode);
    
    for(int i=0; i<len; i++) {
        if(qrCode[i] == '1') {
            printf("*");
        } else {
            printf(" ");
        }
        
        if((i+1) % 25 == 0) { //Assuming QR code size is 25x25
            printf("\n");
        }
    }
}

int main() {
    //This program takes input string and prints the QR code
    
    printf("Enter the QR code string:\n");
    
    char input[MAX_LENGTH];
    
    fgets(input, MAX_LENGTH, stdin);
    
    input[strcspn(input, "\n")] = 0; //Removing the newline character from input
    
    printQRCode(input);
    
    return 0;
}