//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1024

void hashString(char *string, int length);

int main(void)
{
    char input[MAX_CHARS];
    int inputLength;

    printf("Welcome to the Medieval Cryptographic Hash Function!");

    printf("\nPlease enter a string to hash: ");
    fgets(input, MAX_CHARS, stdin);

    inputLength = strlen(input);
    if (inputLength > 0 && input[inputLength - 1] == '\n') // remove the newline character
    {
        input[inputLength - 1] = '\0';
        inputLength--;
    }

    hashString(input, inputLength);

    return 0;
}

void hashString(char *string, int length)
{
    int i, hash = 0;
    char hashString[length + 1];

    for (i = 0; i < length; i++)
    {
        hash += (int)string[i] * i;
    }

    // convert the hash to a string and append a medieval touch to it
    sprintf(hashString, "%d", hash);
    strcat(hashString, "_ForKingAndCountry");

    printf("\n\nThe hashed string is: %s", hashString);
}