//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include<stdio.h>
#include<string.h>

int main(){
    char input[1000];
    char* word;
    int wordCount = 1;
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    word = strtok(input, " ");

    while(word != NULL){
        wordCount++;
        word = strtok(NULL, " ");
    }

    printf("Number of words in the sentence: %d\n", wordCount);

    return 0;
}