//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

char* translate(char* input) {
    char* output = malloc(strlen(input) * 2);

    int i = 0;
    while (input[i] != '\0') {
        switch (input[i]) {
            case '#':
                strcat(output, "meow");
                break;
            case '@':
                strcat(output, "purr");
                break;
            case '$':
                strcat(output, "hiss");
                break;
            case '*':
                strcat(output, "scratch");
                break;
            case '%':
                strcat(output, "claw");
                break;
            case '+':
                strcat(output, "lick");
                break;
            default:
                strcat(output, "?");
                break;
        }
        strcat(output, " ");
        i++;
    }

    return output;
}

int main() {
    char input[1000];
    printf("Input: ");
    fgets(input, 1000, stdin);

    char* output = translate(input);
    printf("Output: %s\n", output);

    free(output);
    return 0;
}