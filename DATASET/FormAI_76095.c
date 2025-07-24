//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include<stdio.h>
#include<string.h>
#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORD_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int frequencies[MAX_WORDS] = {0};
    
    printf("Enter some text: ");
    fgets(text, MAX_WORD_LEN, stdin);
    
    char *word = strtok(text, " \n\r\t");
    int num_words = 0;
    while(word != NULL && num_words < MAX_WORDS)
    {
        strcpy(words[num_words++], word);
        word = strtok(NULL, " \n\r\t");
    }
    
    for(int i = 0; i < num_words; i++)
    {
        char *temp_word = words[i];
        int freq = 0;
        for(int j = i; j < num_words; j++)
        {
            if(strcmp(temp_word, words[j]) == 0)
            {
                freq++;
                frequencies[j] = -1; // set to -1 to avoid recounting
            }
        }
        if(frequencies[i] != -1)
        {
            frequencies[i] = freq; // save frequency count for current word
        }
    }
    
    printf("Word\tFrequency\n");
    for(int i = 0; i < num_words; i++)
    {
        if(frequencies[i] != -1)
        {
            printf("%s\t%d\n", words[i], frequencies[i]);
        }
    }
    
    return 0;
}