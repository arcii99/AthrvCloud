//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to the peaceful C Checksum Calculator!\n");
    printf("Please enter the data to calculate the checksum for:\n");

    char input[100];
    scanf("%s", input);

    int checksum = 0;
    // Loop through each character and calculate the checksum
    for (int i = 0; input[i] != '\0'; i++) {
        checksum += input[i];
    }

    // Print the final checksum
    printf("The checksum for %s is %d.\n", input, checksum);

    return 0;
}