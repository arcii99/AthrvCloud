//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    int words = 0;
    int i = 0;
    int flag = 0;
    
    while(i < strlen(sentence))
    {
        // Check for spaces, tabs, or newlines - these indicate the end of a word
        if(sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n')
        {
            // If flag is set (i.e. we just finished a word), increment the word count
            if(flag == 1)
            {
                words++;
                flag = 0;
            }
        }
        else
        {
            // If the flag is not set (i.e. we're starting a new word), set the flag
            if(flag == 0)
            {
                flag = 1;
            }
        }
        
        i++;
    }
    
    // Handle the case where there is no space/tab/newline after the last word
    if(flag == 1)
    {
        words++;
    }
    
    printf("The sentence contains %d words.\n", words);
    
    return 0;
}