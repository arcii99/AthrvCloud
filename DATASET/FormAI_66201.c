//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool checkQRCode(char *code) {
    const int CODE_LENGTH = 15;
    const char CODE_START = 'C';
    const char CODE_END = 'R';
    const char VALID_CHARACTERS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%*";
    
    if (strlen(code) != CODE_LENGTH) {
        return false;
    }
    
    if (code[0] != CODE_START || code[CODE_LENGTH-1] != CODE_END) {
        return false;
    }
    
    for (int i = 1; i < CODE_LENGTH-1; i++) {
        char c = code[i];
        if (strchr(VALID_CHARACTERS, c) == NULL) {
            return false;
        }
    }
    
    return true;
}


void readQRCode(char *code) {
    const int MAX_CODE_LENGTH = 50;
    
    printf("Please scan your C-QR code:\n");
    fgets(code, MAX_CODE_LENGTH, stdin);
    code[strcspn(code, "\n")] = 0;
}


int main() {
    char code[50];
    
    readQRCode(code);
    
    if (checkQRCode(code)) {
        printf("This is a valid C-QR code!\n");
    }
    else {
        printf("This is not a valid C-QR code.\n");
    }
    
    return 0;
}