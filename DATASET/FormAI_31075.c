//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Surprise! You've stumbled upon a C Checksum Calculator.\n");
    printf("This program will calculate the checksum of any given string.\n\n");

    char string[100];
    int checksum = 0;

    printf("Please enter a string (max length 100 characters):\n");
    scanf("%s", string);

    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        checksum += (int) string[i]; // Convert current character to ASCII value and add to checksum
    }

    printf("\nThe checksum for the string '%s' is %d.\n", string, checksum);

    printf("\nAre you surprised by the result? I sure am!\n");

    return 0;
}