//FormAI DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* input = "<html><head><title>My Funny HTML Page</title></head><body><h1>Welcome to my page</h1><p>This is a paragraph.</p></body></html>";
    char* output = malloc(sizeof(char) * strlen(input));
    int indent_level = 0;
    int i = 0;

    while (input[i] != '\0') {
        // check for opening and closing tags
        if (input[i] == '<' && input[i+1] != '/') {
            printf("\n");
            for (int j = 0; j < indent_level*4; j++) {
                printf(" ");
            }
            printf("%c", input[i]);
            printf("%c", input[i+1]);
            indent_level++;
            i += 2;
        } else if (input[i] == '<' && input[i+1] == '/') {
            printf("\n");
            indent_level--;
            for (int j = 0; j < indent_level*4; j++) {
                printf(" ");
            }
            printf("%c", input[i]);
            printf("%c", input[i+1]);
            i += 2;
        } else {
            printf("%c", input[i]);
            i++;
        }
    }

    return 0;
}