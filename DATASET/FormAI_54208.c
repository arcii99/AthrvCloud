//FormAI DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter your HTML code:\n");

    char html[10000];
    fgets(html, sizeof(html), stdin);

    int numTabs = 0;
    int numNewLines = 0;
    char beautified[10000] = "";

    for (int i = 0; i < strlen(html); i++) {
        if (html[i] == '<') {
            strcat(beautified, "\n");
            numNewLines++;
            for (int j = 0; j < numTabs; j++) {
                strcat(beautified, "\t");
            }
            strcat(beautified, "<");
            numTabs++;
        } else if (html[i] == '>') {
            strcat(beautified, ">");
            numTabs--;
        } else {
            strcat(beautified, &html[i]);
        }
    }

    printf("\nYour beautified HTML code:\n\n");
    printf("%s\n", beautified);

    printf("\nThanks for using the HTML beautifier!\n");

    return 0;
}