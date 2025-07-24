//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORDS 1000
#define WORDLEN 20

char words[MAXWORDS][WORDLEN];
int nwords = 0;
int counter = 0;

void addWord(char* word) {
    if(nwords == MAXWORDS) {
        printf("Sorry, Dictionary is full\n");
        return;
    }

    strcpy(words[nwords], word);
    nwords++;
}

int check(char* word) {
    for(int i = 0; i < nwords; i++) {
        if(strcmp(words[i], word) == 0) {
            return 1;
        }
    }
    addWord(word);
    return 0;
}

void cleanup(char* page) {
    counter = 0;
    int length = strlen(page);
    for(int i = 0; i < length; i++) {
        if(isalpha(page[i])) {
            page[counter++] = tolower(page[i]);
        } else {
            page[counter++] = ' ';
        }
    }
    page[counter] = '\0';
}

void parse(char* page) {
    char* word = strtok(page, " ");
    while(word) {
        check(word);
        word = strtok(NULL, " ");
    }
}

int main() {
    printf("WELCOME TO SPELL CHECKER\n\n");
    printf("Enter the text to be spell-checked:\n");

    char page[MAXWORDS*WORDLEN];
    fgets(page, MAXWORDS*WORDLEN, stdin);
    cleanup(page);
    parse(page);

    printf("\nNumber of words in dictionary: %d\n", nwords);
    printf("\nWORDS:\n");
    for(int i = 0; i < nwords; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}