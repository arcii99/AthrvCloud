//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    char input[BUFFER_SIZE];
    
    printf("Enter a string:\n");
    fgets(input, BUFFER_SIZE, stdin); // get user input
    
    // sanitize the user input
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '<' || input[i] == '>') { // check for angle brackets
            input[i] = '_'; // replace with underscore
        } else if (input[i] == '&') { // check for ampersand
            if (strncmp(input + i, "&amp;", strlen("&amp;")) == 0) { // check for &amp;
                i += strlen("&amp;") - 1; // skip over &amp;
            } else if (strncmp(input + i, "&lt;", strlen("&lt;")) == 0) { // check for &lt;
                input[i] = '<'; // replace with <
                memmove(input + i + 1, input + i + strlen("&lt;"), strlen(input + i + strlen("&lt;")) + 1); // shift characters after < to the left
            } else if (strncmp(input + i, "&gt;", strlen("&gt;")) == 0) { // check for &gt;
                input[i] = '>'; // replace with >
                memmove(input + i + 1, input + i + strlen("&gt;"), strlen(input + i + strlen("&gt;")) + 1); // shift characters after > to the left
            } else { // unrecognized ampersand
                input[i] = '_'; // replace with underscore
            }
        }
    }
    
    printf("Sanitized string: %s\n", input);
    
    return 0;
}