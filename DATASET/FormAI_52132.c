//FormAI DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>

// Function to beautify an HTML code
void beautify_HTML(char* htmlCode) {
    int i = 0, j = 0;
    char beautifiedCode[10000];

    while (htmlCode[i] != '\0') {
        if (htmlCode[i] == '<') {
            // Indent the HTML element
            for (int k = 0; k < j; k++) {
                beautifiedCode[i+j+k] = ' ';
            }
            j += 2;
        }
        beautifiedCode[i+j] = htmlCode[i];
        if (htmlCode[i] == '>') {
            // Add a new line after the HTML element
            beautifiedCode[i+j+1] = '\n';
            j++;
        } 
        i++;
    }
    printf("%s", beautifiedCode);
}

// Main program
int main() {
    char htmlCode[] = "<html><head><title>Sample Title</title></head><body><h1>Sample Heading</h1><p>Sample paragraph.</p></body></html>";
    beautify_HTML(htmlCode);
    return 0;
}