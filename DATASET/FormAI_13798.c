//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct representing an XML element with a tag and a list of attributes
struct xml_element {
    char* tag;
    char** attributes;
};

// Define a function to parse an XML element from a string
struct xml_element* parse_xml_element(char* xml_string) {
    struct xml_element* element = malloc(sizeof(struct xml_element));
    // Find the tag name and set it in the struct
    char* start_tag = strchr(xml_string, '<') + 1;
    char* end_tag = strchr(start_tag, '>');
    int tag_length = end_tag - start_tag;
    element->tag = malloc(tag_length + 1);
    strncpy(element->tag, start_tag, tag_length);
    element->tag[tag_length] = '\0';
    // Find the attributes and set them in the struct
    int attribute_count = 0;
    char* attribute_start = end_tag + 1;
    while (*attribute_start != '>') {
        if (*attribute_start != ' ') {
            attribute_count++;
        }
        attribute_start++;
    }
    element->attributes = malloc(attribute_count * sizeof(char*));
    int attribute_index = 0;
    char* attribute = strtok(attribute_start - attribute_count + 1, " \t\r\n");
    while (attribute != NULL) {
        element->attributes[attribute_index] = strdup(attribute);
        attribute_index++;
        attribute = strtok(NULL, " \t\r\n");
    }
    return element;
}

int main() {
    char* xml_string = "<example id=\"1\" type=\"test\">Hello, world!</example>";
    struct xml_element* element = parse_xml_element(xml_string);
    printf("Tag name: %s\n", element->tag);
    printf("Attributes: ");
    for (int i = 0; element->attributes[i] != NULL; i++) {
        printf("%s ", element->attributes[i]);
    }
    printf("\n");
    return 0;
}