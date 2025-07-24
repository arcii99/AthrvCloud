//FormAI DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is whitespace
bool is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Function to beautify the given HTML code
void beautify_html(char* code) {
    int indent_level = 0;
    int code_length = strlen(code);

    // Loop through each character in the code
    for (int i = 0; i < code_length; i++) {
        char c = code[i];

        // If we find an opening tag, increase the indent level and print the tag with an indent
        if (c == '<' && code[i + 1] != '/') {
            printf("%*c%c", indent_level * 4, ' ', c);
            indent_level++;
        }

        // If we find a closing tag, decrease the indent level and print the tag with an indent
        else if (c == '<' && code[i + 1] == '/') {
            indent_level--;
            printf("\n%*c%c", indent_level * 4, ' ', c);
        }

        // If we find a closing angle bracket after a whitespace character, remove the space
        else if (c == '>' && is_whitespace(code[i - 1])) {
            printf("%c", c);
        }

        // If we find a whitespace character after an opening angle bracket, remove the space
        else if (is_whitespace(c) && code[i - 1] == '<') {
            continue;
        }

        // If we find a whitespace character after an opening tag, increase the indent level and print the tag with an indent
        else if (is_whitespace(c) && code[i - 1] == '/' && code[i - 2] == '<') {
            indent_level++;
            printf("\n%*c%c", indent_level * 4, ' ', c);
        }

        // If none of the above conditions are met, simply print the character
        else {
            printf("%c", c);
        }
    }
}

int main() {
    char code[] = "<html>\n\t<head>\n\t\t<title>My Page</title>\n\t</head>\n\t<body>\n\t\t<h1>Welcome!</h1>\n\t\t<p>This is my page. It's not much, but it's mine.</p>\n\t</body>\n</html>";
    printf("Original code:\n%s\n\n", code);

    beautify_html(code);
    printf("\n\nBeautified code:\n%s\n", code);

    return 0;
}