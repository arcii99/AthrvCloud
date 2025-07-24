//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

/* Function to beautify HTML code */
void beautifyHTML(char *input) {
    char ch = ' ';
    int i = 0, j = 0;
    int tab_count = 0;
    int in_tag = 0;

    while(input[i] != '\0') {
        ch = input[i];
        
        /* If character is '<', check if it's an opening or closing tag */
        if(ch == '<') {
            in_tag = 1;
            printf("%c", ch);
            /* If it's a closing tag, decrease the tab count */
            if(input[i+1] == '/') {
                tab_count--;
            } 
            /* If it's an opening tag, increase the tab count */
            else {
                tab_count++;
            }
        } 
        /* If character is '>', print it and move to new line */
        else if (ch == '>') {
            printf("%c\n", ch);
            in_tag = 0;
        } 
        /* If character is '\n', ignore it */
        else if (ch == '\n') {
            continue;
        } 
        /* If character is a space and outside a tag, ignore it */
        else if (ch == ' ' && !in_tag) {
            continue;
        } 
        /* Else print the character */
        else {
            printf("%c", ch);
        }

        /* Add indendation */
        if(!in_tag) {
            for(j=0;j<tab_count;j++) {
                printf("\t");
            }
        }
        i++;
    }
}

int main() {
    char *input = "<html><head><title>My Page</title></head><body><h1>Welcome to my page</h1></body></html>";
    beautifyHTML(input);
    return 0;
}