//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char* name;
    char* content;
} element;

element* parse_element(char* xml) {
    element* el = malloc(sizeof(element));

    // Parse element name
    char* name_start = strchr(xml, '<') + 1;
    char* name_end = strchr(xml, '>');
    int name_len = name_end - name_start;
    el->name = malloc((name_len + 1) * sizeof(char));
    strncpy(el->name, name_start, name_len);
    el->name[name_len] = '\0';

    // Parse element content
    char* content_start = name_end + 1;
    char* content_end = strstr(content_start, "</");
    int content_len = content_end - content_start;
    el->content = malloc((content_len + 1) * sizeof(char));
    strncpy(el->content, content_start, content_len);
    el->content[content_len] = '\0';

    return el;
}

int main() {
    char xml[] = "<name>John</name>";

    element* el = parse_element(xml);

    printf("Element name: %s\n", el->name);
    printf("Element content: %s\n", el->content);

    free(el->name);
    free(el->content);
    free(el);

    return 0;
}