//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void decToHexRecursive(int num);

int main() {
    int decimalNum;
    
    printf("Enter a decimal number: ");
    scanf("%d",&decimalNum);
    
    printf("Hexadecimal Number: ");
    decToHexRecursive(decimalNum);
    
    return 0;
}

void decToHexRecursive(int num) {
    int rem = 0;
    rem = num % 16;

    if(num <= 0) {
        return;
    }
    decToHexRecursive(num/16);

    if(rem < 10) {
        printf("%d", rem);
    } else {
        printf("%c", rem - 10 + 'A');
    }
}