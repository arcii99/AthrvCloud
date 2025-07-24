//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data structure for holding XML element information
typedef struct {
    char* element_name;
    char* element_content;
} xml_element_t;

// Struct for holding XML data
typedef struct {
    int num_elements;
    xml_element_t* elements;
} xml_data_t;

// Function for parsing XML data from a string input
xml_data_t parse_xml_string(char* xml_string) {
    xml_data_t parsed_data;

    // Initialize variables for parsing
    const char* element_start = "<";
    const char* element_end = ">";
    const char* content_start = ">";
    const char* content_end = "<";
    char* element_buffer = calloc(sizeof(char), strlen(xml_string));
    char* content_buffer = calloc(sizeof(char), strlen(xml_string));
    int element_index = 0;
    int content_index = 0;
    bool inside_element = false;
    bool inside_content = false;

    // Count the number of elements in the input XML string
    for (int i = 0; i < strlen(xml_string); i++) {
        if (strstr(&xml_string[i], element_start) == &xml_string[i]) {
            parsed_data.num_elements++;
        }
    }

    // Allocate memory for holding parsed elements
    parsed_data.elements = calloc(parsed_data.num_elements, sizeof(xml_element_t));

    // Parse elements and content from the input XML string
    for (int i = 0; i < strlen(xml_string); i++) {
        if (strstr(&xml_string[i], element_start) == &xml_string[i]) {
            // Beginning of a new element
            inside_element = true;
            element_index = 0;
        } else if (strstr(&xml_string[i], element_end) == &xml_string[i]) {
            // End of the current element
            inside_element = false;
            inside_content = false;

            // Copy element name and content to their respective buffers
            parsed_data.elements[parsed_data.num_elements - 1].element_name = calloc(sizeof(char), strlen(element_buffer));
            strcpy(parsed_data.elements[parsed_data.num_elements - 1].element_name, element_buffer);
            parsed_data.elements[parsed_data.num_elements - 1].element_content = calloc(sizeof(char), strlen(content_buffer));
            strcpy(parsed_data.elements[parsed_data.num_elements - 1].element_content, content_buffer);
        } else if (strstr(&xml_string[i], content_start) == &xml_string[i]) {
            // Beginning of element content
            inside_content = true;
            content_index = 0;
        } else if (strstr(&xml_string[i], content_end) == &xml_string[i]) {
            // End of element content
            inside_content = false;
        } else {
            // Add character to appropriate buffer
            if (inside_element) {
                element_buffer[element_index] = xml_string[i];
                element_index++;
            } else if (inside_content) {
                content_buffer[content_index] = xml_string[i];
                content_index++;
            }
        }
    }

    return parsed_data;
}

int main() {
    char* xml_input = "<root><person><name>John Smith</name><age>30</age></person><person><name>Jane Doe</name><age>25</age></person></root>";
    xml_data_t parsed_xml = parse_xml_string(xml_input);

    // Print parsed elements and their content
    for (int i = 0; i < parsed_xml.num_elements; i++) {
        printf("Element Name: %s\n", parsed_xml.elements[i].element_name);
        printf("Element Content: %s\n", parsed_xml.elements[i].element_content);
    }

    return 0;
}