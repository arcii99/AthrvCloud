//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000

void indent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int stack[MAX_LINES];
    int top = -1;
    int depth = 0;
    int num_lines = 0;
    
    // read input lines into array
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, stdin) != NULL) {
        strcpy(lines[num_lines], line);
        num_lines++;
    }
    
    // iterate through lines and beautify them
    for (int i = 0; i < num_lines; i++) {
        char* tag = strstr(lines[i], "<");
        
        if (tag != NULL) {
            *tag = '\0'; // terminate line before tag
            indent(depth);
            printf("%s\n", lines[i]);
            
            if (*(tag + 1) == '/') {
                depth--;
            } else {
                stack[++top] = depth++;
            }
            
            // add tag to line and print
            sprintf(line, "%s<%s>", tag, tag + 1);
            indent(depth);
            printf("%s\n", line);
        } else {
            if (top >= 0 && strstr(lines[i], "</") != NULL) {
                depth = stack[top--];
            }
            
            indent(depth);
            printf("%s\n", lines[i]);
        }
    }
    
    return 0;
}