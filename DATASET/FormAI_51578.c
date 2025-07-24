//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LEN 1000

// function to count frequency of words
void countWords(char* str)
{
    int i, j, count;
    char words[MAX_STRING_LEN][MAX_STRING_LEN], temp[MAX_STRING_LEN];
    int len = strlen(str);
 
    // making each character lowercase
    for(i = 0; i < len; i++)
        str[i] = tolower(str[i]);
 
    i = 0;
    j = 0;
    count = 0;
 
    // storing each word in a 2D array
    while(*str != '\0')
    {
        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9'))
        {
            temp[j] = *str;
            j++;
        }
        else
        {
            temp[j] = '\0';
            j = 0;
            strcpy(words[i], temp);
            
            i++;
        }
        str++;
    }
    
    // counting the frequency of each word and printing it
    int n = i;
    for(i = 0; i < n; i++)
    {
        count = 1;
        for(j = i+1; j < n; j++)
        {
            if(strcmp(words[i], words[j]) == 0)
            {
                count++;
                // replacing the repeated words with empty string
                strcpy(words[j], "");
            }
        }
        // printing the word and its count
        if(strcmp(words[i], "") != 0)
        {
            printf("%s : %d\n", words[i], count);
        }
    }
}

int main()
{
    char str[MAX_STRING_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LEN, stdin);
 
    printf("\nFrequency of words in the entered string:\n");
    countWords(str);
    
    return 0;
}