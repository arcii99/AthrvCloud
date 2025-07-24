//FormAI DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the HTML beautifier program! \n");
    printf("Enter your HTML code: \n");

    // read in the user's input
    char input[5000];
    fgets(input, 5000, stdin);

    // remove any existing indentation
    char no_indent[5000];
    int no_indent_index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != ' ' && input[i] != '\t') {
            no_indent[no_indent_index] = input[i];
            no_indent_index++;
        }
    }

    // add the proper indentation
    int indent_level = 0;
    char output[5000];
    int output_index = 0;
    for (int i = 0; i < strlen(no_indent); i++) {
        if (no_indent[i] == '<') {
            if (no_indent[i+1] == '/') {
                indent_level--;
            }
            for (int j = 0; j < indent_level; j++) {
                output[output_index] = '\t';
                output_index++;
            }
            if (no_indent[i+1] != '/') {
                indent_level++;
            }
        }
        output[output_index] = no_indent[i];
        output_index++;
    }
    output[output_index] = '\0';

    printf("Here is your updated HTML code: \n");
    printf("%s \n", output);

    return 0;
}