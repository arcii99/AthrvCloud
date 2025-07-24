//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

int is_vowel(char c) {
    int i;
    for (i = 0; i < 5; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[1000], output[1000];
    int len, i, j = 0;

    printf("Welcome to Alien Language Translator!\n");
    printf("Please enter the alien language text to translate: ");

    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            if (is_vowel(c)) {
                output[j++] = c;
                output[j++] = 'b';
            } else {
                output[j++] = c;
                output[j++] = 'a';
            }
        } else if (c >= 'A' && c <= 'Z') {
            c = c + 32;
            if (is_vowel(c)) {
                output[j++] = c - 32;
                output[j++] = 'B';
            } else {
                output[j++] = c - 32;
                output[j++] = 'A';
            }
        } else {
            output[j++] = c;
        }
    }

    printf("Translation: %s\n", output);

    return 0;
}