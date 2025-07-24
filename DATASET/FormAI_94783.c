//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

// function prototype
void count_words(char *text, int *word_count, char *word_array[]);

int main() {
    
    char text[] = "This is a test sentence. Test is a repeated word. Repeated words are counted only once";
    int word_count[MAX_NUM_WORDS] = {0};
    char *word_array[MAX_NUM_WORDS];
    
    count_words(text, word_count, word_array);
    
    // print word frequency count
    printf("Word Frequency Count:\n");
    for(int i = 0; i < MAX_NUM_WORDS && word_array[i] != NULL; i++) {
        printf("%s : %d\n", word_array[i], word_count[i]);
    }
    
    return 0;
}

void count_words(char *text, int *word_count, char *word_array[]) {
    
    // initialize variables
    char current_word[MAX_WORD_LENGTH];
    int index = 0;
    int array_size = 1;
    int repeat = 0;
    
    // convert all characters to lowercase
    for(int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
    
    // tokenize text and count word frequency
    char *token = strtok(text, " ,.-\n\t\r");
    while(token != NULL) {
        strcpy(current_word, token);
        repeat = 0;
        for(int i = 0; i < array_size && word_array[i] != NULL; i++) {
            if(strcmp(word_array[i], current_word) == 0) {
                repeat = 1;
                word_count[i]++;
                break;
            }
        }
        if(!repeat) {
            word_array[index] = malloc(strlen(current_word) + 1);
            strcpy(word_array[index], current_word);
            word_count[index]++;
            index++;
            array_size++;
        }
        token = strtok(NULL, " ,.-\n\t\r");
    }
}