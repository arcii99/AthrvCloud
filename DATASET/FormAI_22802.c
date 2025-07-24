//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000], word[1000];
    int i, j, freq, len, count = 0;

    printf("Please enter your text: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // remove any non-alphabetic characters and make lowercase
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            input[count++] = tolower(input[i]);
        }
    }
    input[count] = '\0';

    // tokenize and count frequency
    for (i = 0; i < strlen(input); i++) {
        j = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            word[j++] = input[i++];
        }
        word[j] = '\0';

        freq = 1;
        for (j = i + 1; j < strlen(input); j++) {
            if (strcmp(word, "") != 0) {  // avoid counting empty strings
                if (strcmp(word, " ") != 0 && strncmp(&input[j], word, strlen(word)) == 0) {
                    freq++;
                    strcpy(&input[j], "");
                }
            }
        }
        if (strcmp(word, "") != 0) {
            printf("%s: %d\n", word, freq);
        }
    }

    return 0;
}