//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function to remove all white spaces from a string */
void removeWhiteSpace(char *string) {
    int i = 0, j = 0;
    while (string[i]) {
        if (!isspace(string[i])) {
            string[j++] = string[i];
        }
        i++;
    }
    string[j] = '\0';
}

/* Function to add appropriate indentation to each line */
void addIndentation(int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
}

/* Main function to beautify the HTML code */
void beautifyHTML(char *code) {
    int i = 0, level = 0;
    while (code[i]) {
        /* If '<' encountered, new tag has started */
        if (code[i] == '<') {
            /* Print the tag and update index */
            printf("%c", code[i++]);
            /* Check whether it is an opening or closing tag */
            if (code[i] == '/') {
                level--;
            }
            else {
                level++;
            }
            /* Add appropriate indentation and print the tag */
            addIndentation(level);
            while (code[i] != '>') {
                printf("%c", code[i++]);
            }
            printf("%c\n", code[i++]);
        }
        /* If normal text, print it */
        else {
            /* Add appropriate indentation and print the text */
            addIndentation(level);
            while (code[i] && code[i] != '<') {
                printf("%c", code[i++]);
            }
            printf("\n");
        }
    }
}

/* Driver function */
int main() {
    char code[1000];
    printf("Enter HTML code:\n");
    fgets(code, sizeof(code), stdin);

    /* Remove all white spaces */
    removeWhiteSpace(code);

    /* Beautify the HTML code */
    beautifyHTML(code);

    return 0;
}