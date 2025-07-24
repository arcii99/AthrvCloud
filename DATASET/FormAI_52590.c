//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SPACES 4

int main(void) {
    char input[10000] = {0};
    char output[10000] = {0};
    int tabs = 0;
    int open_bracket_count = 0;
    int close_bracket_count = 0;
    int i = 0;
    int j = 0;

    printf("Enter HTML code to beautify:\n");
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input) - 1; i++) {
        char current_char = input[i];
        char next_char = input[i + 1];
        if (current_char == '<') {
            if (next_char != '/') {
                strncpy(&output[j], "\n", 1);
                j++;
                for (int k = 0; k < tabs; k++) {
                    strncpy(&output[j], " ", TAB_SPACES);
                    j += TAB_SPACES;
                }
                open_bracket_count++;
                tabs++;
            } else {
                tabs--;

                if (open_bracket_count == close_bracket_count) {
                    strncpy(&output[j], "\n", 1);
                    j++;
                }
                for (int k = 0; k < tabs; k++) {
                    strncpy(&output[j], " ", TAB_SPACES);
                    j += TAB_SPACES;
                }
                close_bracket_count++;
            }
        }
        strncpy(&output[j], &current_char, 1);
        j++;
        if (current_char == '>') {
            strncpy(&output[j], "\n", 1);
            j++;
            if (next_char != '<' && next_char != '/') {
                for (int k = 0; k < tabs; k++) {
                    strncpy(&output[j], " ", TAB_SPACES);
                    j += TAB_SPACES;
                }
            }
        }
    }

    printf("\nBeautified code:\n");
    printf("%s\n", output);

    return EXIT_SUCCESS;
}