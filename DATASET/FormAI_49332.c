//FormAI DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char *source, char *dest, int len);

int main()
{
    char *source = "<html><head><title>Sample Page</title></head><body><p>This is sample HTML code</p></body></html>";
    int len = strlen(source);
    
    char *dest = (char *) malloc(len*sizeof(char));
    
    beautifyHTML(source, dest, len);
    
    printf("Input HTML code:\n%s\n", source);
    printf("Beautified HTML code:\n%s\n", dest);
    
    free(dest);
    
    return 0;
}

void beautifyHTML(char *source, char *dest, int len)
{
    // Initialize the stack
    char stack[50][50];
    int top = -1;
    
    // Initialize the indentation level
    int level = 0;
    
    // Loop through the source code
    for (int i = 0; i < len; i++) {
        
        // Check if the current character is the beginning of a tag
        if (source[i] == '<' && source[i+1] != '/') {
            
            // Push the tag onto the stack
            top++;
            strcpy(stack[top], "");
            strncat(stack[top], &source[i], strcspn(&source[i], ">")+1);
            
            // Indent the tag
            for (int j = 0; j < level; j++) {
                strcat(dest, "\t");
            }
            
            // Copy the tag to the destination string
            strcat(dest, &source[i]);
            
            // Update the index to the end of the tag
            i += strcspn(&source[i], ">")+1;
            
            // Increment the indentation level
            level++;
            
            // Check if the tag is self-closing
            if (source[i-2] == '/') {
                level--;
            }
            
            // Add a newline character
            strcat(dest, "\n");
            
        }
        
        // Check if the current character is the end of a tag
        else if (source[i] == '>') {
            
            // Indent the tag
            for (int j = 0; j < level; j++) {
                strcat(dest, "\t");
            }
            
            // Copy the tag to the destination string
            strcat(dest, &source[i]);
            
            // Update the index to the end of the tag
            i += strcspn(&source[i], ">")+1;
            
            // Add a newline character
            strcat(dest, "\n");
            
        }
        
        // Check if the current character is the beginning of a closing tag
        else if (source[i] == '<' && source[i+1] == '/') {
            
            // Pop the top tag from the stack
            top--;
            
            // Decrement the indentation level
            level--;
            
            // Indent the tag
            for (int j = 0; j < level; j++) {
                strcat(dest, "\t");
            }
            
            // Copy the tag to the destination string
            strcat(dest, &source[i]);
            
            // Update the index to the end of the tag
            i += strcspn(&source[i], ">")+1;
            
            // Add a newline character
            strcat(dest, "\n");
            
        }
        
        // Check if the character is part of the text
        else {
            
            // Indent the text
            for (int j = 0; j < level; j++) {
                strcat(dest, "\t");
            }
            
            // Copy the text to the destination string
            strncat(dest, &source[i], strcspn(&source[i], "<"));
            
            // Update the index to the end of the text
            i += strcspn(&source[i], "<")-1;
            
            // Add a newline character
            strcat(dest, "\n");
            
        }
    }
}