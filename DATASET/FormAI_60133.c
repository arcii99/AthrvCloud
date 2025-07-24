//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* string = "<html><body><h1>Hello World!</h1><p>This is a test.</p></body></html>";
    char* output = malloc(sizeof(char) * strlen(string) * 2);  // Allocate memory for the output string
    
    int indent = 0;  // Variable to keep track of current indentation level
    
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == '<') {
            // Check if the tag is opening or closing
            if(string[i+1] != '/') {  
                // Add an indentation
                for(int j = 0; j < indent; j++) {
                    strcat(output, "    ");
                }
                // Copy the opening tag to the output string
                char opening_tag[100];
                int j = 0;
                while(string[i] != '>') {
                    opening_tag[j] = string[i];
                    i++;
                    j++;
                }
                opening_tag[j] = '>';  // Add the closing bracket
                opening_tag[j+1] = '\0';  // Add the null terminator
                strcat(output, opening_tag);
                strcat(output, "\n");  // Add a newline after the tag
                indent++;  // Increase the indentation level
            } else {
                indent--;  // Decrease the indentation level
                // Add an indentation
                for(int j = 0; j < indent; j++) {
                    strcat(output, "    ");
                }
                // Copy the closing tag to the output string
                char closing_tag[100];
                int j = 0;
                while(string[i] != '>') {
                    closing_tag[j] = string[i];
                    i++;
                    j++;
                }
                closing_tag[j] = '>';  // Add the closing bracket
                closing_tag[j+1] = '\0';  // Add the null terminator
                strcat(output, closing_tag);
                strcat(output, "\n");  // Add a newline after the tag
            }
        } else {
            // Copy the character to the output string
            char character[2];
            character[0] = string[i];
            character[1] = '\0';  // Add the null terminator
            strcat(output, character);
        }
    }
    
    printf("%s", output);  // Print the formatted HTML string
    
    free(output);  // Deallocate the memory used for the output string
    
    return 0;
}