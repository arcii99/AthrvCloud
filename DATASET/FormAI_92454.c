//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[17];
    long decimal, place;
    int i = 0, digit;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex); 
    decimal = 0;
    place = 1;
    for(i = 0; hex[i] != '\0'; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        }
        decimal += digit * place;
        place *= 16;
    }
    printf("The decimal equivalent is: %ld\n", decimal);
    return EXIT_SUCCESS;
}