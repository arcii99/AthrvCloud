//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char html[1000];
    printf("Enter a HTML string: ");
    fgets(html, sizeof html, stdin);

    int indent = 0;
    int length = strlen(html);
    char result[10000] = "";

    for (int i = 0; i < length; i++) {

        if (html[i] == '<') {

            //print the tag name
            strcat(result, "\n");
            for (int j = 0; j < indent; j++) {
                strcat(result, "    ");
            }
            strcat(result, "<");

            //loop through attributes
            int j = i + 1;
            while (html[j] != '>') {
                strcat(result, &html[j]);
                j++;
            }
            strcat(result, ">");

            //update indent
            indent++;
            i = j;

        } else if (html[i] == '>') {

            strcat(result, ">");
            i--;
        
        } else {

            strcat(result, &html[i]);
        }
    }

    printf("\n\nFormatted HTML:\n%s\n", result);
    return 0;
}