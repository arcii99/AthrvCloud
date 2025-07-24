//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <ctype.h>

#define SIZE 30000

char html[SIZE];

/* Function to read HTML code */
void read_html(char* html)
{
    char ch;
    int i = 0;
    printf("Enter the HTML code:\n");
    while ((ch = getchar()) != EOF && i < SIZE-1) {
        html[i++] = ch;
    }
    html[i] = '\0';
}

/* Function to beautify HTML code */
void beautify_html(char* html)
{
    int indent = 0;
    char ch;
    int i = 0;
    while ((ch = html[i]) != '\0') {
        if (ch == '<') {
            if (html[i+1] == '/') {
                indent -= 4;
                printf("\n%*c", indent, ' ');
            } else {
                printf("\n%*c", indent, ' ');
                indent += 4;
            }
        }
        printf("%c", ch);
        i++;
    }
    printf("\n");
}

int main()
{
    read_html(html);
    beautify_html(html);
    return 0;
}