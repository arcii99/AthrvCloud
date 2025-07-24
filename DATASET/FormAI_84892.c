//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct WordFrequency {
    char* word;
    int frequency;
};

void print_count(struct WordFrequency* count, int num) {
    printf("\nWord Count:\n");
    for(int i=0; i<num; i++) {
        printf("%s: %d\n", count[i].word, count[i].frequency);
    }
}

void add_word(struct WordFrequency* count, int* num, char* word) {
    for(int i=0, n=*num; i<n; i++) {
        if(strcmp(count[i].word, word)==0) {
            count[i].frequency++;
            return;
        }
    }
    *num += 1;
    count = realloc(count, *num * sizeof(struct WordFrequency));
    if(count == NULL) {
        printf("Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    count[*num - 1].word = malloc((strlen(word)+1) * sizeof(char));
    if(count[*num - 1].word == NULL) {
        printf("Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(count[*num - 1].word, word);
    count[*num - 1].frequency = 1;
}

int main() {
    char input[1000];
    printf("Enter text to count word frequencies:\n");
    fgets(input, 1000, stdin);
    struct WordFrequency* count = NULL;
    int num = 0;
    char* word = strtok(input, " ,.?!:;\n");
    while(word != NULL) {
        for(int i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        add_word(count, &num, word);
        word = strtok(NULL, " ,.?!:;\n");
    }
    print_count(count, num);
    for(int i=0; i<num; i++) {
        free(count[i].word);
    }
    free(count);
    return 0;
}