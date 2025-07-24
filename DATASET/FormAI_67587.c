//FormAI DATASET v1.0 Category: QR code reader ; Style: scalable
// QR Code Reader Program in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define QR_CODE_SIZE 25
#define MAX_INPUT_LENGTH 1000

// Helper function to get user input
void getInput(char *inputString){
    printf("Enter the QR Code (alphanumeric characters only, max %d characters): ", QR_CODE_SIZE);
    fgets(inputString, MAX_INPUT_LENGTH, stdin);
    strtok(inputString, "\n");  // remove the newline character from the input string
}

// Helper function to validate the QR code format
bool isValidQRCode(char *qrCodeString){
    int len = strlen(qrCodeString);
    if(len == QR_CODE_SIZE){
        for(int i=0; i<len; i++){
            if((qrCodeString[i]>='A' && qrCodeString[i]<='Z') || (qrCodeString[i]>='a' && qrCodeString[i]<='z') || (qrCodeString[i]>='0' && qrCodeString[i]<='9')){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    return false;
}

// Helper function to decode the QR code
void decodeQRCode(char *qrCodeString){
    printf("\nQR Code Decoded: ");
    for(int i=0; i<QR_CODE_SIZE; i+=2){
        int num = (qrCodeString[i]-'0')*10 + (qrCodeString[i+1]-'0');
        printf("%c", (char)num);
    }
    printf("\n\n");
}

// Main function
int main(){
    char inputString[MAX_INPUT_LENGTH], qrCodeString[QR_CODE_SIZE+1];

    do{
        getInput(inputString);

        if(isValidQRCode(inputString)){
            strncpy(qrCodeString, inputString, QR_CODE_SIZE);
            decodeQRCode(qrCodeString);
        }else{
            printf("Invalid QR Code! Please try again!\n\n");
        }

    }while(true);

    return 0;
}