//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_LEN 1000

int count_words(char *text);

int main() 
{
    char input[MAX_LEN];
    
    printf("Enter some text: ");
    fgets(input, MAX_LEN, stdin);
    
    printf("Counting words...\n");
    count_words(input);
    
    return 0;
}

int count_words(char *text)
{
    int count = 0;
    char copy[MAX_LEN];
    char *word;
    strcpy(copy, text);
    
    word = strtok(copy, " \n\t");
    
    while(word != NULL) {
        count++;
        word = strtok(NULL, " \n\t");
    }
    
    printf("The text contains %d words.\n", count);
    return count;
}