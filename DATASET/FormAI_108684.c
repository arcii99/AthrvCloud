//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Checksum Calculator!\n");
    printf("Enter a series of numbers to calculate the checksum:\n");

    // read in the input string
    char input[1024];
    fgets(input, 1024, stdin);

    // initialize the checksum to 0
    int checksum = 0;

    // loop over the input string, adding up the ASCII values of each character
    for (int i = 0; input[i] != '\0'; i++) {
        checksum += (int) input[i];
    }

    // take the two's complement of the checksum to get the final checksum value
    checksum = ~checksum + 1;

    printf("The checksum of the input is: %d\n", checksum);

    return 0;
}