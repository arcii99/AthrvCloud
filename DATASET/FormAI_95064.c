//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char sentence[1000] = "Oh Romio, wherefore art thou Romio?";
    char dictionary[100][100] = {"art", "thou", "Romio", "Romeo", "wherefore"};
    char *word, *match;
    int i, j, found, len, dict_size = 5;

    word = strtok(sentence, " ,?.!");
    while (word != NULL) {
        len = strlen(word);

        // Convert word to lowercase
        for (i = 0; i < len; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] += 32;
            }
        }

        // Check if word matches any word in dictionary
        found = 0;
        for (i = 0; i < dict_size; i++) {
            match = strstr(dictionary[i], word);
            if (match != NULL && match == dictionary[i]) {
                found = 1;
                break;
            }
        }

        // If word is not found in dictionary, suggest corrections
        if (!found) {
            printf("Oh pardon me, but dost thou mean:\n");
            for (j = 0; j < dict_size; j++) {
                if (strlen(dictionary[j]) == len) {
                    for (i = 0; i < len; i++) {
                        if (dictionary[j][i] != word[i]) {
                            break;
                        }
                    }
                    if (i == len-1) {
                        printf("%s\n", dictionary[j]);
                    }
                }
            }
        }

        word = strtok(NULL, " ,?.!");
    }

    return 0;
}