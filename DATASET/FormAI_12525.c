//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[100];
    int count = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    for(int i=0; i<strlen(sentence); i++)
    {
        if(sentence[i] == ' ')
        {
            count++;
        }
    }
    
    printf("The number of words in the sentence is: %d", count+1);
    
    return 0; 
}