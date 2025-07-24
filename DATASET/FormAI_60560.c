//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Function to translate C Cat language to English
void translate_c_cat(char* c_cat_string) {
    char final_string[100];
    char* token;

    // Define a dictionary for C Cat keywords and their English translations
    char keyword_dict[][2][20] = {{"meow", "int"},
                                  {"purr", "char"},
                                  {"hiss", "float"},
                                  {"yawn", "double"},
                                  {"scratch", "long"},
                                  {"stretch", "unsigned"}};

    // Tokenize the C Cat string
    token = strtok(c_cat_string, " ");

    while (token != NULL) {
        int found = 0;

        // Check if the token is a C Cat keyword
        for (int i = 0; i < 6; i++) {
            if (strcmp(keyword_dict[i][0], token) == 0) {
                strcat(final_string, keyword_dict[i][1]);
                strcat(final_string, " ");
                found = 1;
            }
        }

        // If not a keyword, copy the original token
        if (!found) {
            strcat(final_string, token);
            strcat(final_string, " ");
        }

        token = strtok(NULL, " ");
    }

    printf("%s", final_string);
}

int main() {
    char c_cat_string[] = "meow x; scratch y; purr z;";
    printf("C Cat translation: ");
    translate_c_cat(c_cat_string);
    return 0;
}