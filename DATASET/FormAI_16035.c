//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include<stdio.h>
#include<string.h>

// function to check valid hexadecimal number
int isHex(char hex[]) {
    int len = strlen(hex);
    for(int i=0; i<len; i++) {
        if((hex[i]>='0' && hex[i]<='9') || (hex[i]>='a' && hex[i]<='f') || (hex[i]>='A' && hex[i]<='F')) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

// function to convert hexadecimal string to decimal value
int hexToDec(char hex[]) {
    int len = strlen(hex), base=1, dec=0;
    for(int i=len-1; i>=0; i--) {
        if(hex[i]>='0' && hex[i]<='9') {
            dec += (hex[i] - 48) * base;
        } else if(hex[i]>='a' && hex[i]<='f') {
            dec += (hex[i] - 87) * base;
        } else if(hex[i]>='A' && hex[i]<='F') {
            dec += (hex[i] - 55) * base;
        }
        base *= 16; // multiply base by 16
    }
    return dec;
}

// main function
int main() {
    char hex[20];
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);
    if(isHex(hex)) { // check if valid hexadecimal number
        int red = hexToDec(strncpy(hex, hex+1, 2)); // convert first two characters to decimal
        int green = hexToDec(strncpy(hex, hex+3, 2)); // convert next two characters to decimal
        int blue = hexToDec(strncpy(hex, hex+5, 2)); // convert last two characters to decimal
        printf("RGB Color Code: %d, %d, %d", red, green, blue);
    } else {
        printf("Invalid hexadecimal color code!");
    }
    return 0;
}