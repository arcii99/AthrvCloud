//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

int main() {
    // Setting up dictionary
    char* c_cat_dict[] = {
        "meow", "if",
        "purr", "else",
        "hiss", "while",
        "paw", "for",
        "claws", "do",
        "whiskers", "break",
        "tail", "continue",
        "nip", "return",
        "scratch", "switch",
        "catnip", "case",
        "screech", "default",
        "toys", "struct",
        "collar", "union",
        "treats", "int",
        "kitten", "char",
        "litterbox", "void",
        "housecat", "main",
        "furball", "printf"
    };

    // Prompting for input
    printf("Enter C Cat code to translate to ordinary C:\n");

    // Reading in input line by line
    char line[200];
    while (fgets(line, sizeof(line), stdin)) {
        // Tokenizing the input line
        char* token = strtok(line, " \n\t\r");

        // Translating each token
        while (token != NULL) {
            // Checking if token exists in the dictionary
            int exists_in_dict = 0;
            for (int i = 0; i < 34; i += 2) {
                if (strcmp(c_cat_dict[i], token) == 0) {
                    exists_in_dict = 1;
                    printf("%s ", c_cat_dict[i + 1]);
                    break;
                }
            }

            // If token does not exist in dictionary, output as is
            if (!exists_in_dict) {
                printf("%s ", token);
            }

            token = strtok(NULL, " \n\t\r");
        }

        printf("\n");
    }

    return 0;
}