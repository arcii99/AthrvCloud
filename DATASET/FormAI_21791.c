//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is unbelievable! I never thought I would write my own XML parser!
// Here's a sample program that does exactly that.

typedef struct {
    char *tag_name;
    char *attr_name;
    char *attr_value;
} xml_element;

xml_element parse_element(char *element_string) {
    xml_element elem;

    // Use strtok to separate the tag name, attribute name and attribute value
    char *token = strtok(element_string, "<>=\"");

    // The first token is always the tag name
    elem.tag_name = malloc(sizeof(char) * strlen(token) + 1); // Dynamic memory allocation
    strcpy(elem.tag_name, token);

    // Traverse the rest of the tokens until the end of the string
    while (token != NULL) {
        token = strtok(NULL, "<>=\"");

        if(token != NULL) {
            // Alternate tokens will either be attribute names or attribute values
            if(elem.attr_name == NULL) {
                elem.attr_name = malloc(sizeof(char) * strlen(token) + 1);
                strcpy(elem.attr_name, token);
            }
            else {
                elem.attr_value = malloc(sizeof(char) * strlen(token) + 1);
                strcpy(elem.attr_value, token);
            }
        }
    }

    return elem;
}

int main() {
    char *xml = "<person name=\"John Doe\" age=\"25\"></person>";
    xml_element elem = parse_element(xml);

    printf("Tag name: %s\nAttribute name: %s\nAttribute value: %s\n", 
        elem.tag_name, elem.attr_name, elem.attr_value);

    return 0;
}