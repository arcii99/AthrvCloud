//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
void beautifyHTML(char* htmlCode) {
    int indentLevel = 0;
    int len = strlen(htmlCode);

    for(int i=0; i<len;) {
        // If opening tag detected
        if(htmlCode[i] == '<' && htmlCode[i+1] != '/') {
            // Increase indentation level and print new line
            indentLevel++;
            printf("\n");
            for(int j=0; j<indentLevel; j++)
                printf("    ");

            // Print opening tag
            while(htmlCode[i] != '>' && i < len) {
                printf("%c", htmlCode[i]);
                i++;
            }
            printf("%c", htmlCode[i]);
            i++;
        } 
        // If closing tag detected
        else if(htmlCode[i] == '<' && htmlCode[i+1] == '/') {
            // Decrease indentation level and print new line
            indentLevel--;
            printf("\n");
            for(int j=0; j<indentLevel; j++)
                printf("    ");

            // Print closing tag
            while(htmlCode[i] != '>' && i<len) {
                printf("%c", htmlCode[i]);
                i++;
            }
            printf("%c", htmlCode[i]);
            i++;
        }
        // If text data detected
        else {
            // Print the text and look for next opening tag
            while(htmlCode[i] != '<' && i<len) {
                printf("%c", htmlCode[i]);
                i++;
            }
        }
    }
}

// Driver code
int main() {
    char htmlCode[1000];
    printf("Enter the HTML code:\n");
    fgets(htmlCode, 1000, stdin);
    printf("\nOriginal code:\n%s", htmlCode);

    printf("\nBeautified code:\n");
    beautifyHTML(htmlCode);

    printf("\n");
    return 0;
}