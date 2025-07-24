//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translate(char* input);

int main() {
    char input[100];
    printf("Enter the string to be translated: ");
    scanf("%[^\n]s", input);
    printf("Translated string: %s\n", translate(input));
    return 0;
}

char* translate(char* input) {
    int i, j, k, l;
    char* output = (char*) malloc(strlen(input) * 3 * sizeof(char));
    char consonants[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            output[j] = ' ';
            j++;
            continue;
        }
        for (k = 0; k < strlen(consonants); k++) {
            if (input[i] == consonants[k]) {
                output[j] = consonants[k];
                j++;
                output[j] = 'o';
                j++;
                output[j] = consonants[k];
                j++;
                break;
            }
        }
        if (k == strlen(consonants)) {
            for (l = 0; l < strlen(vowels); l++) {
                if (input[i] == vowels[l]) {
                    output[j] = vowels[l];
                    j++;
                    break;
                }
            }
        }
    }
    return output;
}