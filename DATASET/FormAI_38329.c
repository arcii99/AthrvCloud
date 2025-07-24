//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000

int indentation = 0;

//Recursive function to beautify HTML code
void process_line(char *line) {

    int i = 0, j = 0, k = 0;

    if (line[i] == '\n')
        return;

    //Trimming leading whitespaces
    while (isspace(line[i])) {
        i++;
    }

    //Checking whether the line is closing tag or not
    if (line[i] == '<' && line[i + 1] == '/') {
        indentation--;
    }

    //Printing beautified line
    for (k = 0; k < indentation; k++) {
        printf(" ");
    }

    while (line[i] != '\0') {

        if (line[i] == '<') {

            //Printing tag
            putchar(line[i++]);

            while (line[i] != '>' && line[i] != ' ') {
                putchar(line[i++]);
            }

            putchar(line[i++]);

            //Checking whether the tag is self closing
            if (line[i - 2] == '/') {
                continue;
            }

            putchar('\n');
            indentation++;

        } else if (line[i] == '>') {
            putchar(line[i++]);
            putchar('\n');

        } else {
            putchar(line[i++]);
        }
    }
}

//Main function
int main() {

    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL) {
        process_line(line);
    }

    return 0;
}