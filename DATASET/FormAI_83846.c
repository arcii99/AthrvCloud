//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>

/**
 * Function to calculate the C checksum of a given string
 * @param s The input string
 * @return The C checksum value
 */
int calculate_checksum(char *s)
{
    int checksum = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        checksum += s[i];
    }

    return (-checksum);
}

int main()
{
    char input[100]; // assuming that the input string won't be longer than 100 characters
    int checksum;

    printf("Please enter a string: ");
    scanf("%s", input);

    checksum = calculate_checksum(input);

    printf("The C checksum of '%s' is %d.\n", input, checksum);

    return 0;
}