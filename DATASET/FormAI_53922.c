//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1024]; // Maximum 1024 length
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
    int len = strlen(text);

    // Removing leading and trailing spaces
    while(text[0] == ' ')
    {
        for(int i = 0; i < len; i++)
        {
            text[i] = text[i+1];
        }
        len--;
    }
    while(text[len-1] == ' ')
    {
        text[len-1] = '\0';
        len--;
    }

    // Counting words and sentences
    int word_count = 0;
    int sentence_count = 0;
    for(int i = 0; i < len; i++)
    {
        if(text[i] == ' ')
        {
            word_count++;
        }
        else if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    }
    word_count++; // Last word is not counted in loop
    sentence_count++;

    // Printing results
    printf("\nProcessed text:\n%s\n\n", text);
    printf("Word count: %d\n", word_count);
    printf("Sentence count: %d\n", sentence_count);

    return 0;
}