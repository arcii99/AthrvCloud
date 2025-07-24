//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: calm
#include <stdio.h>

// Function to calculate checksum of a given string
int calc_checksum(char *str)
{
    int i, sum = 0;

    // Iterate over each character in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        sum += str[i]; // Add the ASCII value of the character to the sum
    }

    return sum % 256; // Calculate and return the checksum
}

// Main function
int main(void)
{
    char str[50];

    // Prompt the user to enter a string
    printf("Enter a string to calculate checksum: ");
    scanf("%s", str);

    // Calculate the checksum of the string
    int checksum = calc_checksum(str);

    // Print the checksum
    printf("Checksum of the given string is %d.\n", checksum);

    return 0;
}