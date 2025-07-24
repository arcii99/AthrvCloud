//FormAI DATASET v1.0 Category: Browser Plugin ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void process_html_tag(char *tag, int length) {
    // Convert tag to lowercase
    for (int i = 0; i < length; i++) {
        tag[i] = tolower(tag[i]);
    }
    // Check if tag is a valid HTML tag
    if (strcmp(tag, "a") == 0 || strcmp(tag, "img") == 0 || strcmp(tag, "div") == 0) {
        // Tag is valid, process it here
        printf("Processing HTML tag: <%s>\n", tag);
        // TODO: Add your code here to process the tag
    } else {
        // Tag is invalid, ignore it
        printf("Ignoring invalid HTML tag: <%s>\n", tag);
    }
}

int main() {
    char html[1000];
    printf("Enter HTML code: ");
    fgets(html, 1000, stdin);
    // Remove newline at the end of input
    html[strcspn(html, "\n")] = 0;
    // Process each tag in the HTML code
    char *tag = strtok(html, "<>");
    while (tag != NULL) {
        // Ignore any non-tag text
        if (tag[0] != '/') {
            int length = strlen(tag);
            process_html_tag(tag, length);
        }
        tag = strtok(NULL, "<>");
    }
    return 0;
}