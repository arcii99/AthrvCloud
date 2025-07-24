//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

void AlienToEnglish(char alienWord[]) {
    int i;
    char engWord[30]="";
    for (i=0; i<strlen(alienWord); i++) {
        if (alienWord[i] == 'r') {
            strcat(engWord, "a");
        } else if (alienWord[i] == 'r' || alienWord[i] == 's' || alienWord[i] == 't' || alienWord[i] == 'l' || alienWord[i] == 'n') {
            strcat(engWord, "e");
        } else if (alienWord[i] == 'y' || alienWord[i] == 'u' || alienWord[i] == 'i' || alienWord[i] == 'o' || alienWord[i] == 'a') {
            strcat(engWord, "i");
        } else if (alienWord[i] == 'k' || alienWord[i] == 'm' || alienWord[i] == 'p' || alienWord[i] == 'j' || alienWord[i] == 'b') {
            strcat(engWord, "o");
        } else if (alienWord[i] == 'f' || alienWord[i] == 'g' || alienWord[i] == 'c' || alienWord[i] == 'v' || alienWord[i] == 'd') {
            strcat(engWord, "u");
        } else if (alienWord[i] == 'q' || alienWord[i] == 'z' || alienWord[i] == 'x') {
            strcat(engWord, "!");
        } else {
            strcat(engWord, " ");
        }
    }
    printf("The alien word %s in English is %s\n", alienWord, engWord);
}

int main() {
    char alienWord[30];
    printf("Welcome to the Alien Language Translator! Please enter a word in alien language: ");
    scanf("%s", alienWord);
    AlienToEnglish(alienWord);
    return 0;
}