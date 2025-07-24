//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int dictionary_size = 0;
char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH];

int load_dictionary(char *dict_file) {
    FILE *fp = fopen(dict_file, "r");
    if(fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        return 0;
    }

    char buffer[MAX_WORD_LENGTH];
    while(fgets(buffer, MAX_WORD_LENGTH, fp)) {
        strcpy(dictionary[dictionary_size++], buffer);
    }
    fclose(fp);
    return 1;
}

int check_spelling(char *word) {
    int i;
    for(i = 0; i < dictionary_size; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char dict_file[] = "dictionary.txt";
    if(!load_dictionary(dict_file)) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a word to check spelling:\n");
    scanf("%s", input);

    if(check_spelling(input)) {
        printf("%s is spelled correctly.\n", input);
    } else {
        printf("%s is spelled incorrectly.\n", input);
    }

    return 0;
}