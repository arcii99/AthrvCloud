//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertToHex(int num);

int main() {
    int decimalNum;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    
    printf("The hexadecimal equivalent of %d is: ", decimalNum);
    convertToHex(decimalNum);
    
    return 0;
}

void convertToHex(int num) {
    char hexNum[17];
    int remainder, i = 0, j, temp;
    
    while (num != 0) {
        remainder = num % 16;
        
        if (remainder < 10) {
            hexNum[i++] = remainder + 48;
        } else {
            hexNum[i++] = remainder + 55;
        }
        
        num /= 16;
    }
    
    hexNum[i] = '\0';
    
    for (j = 0 ; j < i / 2 ; j++) {
        temp = hexNum[j];
        hexNum[j] = hexNum[i - j - 1];
        hexNum[i - j - 1] = temp;
    }
    
    printf("%s\n", hexNum);
}