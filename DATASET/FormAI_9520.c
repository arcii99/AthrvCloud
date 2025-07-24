//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function to beautify HTML code 
   by adding appropriate indentation */
int main(void) {
    char input[1000];
    char formatted[1000];
    int indent = 0;
    int new_line = 1;
    
    printf("Enter the HTML code to be beautified: \n");
    fgets(input, 1000, stdin);
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '<') {
            if (new_line) {
                for (int j = 0; j < indent; j++) {
                    strcat(formatted, "\t");
                }
            }
            strcat(formatted, "<");
            if (input[i+1] != '/') {
                indent++;
                new_line = 1;
            } 
            else {
                indent--;
                if (new_line) {
                    for (int j = 0; j < indent; j++) {
                        strcat(formatted, "\t");
                    }
                }
                new_line = 0;
            }
        } 
        else if (input[i] == '>') {
            strcat(formatted, ">\n");
            new_line = 1;
        } 
        else {
            strncat(formatted, &input[i], 1);
            new_line = 0;
        }
    }
    
    printf("Beautified HTML code: \n%s", formatted);
    return 0;
}