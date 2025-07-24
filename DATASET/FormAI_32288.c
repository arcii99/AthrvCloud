//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char html[1000];
    printf("Enter the HTML code: ");
    fgets(html, 1000, stdin); // read in HTML code
    int i = 0, indent = 0;
    while (html[i]) { // loop through each character in the HTML code
        if (html[i] == '<') { // if an opening tag is found
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf("\t"); // add indentation
            }
            printf("%c", html[i]); // print opening tag
            if (html[i + 1] != '/') { // check if it's not a closing tag
                indent++; // increase indentation level for next line
            }
        }
        else if (html[i] == '>') { // if a closing tag is found
            if (html[i - 1] == '/') { // check if it's a self-closing tag
                indent--; // decrease indentation level
            }
            printf("%c\n", html[i]); // print closing tag
        }
        else if (html[i] == '/') { // if a self-closing tag is found
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf("\t"); // add indentation
            }
            printf("%c", html[i]); // print tag
            indent--; // decrease indentation level
        }
        else {
            printf("%c", html[i]); // print character
        }
        i++;
    }
    printf("\n");
    return 0;
}