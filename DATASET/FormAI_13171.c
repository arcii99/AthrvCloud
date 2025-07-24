//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void getTranslation(char [], char []);
void translateWord(char [], char []);
void printResult(char []);

int main() {
    char input[1000];
    char output[1000] = "";

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a sentence to translate: ");
    fgets(input, 1000, stdin);

    getTranslation(input, output);
    printResult(output);

    return 0;
}

// Function to build translated sentence
void getTranslation(char sentence[], char translated[]) {
    char temp[100];
    char delimiter[] = " \n\t!?,.";
    char *s;

    s = strtok(sentence, delimiter);

    while (s != NULL) {
        translateWord(s, temp);
        strcat(temp, " ");
        strcat(translated, temp);
        s = strtok(NULL, delimiter);
    }
}

// Function to translate a single word
void translateWord(char word[], char translated[]) {
    char c = word[0];
    int i, len;
    len = strlen(word);
    char newword[len + 1];

    if (c == 'c' || c == 'C') {
        // Replace 'c' with 'meow'
        strcpy(newword, "meow");
        for (i = 1; i < len; i++) {
            newword[i + 3] = word[i];
        }
        newword[len + 3] = '\0';
    } else if (c == 'a' || c == 'A') {
        // Replace 'a' with 'purr'
        strcpy(newword, "purr");
        for (i = 1; i < len; i++) {
            newword[i + 3] = word[i];
        }
        newword[len + 3] = '\0';
    } else if (c == 't' || c == 'T') {
        // Replace 't' with 'hiss'
        strcpy(newword, "hiss");
        for (i = 1; i < len; i++) {
            newword[i + 3] = word[i];
        }
        newword[len + 3] = '\0';
    } else {
        // Copy original word if not translated
        strcpy(newword, word);
    }

    strcpy(translated, newword);
}

// Function to print the translated sentence
void printResult(char sentence[]) {
    printf("\nTranslated Sentence: %s\n", sentence);
}