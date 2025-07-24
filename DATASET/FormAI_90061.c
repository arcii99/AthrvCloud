//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    // remove newline character at the end of the input
    input[strcspn(input, "\n")] = 0;

    printf("Processed sentence: ");

    int length = strlen(input);
    int is_word = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (input[i] == ' ')
        {
            is_word = 0;
        }
        else if (is_word == 0)
        {
            is_word = 1;
            printf("%c", input[i]);
        }
    }

    return 0;
}