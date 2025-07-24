//FormAI DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>

/* HTML beautifier function */
void html_beautifier(char* input_text) {
    int indent_level = 0;
    char current_char, last_char = '\0';
    int i, j;

    /* Loop through each character of the input string */
    for (i = 0; input_text[i] != '\0'; i++) {
        current_char = input_text[i];

        /* Increase indent level when opening tag is encountered */
        if (current_char == '<' && last_char != '/') {
            for (j = 0; j < indent_level; j++) {
                printf("    ");
            }
            indent_level++;
        }

        /* Decrease indent level when closing tag is encountered */
        if (current_char == '<' && last_char == '/') {
            indent_level--;
            for (j = 0; j < indent_level; j++) {
                printf("    ");
            }
        }

        /* Print the current character */
        printf("%c", current_char);
        
        /* Insert newline after closing tag */
        if (current_char == '>' && last_char == '/') {
            printf("\n");
            for (j = 0; j < indent_level; j++) {
                printf("    ");
            }
        }

        last_char = current_char;
    }
}

int main() {
    /* Example input HTML text to be beautified */
    char input_text[] = "<html><head><title>My webpage</title></head><body><p>Welcome to my webpage!</p></body></html>";

    /* Call HTML beautifier function */
    html_beautifier(input_text);

    return 0;
}