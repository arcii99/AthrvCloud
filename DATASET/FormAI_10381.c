//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function to convert decimal number to binary
void decimalToBinary(int num) {
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("\nBinary number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// function to convert binary number to decimal number
void binaryToDecimal(int num) {
    int decimalNum = 0, base = 1, rem;
    while (num > 0) {
        rem = num % 10;
        decimalNum += rem * base;
        num /= 10;
        base *= 2;
    }
    printf("\nDecimal number: %d", decimalNum);
}

int main() {
    char choice;
    int num;
    do {
        printf("Enter 'b' to convert binary to decimal or 'd' to convert decimal to binary: ");
        scanf("%c", &choice);
        choice = tolower(choice);
        switch (choice) {
            case 'b':
                printf("\nEnter binary number: ");
                scanf("%d", &num);
                binaryToDecimal(num);
                break;
            case 'd':
                printf("\nEnter decimal number: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
        printf("\n\nDo you want to continue(y/n): ");
        getchar();  // clear input buffer
        scanf("%c", &choice);
        choice = tolower(choice);
    } while (choice == 'y');
    return 0;
}