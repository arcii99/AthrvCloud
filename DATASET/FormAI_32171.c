//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 1000

int main(){
    char text[MAX_CHARS];
    int wordCount = 0;
    char* word;
    printf("Welcome to the Unique C Word Count Tool\n\n");
    printf("Enter your text: ");

    fgets(text, MAX_CHARS, stdin);

    // make a duplicate text buffer to modify
    char duplicate[MAX_CHARS];
    strcpy(duplicate, text);

    // tokenize the text to count unique words
    word = strtok(text, " ,.!?;\n");

    // put all unique words in a separate array
    char unique_words[MAX_CHARS][MAX_CHARS];
    char* temp;
    int unique_word_count = 0;

    while(word != NULL){
        int is_unique = 1;
        for(int i = 0; i < unique_word_count; i++){
            if(strcmp(unique_words[i], word) == 0){
                is_unique = 0;
                break;
            }
        }
        if(is_unique){
            strcpy(unique_words[unique_word_count], word);
            unique_word_count++;
        }

        word = strtok(NULL, " ,.!?;\n");
    }

    printf("\nUnique Words:\n");

    for(int i = 0; i < unique_word_count; i++){
        printf("%s\n", unique_words[i]);
    }

    // print each unique word's count
    printf("\nWord Count:\n");

    word = strtok(duplicate, " ,.!?;\n");

    while(word != NULL){
        int count = 0;
        for(int i = 0; i < unique_word_count; i++){
            if(strcmp(unique_words[i], word) == 0){
                count++;
            }
        }
        printf("%s: %d\n", word, count);
        word = strtok(NULL, " ,.!?;\n");
        wordCount++;
    }

    printf("\nTotal word count: %d\n", wordCount);
    
    return 0;
}