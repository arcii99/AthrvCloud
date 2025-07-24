//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This is a compression algorithm that utilizes run-length encoding to compress a string. 
 * Whenever a sequence of the same character occurs repeatedly in the string, it is shortened 
 * to the character itself along with a count of how many times it occurs in a row. For example,
 * aaaaa becomes a5.
 */

int main()
{
    char input[100]; // assuming input string will be no greater than 100 characters
    printf("Enter a string to compress:\n");
    fgets(input, sizeof input, stdin); // get user input up to 100 characters
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    int count = 1; // count of characters in a sequence   
    char cur = input[0]; // current character being tracked
    int i;
    for (i = 1; i < strlen(input); i++)
    {
        if (input[i] == cur) // continuing sequence
        {
            count++;
        }
        else // sequence ended
        {
            printf("%c%d", cur, count); // print compressed sequence
            cur = input[i]; // set new character
            count = 1; // reset count
        }
    }
    printf("%c%d\n", cur, count); // print last sequence
    return 0;
}