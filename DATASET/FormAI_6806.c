//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions for parsing and formatting HTML code

char* remove_extra_whitespace(char* html) {
    int i, j, flag;
    char* cleaned_html = malloc(strlen(html) * sizeof(char));
    for (i = 0, j = 0, flag = 0; i < strlen(html); i++) {

        // Check for spaces and ignore them if we're already in a whitespace streak
        if (html[i] == ' ') {
            if (flag == 1) {
                continue;
            } else {
                flag = 1;
            }
        } else {
            flag = 0;
        }

        // Copy over the character to our cleaned HTML
        cleaned_html[j] = html[i];
        j++;
    }
    cleaned_html[j] = '\0';
    return cleaned_html;
}

int get_spaces(char* html_line) {
    int i, spaces = 0;
    for (i = 0; i < strlen(html_line); i++) {
        if (html_line[i] == ' ') {
            spaces++;
        } else {
            break;
        }
    }
    return spaces;
}

void indent_line(char* html_line, int spaces) {
    int i;
    for (i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("%s\n", html_line);
}

// Main HTML beautifier function

void format_html(char* html) {
    int i, spaces, curr_spaces = 0, in_tag = 0, in_comment = 0, in_string = 0;
    char current_char, prev_char;
    char* cleaned_html = remove_extra_whitespace(html);

    for (i = 0; i < strlen(cleaned_html); i++) {
        current_char = cleaned_html[i];
        prev_char = cleaned_html[i-1];

        // Check if we're inside a tag or a string
        if (current_char == '<' && in_string == 0) {
            in_tag = 1;
        } else if (current_char == '>' && in_string == 0) {
            in_tag = 0;
        } else if (current_char == '"' && in_string == 0) {
            in_string = 1;
        } else if (current_char == '"' && in_string == 1) {
            in_string = 0;
        }

        // Check if we're inside a comment
        if (i < strlen(cleaned_html) - 3 && cleaned_html[i] == '<' && cleaned_html[i+1] == '!' 
            && cleaned_html[i+2] == '-' && cleaned_html[i+3] == '-' && in_comment == 0) {
            spaces = get_spaces(cleaned_html + i);
            indent_line(cleaned_html + i, spaces);
            curr_spaces = spaces;
            i += 3;
            in_comment = 1;
            continue;
        } else if (i > 3 && cleaned_html[i] == '-' && cleaned_html[i-1] == '-' && cleaned_html[i-2] == '>' 
                    && cleaned_html[i-3] == '-' && in_comment == 1) {
            in_comment = 0;
            continue;
        }

        // Handle newline insertion
        if (prev_char == '\n' && in_tag == 0 && in_comment == 0) {
            spaces = get_spaces(cleaned_html + i);
            if (spaces > curr_spaces) {
                curr_spaces = spaces;
            }
        } else if (current_char == '>' && in_tag == 0 && in_comment == 0) {
            printf("\n");
        }

        // Handle indenting
        if (prev_char == '\n' && in_tag == 1 && in_comment == 0) {
            spaces = get_spaces(cleaned_html + i);
            curr_spaces = spaces;
            indent_line(cleaned_html + i, spaces);
        } else if (current_char == '<' && in_tag == 0 && in_comment == 0) {
            indent_line(cleaned_html + i, curr_spaces);
        } else if (i == strlen(cleaned_html) - 1 && in_comment == 0) {
            indent_line(cleaned_html + i, curr_spaces);
        } else {
            printf("%c", current_char);
        }
    }
}

// Example usage

int main() {
    char* html = "<div><p>Some text</p><p>More text</p></div><!-- Some comment --><p>Final text</p>";
    format_html(html);
    return 0;
}