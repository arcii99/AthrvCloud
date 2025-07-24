//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[1000];
    int word_count = 0, i;

    printf("Welcome to the Happy C Word Count Tool!\n");
    printf("Type in your text (max 1000 characters):\n");
    fgets(text, 1000, stdin);

    // Counting words in the text
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]) && !isspace(text[i+1]))
        {
            word_count++;
        }
    }
    // If the last character is not space, add one more word
    if (!isspace(text[i-1]))
    {
        word_count++;
    }

    printf("\n------------------------------------------------\n");
    printf("Your happy text: \n%s\n", text);
    printf("The word count is: %d\n", word_count);
    printf("Thank you for using the Happy C Word Count Tool!\n");
    printf("Have a nice day!\n");
    
    return 0;
}