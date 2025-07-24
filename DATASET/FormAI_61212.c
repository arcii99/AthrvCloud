//FormAI DATASET v1.0 Category: Spell checking ; Style: curious
#include<stdio.h>
#include<string.h>
#define MAX_STRING_SIZE 1000

int check_spelling_errors(char *word, char *dict[], int dict_size);

int main(){

    char dict[5][20] = {"apple", "banana", "carrot", "durian", "eggplant"};
    char sentence[MAX_STRING_SIZE];

    printf("Curious Spell Checker version 1.0\n");
    printf("Please enter a sentence to check spelling errors:\n");
    fgets(sentence, MAX_STRING_SIZE, stdin);

    char *token = strtok(sentence, " ,.*\n");
    int spelling_errors = 0;

    printf("\nChecking spelling errors...\n");

    while (token != NULL) {

        if (check_spelling_errors(token, dict, 5) == 0 ){
            printf("%s is spelled correctly.\n", token);
        }
        else {
            printf("%s is misspelled.\n", token);
            spelling_errors++;
        }

        token = strtok(NULL, " ,.*\n");
    }

    printf("\nSpell checking complete. %d spelling errors found.\n", spelling_errors);

    return 0;
}

int check_spelling_errors(char *word, char *dict[], int dict_size){

    int i;

    for(i = 0; i < dict_size; i++){
        if (strcmp(word, dict[i]) == 0){
            return 0;
        }
    }

    return 1;
}