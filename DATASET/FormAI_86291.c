//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define TOTAL_WORDS 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int typed_length;
    double time_taken;
} TypedWord;

int main() {
    char words[TOTAL_WORDS][MAX_WORD_LENGTH] = {"programming", "algorithm", "variable", "syntax", "compiler", 
        "debugging", "workspace", "function", "project", "array", "string", "operator", "pointer", "recursion", 
        "structure", "library", "conditional", "iteration", "data type", "declaration"};
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a list of %d words to type.\n", TOTAL_WORDS);
    printf("Press enter to start the test.\n");
    getchar();
    
    // Shuffle the order of words
    srand(time(0));
    for(int i = TOTAL_WORDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
    
    TypedWord typed_words[TOTAL_WORDS];
    int current_word_index = 0;
    clock_t start_time = clock();
    while(current_word_index < TOTAL_WORDS) {
        printf("\nType '%s': ", words[current_word_index]);
        TypedWord typed_word;
        fgets(typed_word.word, MAX_WORD_LENGTH, stdin);
        typed_word.typed_length = strlen(typed_word.word) - 1;
        if(typed_word.word[typed_word.typed_length - 1] == '\r' || typed_word.word[typed_word.typed_length - 1] == '\n') {
            typed_word.word[typed_word.typed_length - 1] = '\0';
            typed_word.typed_length--;
        } else {
            typed_word.word[typed_word.typed_length] = '\0';
        }
        clock_t end_time = clock();
        typed_word.time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        typed_words[current_word_index] = typed_word;
        current_word_index++;
    }
    
    printf("\n\nTest complete!\n");
    printf("Here are your results:\n\n");
    printf("Word\t\tTyped\tTime taken\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < TOTAL_WORDS; i++) {
        printf("%s\t\t%d\t%.2f\n", words[i], typed_words[i].typed_length, typed_words[i].time_taken);
    }
    
    return 0;
}