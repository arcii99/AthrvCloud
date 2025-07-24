//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char input[]) {
    int indent = 0;
    int len = strlen(input);
    int i = 0;

    while (i < len) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                indent -= 4;
            }
            else {
                for (int j=0; j<indent; j++) {
                    printf(" ");
                }
                indent += 4;
            }
            printf("%c", input[i]);
            i++;
            while (i < len && input[i] != '>') {
                printf("%c", input[i]);
                i++;
            }
            printf("%c\n", input[i]);
        }
        else if (input[i] == '>') {
            printf("%c\n", input[i]);
        }
        else if (input[i] == '\n') {
            printf("%c", input[i]);
            for (int j=0; j<indent; j++) {
                printf(" ");
            }
        }
        else {
            printf("%c", input[i]);
        }
        i++;
    }
}

int main() {
    char input[] = "<html>\n<head>\n<title>My Webpage</title>\n</head>\n<body>\n<h1>Welcome to My Webpage</h1>\n<p>This is my first webpage.</p>\n<img src=\"image.jpg\" alt=\"An image\">\n</body>\n</html>";
    beautifyHTML(input);
    return 0;
}