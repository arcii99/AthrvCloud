//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// Function to check if a given character exists in the
// alien language
int isValidChar(char c, char *alienLang) {
    for(int i=0; i<strlen(alienLang); i++) {
        if(alienLang[i] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to translate the given word from alien language
// to English
void translate(char *word, char *alienLang, char *english) {
    char currentChar;
    int flag;
    for(int i=0; i<strlen(word); i++) {
        flag = 0;
        currentChar = word[i];
        if(isValidChar(currentChar, alienLang)) {
            printf("%c", currentChar);
            flag = 1;
        }
        if(flag == 0) {
            for(int j=0; j<strlen(english); j++) {
                if(english[j] == currentChar) {
                    printf("%c", currentChar);
                    break;
                }
            }
        }
    }
    printf("\n");
}

// Driver function
int main() {
    char alienLang[] = "BDC";
    char english[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char words[][20] = {"BAACBD", "CCDBDA", "ACAAAA", "BCAACC", "CCBDDB"};

    for(int i=0; i<5; i++) {
        printf("Alien Language Word: %s\n", words[i]);
        printf("English Translation: ");
        translate(words[i], alienLang, english);
    }

    return 0;
}