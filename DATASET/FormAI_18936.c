//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>

/* Function to beautify the given HTML code */
void beautify(char *html) {
    int indent = 0;
    char *p = html;
    while (*p != '\0') {
        if (*p == '<') {
            /* Check if tag is opening or closing */
            int closing = 0;
            if (*(p+1) == '/') {
                closing = 1;
            }
            /* Print indent */
            for (int i = 0; i < indent; i++) {
                printf(" ");
            }
            /* Print tag */
            printf("%s", p);
            /* Increase or decrease indent */
            if (!closing && *(p+strlen(p)-2) != '/') {
                printf("\n");
                indent += 4;
            } else {
                indent -= 4;
            }
        } else {
            /* Print text */
            printf("%c", *p);
        }
        p++;
    }
}

int main() {
    char html[] = "<html><head><title>My Page</title></head><body><h1>Welcome!</h1><p>This is my page.</p></body></html>";
    beautify(html);
    return 0;
}