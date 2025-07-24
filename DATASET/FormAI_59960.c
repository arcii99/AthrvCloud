//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int len, i, count = 0;

    printf("Enter a string: ");
    fgets(input, 1000, stdin); // read input string including spaces

    len = strlen(input);

    // Iterate through input string
    for (i = 0; i < len; i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            // Found a word boundary - increment count
            count++;
        }
    }

    printf("The input string contains %d words.\n", count);

    return 0;
}