//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function to check if character is a letter or not
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//function to check if the word is spelled correctly or not
int checkSpelling(char *word) {
    //add more words to this list to increase the dictionary size
    char *dictionary[] = {"apple", "banana", "cherry", "grape", "orange", "mango", "pear", "pineapple", "watermelon", "kiwi"};
    int length = sizeof(dictionary) / sizeof(dictionary[0]);

    //convert the word to lowercase for case-insensitive comparison
    int i;
    for(i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    //check if the word is in the dictionary
    for(i = 0; i < length; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char input[100];
    printf("Enter a sentence to check spelling:\n");
    fgets(input, 100, stdin);

    char *word = strtok(input, " ");
    printf("Incorrectly spelled words:");

    //iterate through the words in the sentence
    while(word != NULL) {
        //remove punctuation marks from the word
        int len = strlen(word);
        int i;
        for(i = 0; i < len; i++) {
            if(!isLetter(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        //check if the word is spelled correctly
        if(strlen(word) > 0 && !checkSpelling(word)) {
            printf(" %s", word);
        }

        word = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}