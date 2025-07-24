//FormAI DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binary[100];
    int decimal = 0, place = 1;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    for(int i = strlen(binary) - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            decimal = decimal + place;
        }
        place = place * 2;
    }

    printf("The decimal equivalent of %s is %d\n", binary, decimal);
    return 0;
}