//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main() {

    char word[20];
    char language[10];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Enter the language of the word (A or B): ");
    scanf("%s", language);

    if (strcmp(language, "A") == 0) {
        for (int i = 0; i < strlen(word); i++) {
            int ascii = word[i];
            printf("%c%c", ascii / 10 + 'A', ascii % 10 + 'A');
        }
    }
    else if (strcmp(language, "B") == 0) {
        for (int i = 0; i < strlen(word); i += 2) {
            int first = word[i] - 'A';
            int second = word[i + 1] - 'A';
            int ascii = first * 10 + second;
            printf("%c", ascii);
        }
    }
    else {
        printf("Invalid language identifier");
    }

    printf("\n");

    return 0;
}