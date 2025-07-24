//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_SIZE 1000

int count_words(char input[], char search_word[]){
    int word_count = 0;
    char *token; 

    token = strtok(input, " "); 

    while (token != NULL) {
        if (strcmp(token, search_word) == 0) {
            word_count++;
        }
        token = strtok(NULL, " ");
    }

    return word_count;
}

int main(){
    char input[MAX_INPUT_SIZE];
    char search_word[MAX_INPUT_SIZE];

    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    printf("Enter the search word: ");
    fgets(search_word, MAX_INPUT_SIZE, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';
    search_word[strcspn(search_word, "\n")] = '\0';

    int word_count = count_words(input, search_word);

    printf("The word count for '%s' in '%s' is: %d\n", search_word, input, word_count);

    return 0;

}