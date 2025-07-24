//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void print_header(void);
void print_footer(void);
int is_valid_char(char c);
void beautify_html(char *input);

int main(void) {
    char input[MAX_LEN];

    print_header();
    printf("Enter HTML code to beautify:\n");
    fgets(input, MAX_LEN, stdin);

    beautify_html(input);

    print_footer();
    return 0;
}

void print_header(void) {
    printf("/*=====================*\n");
    printf("  * C HTML Beautifier v1 *\n");
    printf("  *    Cyberpunk Style   *\n");
    printf("  *=====================*/\n\n");
}

void print_footer(void) {
    printf("\n/*=================================*/\n");
}

int is_valid_char(char c) {
    if (isalnum(c) || c == '<' || c == '>' || c == '/' || c == '!' || c == '?' || c == '=' || c == ' ' || c == '"'
        || c == '\'' || c == '.' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void beautify_html(char *input) {
    int len = strlen(input);
    char prev_char = '\0';
    int indent_level = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];

        if (c == '<') {
            if (prev_char != '\n') {
                printf("\n");
            }

            for (int j = 0; j < indent_level; j++) {
                printf("  ");
            }

            printf("%c", c);
            prev_char = c;

            if (input[i+1] == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
        } else if (c == '>') {
            printf("%c\n", c);
            prev_char = c;
        } else if (c == ' ') {
            printf("%c", c);
        } else if (is_valid_char(c)) {
            printf("%c", c);
        } else if (c == '\n') {
            int next_index = i + 1;

            while (next_index < len && input[next_index] == '\n') {
                next_index++;
            }

            if (next_index == len) {
                break;
            }

            if (input[next_index] == '<') {
                continue;
            } else {
                printf("\n");
            }
        } else {
            printf("ERROR: Invalid character '%c' found.\n", c);
            return;
        }
    }
}