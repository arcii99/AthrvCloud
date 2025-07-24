//FormAI DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); //get input from user

    int wordCount = 0;

    char* token;
    token = strtok(sentence, " "); //split sentence into words using spaces as delimiters

    while(token != NULL){
        wordCount++;
        token = strtok(NULL, " ");
    }

    printf("The number of words in the sentence is: %d\n", wordCount);

    return 0;
}