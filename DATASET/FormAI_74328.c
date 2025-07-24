//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hexToDec(char hex[]) {
    int i, j, sum = 0;
    int len = strlen(hex);
    for(i=len-1, j=0; i>=0; i--, j++) {
        if(hex[i]>=48 && hex[i]<=57) {
            sum += (hex[i]-48) * (1<<j*4);
        }
        else if(hex[i]>='A' && hex[i]<='F') {
            sum += (hex[i]-55) * (1<<j*4);
        }
        else if(hex[i]>='a' && hex[i]<='f') {
            sum += (hex[i]-87) * (1<<j*4);
        }
        else {
            printf("Invalid Hexadecimal Number!\n");
            exit(0);
        }
    }
    printf("Decimal Value of %s is: %d", hex, sum);
}

int main() {
    char hex[100];
    printf("Enter a Hexadecimal Number: ");
    scanf("%s", hex);
    hexToDec(hex);
    return 0;
}