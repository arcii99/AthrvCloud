//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

void translate(char input[]) {
    int i, j, k;
    char output[1000] = "";
    for (i = 0; i < strlen(input); i += 2) {
        int n = input[i] - '0';
        for (j = i + 1; j < strlen(input); j += 4) {
            char c = 0;
            for (k = j; k < j + 4; k++) {
                c = (c << 1) | (input[k] - '0');
            }
            output[n++] = c;
        }
    }
    printf("\nTranslated Alien Text: %s\n", output);
}

int main() {
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("Please enter the Alien Text to translate: ");
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("\nInput Alien Text: %s\n", input);
    translate(input);
    return 0;
}