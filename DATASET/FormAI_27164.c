//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define XML Node Struct
typedef struct xml_node {
    char tag_name[50];
    char* content;
    struct xml_node* children;
    struct xml_node* next;
} xml_node;

// Helper function to parse XML attributes
void parse_attributes(xml_node* node, char* attribute_str) {
    char* attribute = strtok(attribute_str, " ");
    while (attribute != NULL) {
        char* delimiter = strchr(attribute, '=');
        int index = delimiter - attribute;
        char key[index + 1];
        strncpy(key, attribute, index);
        key[index] = '\0';
        int value_start = index + 2;
        int value_end = strlen(attribute) - 1;
        char value[value_end - value_start + 2];
        strncpy(value, attribute + value_start, value_end - value_start + 1);
        value[value_end - value_start + 1] = '\0';
        // Store attribute in node
        char* attribute_value = malloc(strlen(value) + 1);
        strcpy(attribute_value, value);
        xml_node* attribute_node = malloc(sizeof(xml_node));
        strcpy(attribute_node->tag_name, key);
        attribute_node->content = attribute_value;
        attribute_node->next = node->children;
        node->children = attribute_node;
        attribute = strtok(NULL, " ");
    }
}

// Recursive function to parse XML string into tree of XML nodes
void parse_xml(char* xml_str, xml_node** root_ptr) {
    char* xml_copy = malloc(strlen(xml_str) + 1);
    strcpy(xml_copy, xml_str);
    char* tag_index = strtok(xml_copy, "<");
    while (tag_index != NULL) {
        if (*tag_index == '/') {
            // End tag
            *root_ptr = (*root_ptr)->next;
        } else if (*tag_index == '?') {
            // XML declaration
            tag_index = strtok(NULL, "<");
        } else {
            // Start tag
            xml_node* new_node = malloc(sizeof(xml_node));
            new_node->content = NULL;
            new_node->next = *root_ptr;
            *root_ptr = new_node;
            char* delimiter = strchr(tag_index, ' ');
            if (delimiter == NULL) {
                delimiter = strchr(tag_index, '>');
            }
            int index = delimiter - tag_index;
            strncpy(new_node->tag_name, tag_index, index);
            new_node->tag_name[index] = '\0';
            if (delimiter != NULL) {
                parse_attributes(new_node, delimiter + 1);
            }
        }
        tag_index = strtok(NULL, "<");
    }
    // Reverse linked list of XML nodes
    xml_node* prev_node = NULL;
    xml_node* current_node = *root_ptr;
    while (current_node != NULL) {
        xml_node* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *root_ptr = prev_node;
}

// Example usage of XML parser
int main() {
    char* xml_str = "<xml version=\"1.0\"?><people><person name=\"Alice\"><age>30</age><address><street>Main St</street><city>San Francisco</city></address></person><person name=\"Bob\"><age>40</age><address><street>Market St</street><city>San Francisco</city></address></person></people>";
    xml_node* root = NULL;
    parse_xml(xml_str, &root);
    xml_node* current_node = root;
    while (current_node != NULL) {
        // Print node tag name and content
        printf("Tag Name: %s\n", current_node->tag_name);
        printf("Content: %s\n", current_node->content);
        // Print node attributes
        xml_node* attribute_node = current_node->children;
        while (attribute_node != NULL) {
            printf("Attribute: %s=%s\n", attribute_node->tag_name, attribute_node->content);
            attribute_node = attribute_node->next;
        }
        printf("\n");
        current_node = current_node->next;
    }
    return 0;
}