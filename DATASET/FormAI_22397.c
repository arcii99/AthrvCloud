//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter text to translate: ");
    fgets(input, 1000, stdin);

    // replace words in C Cat language
    char output[1000] = "";
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o') {
            strcat(output, "int ");
            i += 2;
        } else if (input[i] == 'p' && input[i+1] == 'u' && input[i+2] == 'r' && input[i+3] == 'r') {
            strcat(output, "float ");
            i += 3;
        } else if (input[i] == 'h' && input[i+1] == 'i' && input[i+2] == 's') {
            strcat(output, "char ");
            i += 2;
        } else if (input[i] == 'p' && input[i+1] == 'a' && input[i+2] == 'w') {
            strcat(output, "double ");
            i += 2;
        } else if (input[i] == 'c' && input[i+1] == 'l' && input[i+2] == 'a' && input[i+3] == 'w') {
            strcat(output, "struct ");
            i += 3;
        } else if (input[i] == 'f' && input[i+1] == 'i' && input[i+2] == 's' && input[i+3] == 'h') {
            strcat(output, "enum ");
            i += 3;
        } else {
            char temp[2] = {input[i], '\0'};
            strcat(output, temp);
        }
    }

    printf("Translated output: %s", output);
    return 0;
}