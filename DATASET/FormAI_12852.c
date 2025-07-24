//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h> /* Standard Input and Output Library */
#include <string.h> /* String Library */

int main(int argc, char *argv[]) /* Main Function */
{
    if (argc != 2) return 1; /* Return 1 if there is not exactly 1 argument */

    int len = strlen(argv[1]); /* Length of input string */

    int i; /* Declare counter variables */
    int j;
    int k;

    for (i = 0, j = len - 1; i < j; i++, j--) /* Loop through string forwards to backwards */
    {
        if (argv[1][i] != argv[1][j]) /* If characters are not equal, it's not a palindrome */
        {
            printf("\n ☹ - Given string is NOT a Palindrome!!!\n\n"); /* Print message and exit */
            return -1;
        }
    }

    printf("\n 😎 - Given string is a Palindrome!!!\n\n"); /* Print message and return */
    return 0;
}