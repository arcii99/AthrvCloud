//FormAI DATASET v1.0 Category: QR code reader ; Style: happy
#include<stdio.h>
#include<stdbool.h>

/* Function to check if given string is valid QR code */
bool isValidQRCode(char *code){
    int len = strlen(code);
    if(len != 25){
        return false;
    }
    for(int i=0;i<len;i++){
        if(code[i] < 'A' || code[i] > 'Z'){
            return false;
        }
    }
    return true;
}

/* Function to read QR code and validate it */
void readQRCode(){
    char code[26];
    printf("Welcome to our Happy QR code reader program!\n");
    printf("Please scan the QR code: ");
    scanf("%s", code);

    if(isValidQRCode(code)){
        printf("Hooray! You scanned a valid QR code. Enjoy your day!");
    } else {
        printf("Oops! The scanned QR code is invalid. Please try again.");
        readQRCode();
    }
}

/* Main function to start the program */
int main(){
    readQRCode();
    return 0;
}