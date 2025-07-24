//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

void check_spelling(char *word, char dictionary[][MAX_WORD_LENGTH], int num_words);
void strip_punct(char *word);
void to_lower(char *word);


int main(){
    char dict[MAX_WORDS][MAX_WORD_LENGTH];
    int dict_len = 0;

    FILE *fp = fopen("dictionary.txt", "r");

    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];

    while(fgets(buffer, MAX_WORD_LENGTH, fp)){
        strip_punct(buffer);
        to_lower(buffer);
        strncpy(dict[dict_len], buffer, MAX_WORD_LENGTH);

        dict_len++;
    }

    fclose(fp);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LENGTH, stdin);
    strip_punct(word);
    to_lower(word);

    check_spelling(word, dict, dict_len);

    return 0;
}

void check_spelling(char *word, char dictionary[][MAX_WORD_LENGTH], int num_words){
    for(int i = 0; i < num_words; i++){
        if(strcmp(word, dictionary[i]) == 0){
            printf("%s is spelled correctly.", word);
            return;
        }
    }

    printf("%s is misspelled.", word);
}

void strip_punct(char *word){
    int i, j;
    for(i = 0, j = 0; i < strlen(word); i++){
        if(isalpha(word[i])){
            word[j] = word[i];
            j++;
        }
    }
    word[j] = '\0';
}

void to_lower(char *word){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
}