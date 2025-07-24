//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_string[100];
    printf("Enter a string: ");
    fgets(input_string, 100, stdin);
    // fgets reads input from user with maximum input size of 100 characters

    int word_count = 1;
    int length = strlen(input_string);
    for(int i = 0; i < length; i++)
    {
        if(input_string[i] == ' ' || input_string[i] == '\n' || input_string[i] == '\t')
        {
            word_count++;
        }
    }
    // loop through the input string and increment word count when space, new line, or tab is found

    printf("Word count: %d\n", word_count);

    return 0;
}