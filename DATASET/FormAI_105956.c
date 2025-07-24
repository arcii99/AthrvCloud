//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

void translate_to_cat(char input[]) {
    // The following phrases were taken from https://github.com/jsvine/cattify
    char *translations[] = {
        {"hello"}, {"mew"},
        {"how are you?"}, {"hiss"},
        {"what is the weather like?"}, {"purr"},
        {"where is the nearest tuna restaurant?"}, {"meow"},
        {"give me some milk"}, {"nose lick"}
    };
    int num_translations = 5;
    char *output = malloc(strlen(input) * 2 + 1);
    output[0] = '\0';

    char *word = strtok(input, " ");
    while (word != NULL) {
        int found_translation = 0;
        for (int i = 0; i < num_translations; i++) {
            if (strcmp(word, translations[i][0]) == 0) {
                strcat(output, translations[i][1]);
                found_translation = 1;
                break;
            }
        }
        if (!found_translation) {
            strcat(output, word);
        }
        strcat(output, " ");
        word = strtok(NULL, " ");
    }
    printf("%s\n", output);
    free(output);
}

int main() {
    char input[100];
    printf("Enter a sentence in English to translate to C Cat Language:\n");
    fgets(input, 100, stdin);
    translate_to_cat(input);
    return 0;
}