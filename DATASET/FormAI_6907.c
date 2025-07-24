//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in C Cat language:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    char output[100];
    int i, j=0;
    for(i=0; i<strlen(input); i++) {
        if(input[i] == 'c' || input[i] == 'C') {
            output[j++] = 'm';
            output[j++] = 'e';
            output[j++] = 'o';
            output[j++] = 'w';
        } else {
            output[j++] = input[i];
        }
    }

    printf("Translation: %s\n", output);

    return 0;
}