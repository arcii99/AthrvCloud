//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 100, stdin);   // Get user input

    char output[100];
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i] == 'c' || input[i] == 'C') {
            if (i+1 < strlen(input) && input[i+1] == 'a') {
                i++;   // skip 'a'
                output[j] = 'k';
            } else {
                output[j] = 'C';
            }
        } else if (input[i] == 'a') {
            output[j] = 'a';
        } else if (input[i] == 't') {
            output[j] = 't';
        } else {
            output[j] = input[i];
        }
        j++;
    }
    output[j] = '\0';   // Add null terminator to end of string

    printf("Translated sentence: %s\n", output);

    return 0;
}