//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_indent(int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
}

int is_self_closing_tag(char* tag) {
    char *self_closing_tags[] = {"br", "hr", "img", "input", "meta"};
    int num_tags = sizeof(self_closing_tags) / sizeof(self_closing_tags[0]);
    
    for (int i = 0; i < num_tags; i++) {
        if (strcmp(tag, self_closing_tags[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char* html = "<html><head><title>My Page</title></head><body><h1>Welcome!</h1><p>This is my first page.</p></body></html>";
    int indent_level = 0;
    
    for (int i = 0; i < strlen(html); i++) {
        // Check for opening tag
        if (html[i] == '<' && html[i+1] != '/') {
            // Print the tag and increase the indent level
            printf("\n");
            print_indent(indent_level);
            printf("%c", html[i]);
            i++;
            while (html[i] != '>') {
                printf("%c", html[i]);
                i++;
            }
            printf(">");
            if (!is_self_closing_tag(&html[i - strlen(&html[i-1])])) {
                indent_level++;
            }
        }
        // Check for closing tag
        else if (html[i] == '<' && html[i+1] == '/') {
            // Decrease the indent level and print the tag
            indent_level--;
            printf("\n");
            print_indent(indent_level);
            printf("%c%c", html[i], html[i+1]);
            i += 2;
            while (html[i] != '>') {
                printf("%c", html[i]);
                i++;
            }
            printf(">");
        }
        // Otherwise, just print the character
        else {
            printf("%c", html[i]);
        }
    }
    
    printf("\n");
    return 0;
}