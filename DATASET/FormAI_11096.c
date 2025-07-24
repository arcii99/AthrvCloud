//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LEN 50

void tokenize(char* input, char tokens[MAX_WORDS][MAX_LEN]) {
    char* token = strtok(input, " .,;:\n");
    int i = 0;
    while(token != NULL) {
        strncpy(tokens[i], token, MAX_LEN);
        token = strtok(NULL, " .,;:\n");
        i++;
    }
}

int spell_check(char* word, char dictionary[MAX_WORDS][MAX_LEN], int num_words) {
    int i;
    for(i = 0; i < num_words; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE* fp = fopen("dictionary.txt", "r");
    if(fp == NULL) {
        printf("ERROR: Dictionary file not found\n");
        exit(1);
    }

    printf("Reading dictionary...\n");

    char dictionary[MAX_WORDS][MAX_LEN];
    int num_words = 0;

    char line[MAX_LEN];
    while(fgets(line, MAX_LEN, fp)) {
        line[strcspn(line, "\n")] = 0; // remove trailing newline
        strncpy(dictionary[num_words], line, MAX_LEN);
        num_words++;
    }

    fclose(fp);

    printf("Dictionary loaded. Enter text to spell check:\n");

    char input[10000];
    fgets(input, 10000, stdin);

    char tokens[MAX_WORDS][MAX_LEN];
    tokenize(input, tokens);

    printf("Misspelled words:\n");

    int i;
    for(i = 0; i < MAX_WORDS; i++) {
        if(tokens[i][0] == '\0') {
            break; // end of token list
        }
        
        if(!spell_check(tokens[i], dictionary, num_words)) {
            printf("%s\n", tokens[i]);
        }
    }

    return 0;
}