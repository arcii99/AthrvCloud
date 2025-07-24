//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char sentence[1000], word[1000];
    int freq[1000] = {0}, count = 0, flag = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {

        if (isalpha(sentence[i])) {
            word[count] = sentence[i];
            count++;
        }

        else if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
            word[count] = '\0';

            for (int j = 0; j < strlen(word); j++)
                word[j] = tolower(word[j]);

            for (int j = 0; j < flag; j++) {

                if (strcmp(word, &sentence[freq[j]]) == 0) {
                    freq[j + 1]++;
                    break;
                }

                else if (j == flag - 1) {
                    freq[flag] = strlen(sentence) + count;
                    freq[flag + 1]++;
                    flag += 2;
                }
            }

            count = 0;
        }
    }

    printf("\nWord frequency count:\n");

    for (int i = 0; i < flag; i += 2)
        printf("%.*s:%d\n", freq[i + 1], &sentence[freq[i]], freq[i + 1]);

    return 0;
}