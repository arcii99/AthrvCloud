//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
/* Romeo's Binary Converter */

#include <stdio.h>
#include <string.h>

int main() {
    char binary[100];
    int decimal = 0, base = 1, length, index;
    
    printf("Oh Romeo, my dearest love,\n");
    printf("Let me take your heart to 2's compliment land.\n");
    printf("Please enter a binary number, my love: ");
    scanf("%s", binary);
    
    length = strlen(binary);
    for(index = length - 1; index >= 0; index--) {
        if(binary[index] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    
    printf("Oh Romeo, my love,\n");
    printf("The decimal representation of %s is: %d\n", binary, decimal);
    printf("Dispose of this code, my love,\n");
    printf("And let us live happily ever after.\n");

    return 0;
}