//FormAI DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char html[10000];
    int indentLevel = 0;
    printf("Enter your HTML code: ");
    fgets(html, 10000, stdin);
    printf("\n");

    char* ptr = strtok(html, "\n");

    printf("<!DOCTYPE html>\n"); // always include a doctype at the beginning

    while (ptr != NULL) {
        if (strstr(ptr, "<") && !strstr(ptr, ">")) { // if a tag is split onto multiple lines
            char* endTag = strchr(ptr, '>'); // find the end of the tag
            char* start = ptr;
            ptr = strtok(NULL, "\n");
            char* concat = (char*) malloc(strlen(start) + strlen(ptr) + 1);
            strcpy(concat, start);
            strcat(concat, ptr);
            ptr = concat;
            printf("%*s%s\n", 4 * indentLevel, "", ptr); // print new tag on the same line
            indentLevel++;
            free(concat);
            ptr = endTag + 1;
        }
        else if (strstr(ptr, "<") && strstr(ptr, ">")) { // if a full tag is on one line
            printf("%*s%s\n", 4 * indentLevel, "", ptr); // print the tag on a new line
            if (strchr(ptr, '>')) {
                indentLevel++;
            }
            if (strstr(ptr, "</")) {
                indentLevel--;
            }
            ptr = strtok(NULL, "\n");
        }
        else { // if a line does not contain a tag
            printf("%*s%s\n", 4 * indentLevel, "", ptr); // print the line with appropriate indentation
            ptr = strtok(NULL, "\n");
        }
    }
    return 0;
}