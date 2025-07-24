//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int count = 0;
    
    printf("Enter a sentence: ");

    // read user input and remove trailing newline
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strlen(sentence)-1] = '\0';

    // loop through each character in the sentence
    for(int i=0; sentence[i]!='\0'; i++)
    {
        // if we find a space, increment the counter
        if(sentence[i] == ' ')
        {
            count++;
        }
    }

    // add one to the counter to account for the last word
    count++;

    // display the result
    printf("Word Count: %d\n", count);

    return 0;
}