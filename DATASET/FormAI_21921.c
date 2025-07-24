//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>

// function to convert decimal to binary
void dec2bin(int num) {
    int binary_num[32];
    int i = 0;
    
    while(num > 0) {
        binary_num[i] = num % 2;
        num = num / 2;
        i++;
    }
    
    // print the binary number
    printf("Binary Number: ");
    
    for(int j=i-1; j>=0; j--) {
        printf("%d", binary_num[j]);
    }
}

// function to convert binary to decimal
void bin2dec(int num) {
    int decimal_num = 0;
    int base = 1;
    int temp = num;
    
    while(temp > 0) {
        int last_digit = temp % 10;
        temp = temp / 10;
        decimal_num += last_digit * base;
        base = base * 2;
    }
    
    // print the decimal number
    printf("Decimal Number: %d", decimal_num);
}

int main() {
    int choice, num;
    
    // menu
    printf("Binary Converter:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the number to convert: ");
    scanf("%d", &num);
    
    switch(choice) {
        case 1:
            dec2bin(num);
            break;
        
        case 2:
            bin2dec(num);
            break;
        
        default:
            printf("Invalid choice.");
            break;
    }
    
    return 0;
}