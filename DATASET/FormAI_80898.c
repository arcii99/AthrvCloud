//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[100];
    int word_count = 1; //start with one since the first word has no space before it

    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin); //get the input from the user

    for(int i = 0; sentence[i] != '\0'; i++) //loop through the sentence string
    {
        if(sentence[i] == ' ') 
        {
            word_count++; //increment the count when a space is found
        }
    }

    printf("The sentence contains %d words.", word_count);

    return 0;
}