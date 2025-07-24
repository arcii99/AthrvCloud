//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to check if input character is valid
int isValidChar(char c)
{
    if ((c >= 'a' && c <= 'k') || (c >= 'A' && c <= 'K') || c == ' ')
    {
        return 1;
    }
    return 0;
}

// Function to translate the input string
void translate(char *input)
{
    int len = strlen(input);
    char output[len];
    memset(output, 0, len);
    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (isValidChar(input[i]))
        {
            if (input[i] == ' ')
            {
                output[j++] = input[i];
            }
            else
            {
                output[j++] = 'm' - (input[i] - 'a');
            }
        }
        else
        {
            printf("Invalid character: %c\n", input[i]);
            return;
        }
    }
    printf("Translated string: %s\n", output);
}

int main()
{
    char input[100];
    printf("Enter a string to translate: ");
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline character from input string
    input[strcspn(input, "\n")] = 0;
    translate(input);
    return 0;
}