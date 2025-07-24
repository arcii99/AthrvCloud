//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include<stdio.h>

void beautify(char *html) {
    int tab_count = 0;
    for(int i=0; html[i]!='\0'; i++) {
        if(html[i] == '<') {
            if(html[i+1] == '/') {
                tab_count--;
            }
            for(int j=0; j<tab_count; j++) {
                printf("\t");
            }
            tab_count++;
        }
        if(html[i] == '>') {
            printf("%c\n", html[i]);
        }
        else {
            printf("%c", html[i]);
        }
    }
}

int main() {
    char html[] = "<html> <head> <title>My Website</title> </head> </html>";
    printf("Input HTML: \n%s\n", html);
    printf("Output HTML: \n");
    beautify(html);
    return 0;
}