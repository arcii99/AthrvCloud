//FormAI DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long decimal, binary = 0, remainder, base = 1;
    int option;

    printf("Welcome! What would you like to do?\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%lld", &decimal);

            while (decimal > 0) {
                remainder = decimal % 2;
                binary = binary + remainder * base;
                decimal = decimal / 2;
                base = base * 10;
            }

            printf("The binary number is: %lld\n", binary);
            break;

        case 2:
            printf("Enter binary number: ");
            scanf("%lld", &binary);

            while (binary > 0) {
                remainder = binary % 10;
                decimal = decimal + remainder * pow(2, base);
                binary = binary / 10;
                base++;
            }

            printf("The decimal number is: %lld\n", decimal);
            break;

        default:
            printf("Invalid option selected\n");
            break;
    }

    return 0;
}