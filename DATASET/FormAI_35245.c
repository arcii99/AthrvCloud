//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
/* 
This program takes an HTML file and beautifies its code by correctly indenting and spacing 
the tags and elements. This will help improve the readability of the code and make it easier  
to understand and edit. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of a line of code in the HTML file

void indent(int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf("    "); // each level of indentation is 4 spaces
    }
}

int main(int argc, char **argv) {

    if (argc != 2) { // if the user does not input exactly one HTML file, return an error
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); // open the HTML file for reading
    if (fp == NULL) { // if the file does not exist, return an error
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LEN], element[MAX_LEN];
    int level = 0, i;

    while (fgets(line, MAX_LEN, fp) != NULL) { // read each line of the HTML file

        int length = strlen(line);

        if (!strcmp(line, "<html>\n")) { 
            indent(level);
            printf("<html>\n");
            level++;
        } 
        else if (!strcmp(line, "</html>\n")) {
            level--;
            indent(level);
            printf("</html>\n");
        } 
        else {

            int j = 0;
            while (line[j] == ' ') {
                j++;
            }
            if (line[j] == '<') {

                int k = j+1;
                while (line[k] != ' ' && line[k] != '>') {
                    element[k-j-1] = line[k];
                    k++;
                }
                element[k-j-1] = '\0';

                if (line[k] == '>') {
                    indent(level);
                    printf("<%s>\n", element);
                    if (!strcmp(element, "head") || !strcmp(element, "body")) {
                        level++;
                    }
                } else {
                    indent(level);
                    printf("<%s ", element);
                    while (line[k] != '>') {
                        printf("%c", line[k]);
                        k++;
                    }
                    printf(">\n");
                    if (!strcmp(element, "head") || !strcmp(element, "body")) {
                        level++;
                    }
                }
            } 
            else {
                indent(level);
                printf("%s", line);
            }
        }
    }

    fclose(fp); // close the HTML file
    return 0; // program success
}