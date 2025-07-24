//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    // Romeo: Oh Juliet, my love for you is like a binary number.
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);

    // Juliet: Oh Romeo, I don't understand binary. What do you mean?
    printf("The binary representation of %d is: ", decimal);

    // Romeo: Well my love, it's like this.
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // Juliet: Wait, what are those numbers?
    // Romeo: They are each a 0 or 1, representing a digit in binary.
    
    int j;
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    
    // Juliet: Oh, I see now. That's quite clever, my love.
    // Romeo: Anything for you, my sweet Juliet.

    return 0;
}