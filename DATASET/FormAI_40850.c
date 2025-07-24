//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100

char* translate(char* input);

int main(void) {
    char input[MAX_INPUT];
    printf("Welcome to the C-Cat Translator Program! Enter a sentence to be translated:\n");
    fgets(input, MAX_INPUT, stdin);
    printf("Translation: %s\n", translate(input));
    return 0;
}

char* translate(char* input) {
    char result[MAX_INPUT] = "";
    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (input[i] == 'c' || input[i] == 'C') {
                strcat(result, "meow");
                index += 4;
            } else {
                result[index] = input[i];
                index++;
            }
        }
    }
    return result;
}