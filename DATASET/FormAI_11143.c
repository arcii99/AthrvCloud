//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
//
// Happy C Binary Converter
// By [Your Name], 2021
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[256];
    int num = 0;

    printf("Hello! Welcome to the Happy C Binary Converter!\n");
    printf("Please enter a positive integer: ");
    fgets(input, sizeof(input), stdin);
    num = atoi(input);

    printf("Here is the binary representation of %d: ", num);

    // get the binary representation of the number
    int binary[32] = {0};
    int i = 0;
    while (num != 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    // Print out the binary string
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\nThank you for using the Happy C Binary Converter!\n");

    return 0;
}