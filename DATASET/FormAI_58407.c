//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
// C Cat Language Translator
// Author: [Your Name]

#include <stdio.h>
#include <string.h>

int main() {
    char input[101], output[101], c;

    printf("Enter a sentence in C Cat language: ");
    scanf("%[^\n]", input);

    int i, j, n;
    n = strlen(input);

    // Translate C Cat to English
    for (i = 0, j = 0; i < n; i++, j++) {
        c = input[i];

        if (c == 'm') {
            output[j] = 'c';
            output[++j] = 'a';
            output[++j] = 't';
        } else if (c == 'w') {
            output[j] = 'k';
            output[++j] = 'i';
            output[++j] = 't';
            output[++j] = 't';
            output[++j] = 'e';
            output[++j] = 'n';
        } else if (c == 'r') {
            output[j] = 'p';
            output[++j] = 'u';
            output[++j] = 'r';
            output[++j] = 'r';
            output[++j] = 'r';
        } else {
            output[j] = c;
        }
    }
    output[j] = '\0'; // add null terminator

    printf("Translation of C Cat language: %s\n", output);

    return 0;
}