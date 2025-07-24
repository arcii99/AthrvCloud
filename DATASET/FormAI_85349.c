//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define TAB_SIZE 4

int main() {
    char html[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int indentation = 0;
    int output_position = 0;
    
    printf("Enter HTML code (max %d characters):\n", MAX_INPUT_SIZE);
    fgets(html, MAX_INPUT_SIZE, stdin);
    
    for (int i = 0; i < strlen(html); i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') indentation -= TAB_SIZE;
            for (int j = 0; j < indentation; j++) {
                output[output_position++] = ' ';
            }
            if (html[i+1] != '/') indentation += TAB_SIZE;
        }
        output[output_position++] = html[i];
        if (html[i] == '>') {
            if (html[i+1] != '<' && html[i+1] != '/') {
                output[output_position++] = '\n';
            }
        }
    }
    
    printf("\nYour beautified HTML code is:\n\n");
    printf("%s\n", output);
    
    return 0;
}