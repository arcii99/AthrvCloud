//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// function to format HTML code
void beautifyCode(char *code) {
    int tabCount = 0;
    for (int i = 0; code[i]; i++) {
        // add tab before opening tag
        if (code[i] == '<' && code[i+1] != '/') {
            for (int j = 0; j < tabCount; j++) {
                printf("\t");
            }
            tabCount++;
        }
        // remove tab after closing tag
        if (code[i] == '<' && code[i+1] == '/') {
            tabCount--;
        }
        printf("%c", code[i]);
        // add line break after every closing tag
        if (code[i] == '>' && code[i-1] != '/') {
            printf("\n");
        }
    }
}

int main() {
    // input HTML code
    char code[] = "<html>\n<head>\n<title>My Website</title>\n</head>\n<body>\n<h1>Welcome to my website!</h1>\n<p>This is some sample text.</p>\n</body>\n</html>";
    // format code
    beautifyCode(code);
    return 0;
}