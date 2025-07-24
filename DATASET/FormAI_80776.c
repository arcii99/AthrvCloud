//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main()
{
    char input[MAX_INPUT_SIZE];
    int input_len = 0;

    printf("Enter the text to process: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    input_len = strlen(input);

    for (int i = 0; i < input_len; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= '0' && input[i] <= '9'))
        {
            continue;
        }
        else
        {
            input[i] = '%';
        }
    }

    printf("Processed text: %s\n", input);

    return 0;
}