//FormAI DATASET v1.0 Category: QR code reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 500

int main() {
    char qr_code[MAX_QR_CODE_SIZE]; //declare a char array to store the qr code
    char input;
    int i = 0; //counter variable for the qr code
    
    printf("Enter QR code to scan\n");
    
    //take input character by character until enter key is pressed or max code size is reached
    while((input = getchar()) != '\n' && i < MAX_QR_CODE_SIZE) {
        qr_code[i] = input;
        i++;
    }
    qr_code[i] = '\0'; //set last character of the code as '\0' to indicate the end of string
    
    bool is_qr_code = true; //flag variable to check if qr code is valid

    //check if the qr code starts with a valid header
    if(strncmp(qr_code, "QR_CODE:", 8) != 0) {
        printf("Invalid QR Code\n");
        is_qr_code = false;
    }
    
    int j = 8; //counter variable for checking body of the qr code
    
    //check if body of the qr code contains only alphanumeric and space characters
    while(qr_code[j] != '\0') {
        if((qr_code[j] >= 'A' && qr_code[j] <= 'Z') || (qr_code[j] >= 'a' && qr_code[j] <= 'z') || (qr_code[j] >= '0' && qr_code[j] <= '9') || qr_code[j] == ' ') {
            j++;
        }
        else {
            printf("Invalid QR Code\n");
            is_qr_code = false;
            break;
        }
    }
    
    if(is_qr_code) {
        printf("QR Code Successfully Scanned!\n");
        printf("QR Code Body: %s\n", qr_code + 8); //display only the body of the qr code without the header
    }
    
    return 0;
}