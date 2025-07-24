//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main()
{
    printf("Welcome to the C Word Frequency Counter!\n");

    char text[10000];
    printf("Please enter the text you want to analyze: ");
    fgets(text, sizeof(text), stdin);

    //convert text to lowercase
    for(int i = 0; text[i]; i++){
        text[i] = tolower(text[i]);
    }

    char *words[MAX_WORDS]; //an array of pointers to char
    int freq[MAX_WORDS] = {0}; //initialize all elements to 0

    //tokenize the text
    int count = 0;
    char *token = strtok(text, " \n\t.,;:\"'()[]{}-?!"); //delimiters: space, newline, tab, punctuation
    while(token != NULL){
        words[count] = token;
        count++;
        token = strtok(NULL, " \n\t.,;:\"'()[]{}-?!");
    }

    //count the frequency of each word
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(strcmp(words[i], words[j]) == 0){
                freq[i]++;
            }
        }
    }

    //print the result
    printf("Word\tFrequency\n");
    for(int i = 0; i < count; i++){
        if(freq[i] != -1){
            printf("%s\t%d\n", words[i], freq[i]);
            //set frequency to -1 so that we don't count it again
            freq[i] = -1;
        }
    }

    printf("Thank you for using the C Word Frequency Counter.\n");
    return 0;
}