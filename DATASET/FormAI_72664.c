//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int count = 0, i = 0, flag = 0;

    // Ask for user input
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // loop through every character in the input string
    while (input[i] != '\0')
    {

        // check for word boundary
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
        {
            flag = 0;
        }
        else
        {
            // check for first character of a new word
            if (flag == 0)
            {
                flag = 1;
                count++;
            }
        }
        
        i++;
    }

    // print the word count
    printf("Word count: %d", count);

    return 0;
}