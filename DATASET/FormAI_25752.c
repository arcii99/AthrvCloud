//FormAI DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

void check_spelling(char*, char*);

int main() {
    char word[MAX_WORD_SIZE];
    char dictionary[MAX_WORD_SIZE];
    
    printf("Enter a word: ");
    fgets(word, MAX_WORD_SIZE, stdin);
    
    strtok(word, "\n");
    check_spelling(word, dictionary);
}

void check_spelling(char *word, char *dictionary) {
    int found = 0;
    FILE *file = fopen("dictionary.txt", "r");  // open the dictionary file
    if (file) {
        while (!feof(file)) {
            fgets(dictionary, MAX_WORD_SIZE, file); // read a word from the dictionary
            strtok(dictionary, "\n");
            
            if (strcasecmp(word, dictionary) == 0) {  // case-insensitive match
                printf("%s is spelled correctly!\n", word);
                found = 1;
                break;
            }
        }
        fclose(file);  // close the dictionary file
    }
    if (!found) {
        printf("%s is spelled incorrectly!\n", word);
    }
}