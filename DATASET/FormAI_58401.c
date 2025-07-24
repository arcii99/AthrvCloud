//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

int main()
{
    char input[MAX_LEN] = {0};
    printf("Welcome to the Cat Language Translator!\n");
    printf("Please enter a sentence in Cat Language: ");
    fgets(input, MAX_LEN, stdin);
    int len = strlen(input);
    if (input[len-1] == '\n')
    {
        input[len-1] = '\0';
        len--;
    }
    printf("You entered: %s\n", input);
    
    // Check if the input sentence ends with meow or not.
    char *last_four = &input[len-4];
    if (strcmp(last_four, "meow") == 0)
    {
        printf("Translated output: ");
        // Remove the last four letters from the input sentence.
        input[len-4] = '\0';
        len -= 4;
        for (int i = 0; i < len; i++)
        {
            if (input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o' && input[i+3] == 'w')
            {
                printf(" ");
                i += 3;
            }
            else
            {
                printf("%c", input[i]);
            }
        }
        printf(" says meow.\n");
    }
    else
    {
        printf("Error: Input sentence does not end with meow.\n");
    }
    return 0;
}