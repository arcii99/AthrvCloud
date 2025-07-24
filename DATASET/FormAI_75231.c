//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define XML element structure
typedef struct xml_element_t {
    char* tag_name;
    char** attributes;
    struct xml_element_t** children;
    int num_attributes;
    int num_children;
} xml_element;

// Define function to create XML element
xml_element* xml_create_element(char* tag_name, int num_attributes, int num_children) {
    // Allocate memory for XML element
    xml_element* element = (xml_element*)malloc(sizeof(xml_element));
    element->tag_name = tag_name;
    element->num_attributes = num_attributes;
    element->num_children = num_children;

    // Allocate memory for attributes
    element->attributes = (char**)malloc(num_attributes * sizeof(char*));
    for (int i = 0; i < num_attributes; i++) {
        element->attributes[i] = NULL;
    }

    // Allocate memory for children
    element->children = (xml_element**)malloc(num_children * sizeof(xml_element*));
    for (int i = 0; i < num_children; i++) {
        element->children[i] = NULL;
    }

    return element;
}

// Define function to parse XML file
xml_element* xml_parse(char* filename) {
    // Open XML file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Declare variables
    char buffer[256];
    char* token;
    char* tag_name;
    int num_attributes = 0;
    int num_children = 0;
    xml_element* element = NULL;
    xml_element* child_element = NULL;

    // Loop through file line by line
    while (fgets(buffer, sizeof(buffer), file)) {
        // Get tag name
        token = strtok(buffer, " ");
        while (token != NULL) {
            if (token[0] == '<' && token[1] != '/') {
                tag_name = strtok(token + 1, ">");
                element = xml_create_element(tag_name, num_attributes, num_children);
            }
            else if (token[0] == '<' && token[1] == '/') {
                // end element; do nothing
            }
            else {
                // Attribute or child element
                if (token[0] == 'a') {
                    // Attribute; add to attributes array
                    element->attributes[num_attributes] = strtok(token + 1, "\"");
                    num_attributes++;
                }
                else {
                    // Child element; parse recursively
                    child_element = xml_parse(token);
                    element->children[num_children] = child_element;
                    num_children++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Close file and return element
    fclose(file);
    return element;
}

int main() {
    // Parse XML file
    char* filename = "example.xml";
    xml_element* element = xml_parse(filename);

    // Print element tag name
    printf("Tag Name: %s\n", element->tag_name);

    // Print attributes
    for (int i = 0; i < element->num_attributes; i++) {
        printf("Attribute %d: %s\n", i+1, element->attributes[i]);
    }

    // Print children
    for (int i = 0; i < element->num_children; i++) {
        printf("Child %d: %s\n", i+1, element->children[i]->tag_name);
    }

    return 0;
}