//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variable to keep track of indentation
int indent_level = 0;

// function to increase the indentation level
void increase_indentation() {
    indent_level += 4;
}

// function to decrease the indentation level
void decrease_indentation() {
    if (indent_level > 0) {
        indent_level -= 4;
    }
}

// function to print a newline with the current indentation level
void print_newline() {
    printf("\n");
    for (int i = 0; i < indent_level; i++) {
        printf(" ");
    }
}

// function to beautify an HTML tag
void beautify_tag(char *tag) {
    if (strcmp(tag, "<html>") == 0) {
        increase_indentation();
    } else if (strcmp(tag, "</html>") == 0) {
        decrease_indentation();
        print_newline();
    } else if (strcmp(tag, "<head>") == 0) {
        print_newline();
        increase_indentation();
    } else if (strcmp(tag, "</head>") == 0) {
        decrease_indentation();
        print_newline();
    } else if (strcmp(tag, "<body>") == 0) {
        print_newline();
        increase_indentation();
    } else if (strcmp(tag, "</body>") == 0) {
        decrease_indentation();
        print_newline();
    } else {
        // unrecognized tag, just print it
        printf("%s", tag);
    }
}

// main function
int main() {
    char input[1000];
    fgets(input, 1000, stdin);

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '<') {
            // found a tag
            int j = i + 1;
            while (input[j] != '>' && input[j] != '\0') {
                j++;
            }
            if (input[j] == '>') {
                // have found the end of the tag
                char tag[100];
                strncpy(tag, &input[i], j - i + 1);
                tag[j - i + 1] = '\0';
                beautify_tag(tag);
                i = j + 1;
            } else {
                // reached the end of the string without finding the >
                printf("%c", input[i]);
                i++;
            }
        } else {
            // just a regular character
            printf("%c", input[i]);
            i++;
        }
    }

    return 0;
}