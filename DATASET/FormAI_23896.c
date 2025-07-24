//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int frequency[26] = {0};

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; i < strlen(sentence); i++) {
        char c = tolower(sentence[i]);

        if (c >= 'a' && c <= 'z') {
            frequency[c - 'a']++;
        }
    }

    printf("\n********** C Word Frequency Counter **********\n");

    for (int i = 0; i < 26; i++) {
        printf("%c : ", 'a' + i);

        for (int j = 0; j < frequency[i]; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("----------------------------------------------\n");
    printf("Press any key to exit...");
    getchar();
    return 0;
}