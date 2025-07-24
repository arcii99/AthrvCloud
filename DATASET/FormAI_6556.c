//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify HTML code
void beautifyHTML(char* code) {
    int indent_level = 0;
    int len = strlen(code);
    int i = 0;

    while (i < len) {
        // check if current character is a tag opener or closer
        if (code[i] == '<') {
            if (code[i+1] == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
            printf("\n");
            for (int j = 1; j <= indent_level; j++) {
                printf("\t");
            }
        }

        // print current character
        printf("%c", code[i]);

        // check if current character is a tag closer
        if (code[i] == '>') {
            if (code[i-1] == '/') {
                indent_level--;
            }
        }

        i++;
    }
}

int main() {
    char code[] = "<html>\n<head>\n<title>My Web Page</title>\n</head>\n<body>\n<p>Welcome to my website!</p>\n</body>\n</html>";
    
    printf("Original HTML code: \n%s\n", code);
    printf("\nBeautified HTML code: ");
    beautifyHTML(code);

    return 0;
}