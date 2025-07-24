//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char input[MAX_LENGTH];
    int sum = 0;
    int i = 0;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin); // Taking input from user

    while (input[i] != '\n') { // Loop until the end of the string
        sum += (int)input[i]; // Add the ASCII value of the current character to the sum
        i++;
    }

    int checksum = sum % 256; // Calculate the checksum by taking the modulo of the sum with 256

    printf("The checksum of the input string is: %d\n", checksum);

    return 0;
}