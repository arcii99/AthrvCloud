//FormAI DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void add_indentation(int n) {
    for(int i = 0; i < n; i++) {
        printf(" ");
    }
}

void beautify_html(char* input) {
    int indent = 0;
    int len = strlen(input);
    
    for(int i = 0; i < len; i++) {
        // check for opening or closing tags
        if(input[i] == '<') {
            if(input[i+1] == '/') {
                indent--;
                printf("\n");
                add_indentation(indent*4);
            } else {
                printf("\n");
                add_indentation(indent*4);
                indent++;
            }
            printf("%c", input[i]);
        }
        // check for tag attributes
        else if(input[i] == ' ' && input[i-1] != '>') {
            printf("\n");
            add_indentation(indent*4 + 4);
            while(input[i] != '>') {
                printf("%c", input[i]);
                i++;
            }
            printf("%c", input[i]);
        }
        // handle all other characters
        else {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}

int main() {
    
    char input[1000] = "<html><body><h1>Welcome!</h1><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p><a href='https://example.com'><img src='image.jpg' alt='example'></a></body></html>";
    
    beautify_html(input);
    
    return 0;
}