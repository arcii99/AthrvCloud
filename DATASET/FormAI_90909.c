//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// The following function takes an ugly HTML code and makes it beautiful
void surreal_beauty(char *html) {
    int indent_level = 0; // initialize the indent level to 0

    // loop through the HTML code until the end is reached
    while (*html != '\0') {
        
        // if a new element is found, increase the indent level
        if (*html == '<') {
            printf("\n");
            for (int i = 0; i < indent_level; i++) {
                printf("  "); // each level of indentation is two spaces
            }
            indent_level++;
            printf("%c", *html);
            html++;
        }
        
        // if a closing element is found, decrease the indent level
        else if (*html == '>') {
            printf("%c", *html);
            indent_level--;
            html++;
        }

        // if a character is found inside an element, simply print it
        else if (*html != '\r' && *html != '\n' && *html != '\t') {
            printf("%c", *html);
            html++;
        }
        
        // skip line breaks and tabs outside elements
        else {
            html++;
        }
    }

    printf("\n"); // add a line break at the end
}

int main() {
    char* html = "<html><head><title>Welcome</title></head><body>   <h1>My Name is Neo!</h1>\n<p>I work in the Matrix, creating surrealistic websites!</p></body></html>";
    surreal_beauty(html);
    return 0;
}