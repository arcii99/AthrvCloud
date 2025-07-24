//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void translate_input(char* input) {
    char output[MAX_INPUT_LENGTH] = "";
    char curr_char = input[0];
    int curr_count = 1;

    for (int i = 1; i <= strlen(input); i++) {
        if (input[i] == curr_char) {
            curr_count++;
        } else {
            char count_str[MAX_INPUT_LENGTH] = "";
            sprintf(count_str, "%d", curr_count);
            strcat(output, count_str);
            strcat(output, &curr_char);
            curr_count = 1;
            curr_char = input[i];
        }
    }

    printf("%s\n", output);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter a word in Cat language: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character from input
    input[strcspn(input, "\n")] = 0;

    translate_input(input);

    return 0;
}