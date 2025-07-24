//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in C Cat Language:\n");
    scanf("%[^\n]", input);
    char output[100] = "";

    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'c':
                strcat(output, "meow");
                break;
            case 't':
                strcat(output, "purr");
                break;
            case 'l':
                strcat(output, "lick");
                break;
            case 's':
                strcat(output, "hiss");
                break;
            case 'r':
                strcat(output, "purr-purr");
                break;
            case 'n':
                strcat(output, "scratch");
                break;
            default:
                strcat(output, " ");
        }
    }

    printf("C Cat Translation: %s\n", output);

    return 0;
}