//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char alienLanguage[50];
    printf("Enter the Alien Language to translate: ");
    fgets(alienLanguage, 50, stdin);
    alienLanguage[strcspn(alienLanguage, "\n")] = 0;

    bool vowels = true;
    char* vowelArr[] = {"a", "e", "i", "o", "u"};

    for (int i=0; i<strlen(alienLanguage); i++) {
        for (int j=0; j<5; j++) {
            if (alienLanguage[i] == vowelArr[j][0]) {
                printf("%s", vowelArr[j]);
                vowels = false;
                break;
            }
        }
        if (vowels) {
            printf("%c", alienLanguage[i]);
        }
        vowels = true;
    }

    return 0;
}