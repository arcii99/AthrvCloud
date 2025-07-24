//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a character is a punctuation symbol
int isPunctuation(char c) {
    if(c == '.' || c == ',' || c == ':' || c == ';' || c == '?' || c == '!') {
        return 1;
    } else {
        return 0;
    }
}

// function to strip punctuation from a given word
void stripPunctuation(char *word) {
    int i = 0, j = 0;
    while(word[i]) {
        if(!isPunctuation(word[i])) {
            word[j++] = word[i];
        }
        i++;
    }
    word[j] = '\0';
}

// function to convert a given word to lowercase
void toLowercase(char *word) {
    for(int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// function to check if a given word is correct or not
int checkSpelling(char *word, char **dict, int dictSize) {
    stripPunctuation(word);
    toLowercase(word);
    for(int i = 0; i < dictSize; i++) {
        if(strcmp(dict[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *dictionary[] = {"hello", "world", "this", "is", "a", "spell", "checking", "program"};
    int dictSize = sizeof(dictionary)/sizeof(dictionary[0]);

    char input[100]; // max input size is limited to 99 characters
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    char *word = strtok(input, " ");
    while(word) {
        if(!checkSpelling(word, dictionary, dictSize)) {
            printf("'%s' is spelled incorrectly\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}