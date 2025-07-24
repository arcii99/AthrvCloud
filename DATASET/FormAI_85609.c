//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define max length of XML elements and attribute names/values
#define MAX_ELEMENT_LENGTH 50
#define MAX_ATTRIBUTE_LENGTH 30

typedef struct Attribute {
    char name[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_LENGTH];
    struct Attribute* next;
} Attribute;

typedef struct Element {
    char name[MAX_ELEMENT_LENGTH];
    Attribute* attributes;
    struct Element* children;
    char data[100];
    struct Element* next;
} Element;

// Recursive function to print the XML tree
void printTree(Element* node, int level) {
    if (node == NULL)
        return;

    // Add tabs to represent nested levels
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("<%s", node->name);

    // Print the element's attributes
    Attribute* attribute = node->attributes;
    while (attribute != NULL) {
        printf(" %s=\"%s\"", attribute->name, attribute->value);
        attribute = attribute->next;
    }

    // Print the element's data if it has any
    if (strlen(node->data) > 0) {
        printf(">%s</%s>\n", node->data, node->name);
    } 
    else {
        printf(">\n");
    }

    // Print the element's children recursively
    Element* child = node->children;
    while (child != NULL) {
        printTree(child, level + 1);
        child = child->next;
    }

    // End the current element
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("</%s>\n", node->name);
}

// Function to read an XML file and parse it into a tree structure
Element* parseXML(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return NULL;
    }

    // Initialize the root element
    Element* root = NULL;
    Element* currentElement = NULL;
    Attribute* currentAttribute = NULL;

    char buffer[100];
    int level = 0;
    bool inElement = false;
    bool inAttribute = false;
    while (fgets(buffer, 100, fp) != NULL) {
        // Trim the newline character from the buffer
        char* pos = strchr(buffer, '\n');
        if (pos != NULL) {
            *pos = '\0';
        }

        // Ignore whitespace
        if (strlen(buffer) == 0) {
            continue;
        }

        // Check if we're entering or exiting an element
        if (!inElement && buffer[0] == '<') {
            inElement = true;

            // Create a new element and add it to the tree
            Element* element = (Element*) malloc(sizeof(Element));
            element->next = NULL;
            element->attributes = NULL;

            // Parse the element name
            char* start = buffer + 1;
            char* end = strchr(buffer, ' ');
            if (end == NULL) {
                end = strchr(buffer, '>');
            }
            int len = end - start;
            strncpy(element->name, start, len);
            element->name[len] = '\0';

            // Check if this is the root element
            if (root == NULL) {
                root = element;
                currentElement = element;
                level = 1;
            } 
            else if (element->name[0] != '/') {
                // Add the new element as a child of the current element
                if (currentElement->children == NULL) {
                    currentElement->children = element;
                } 
                else {
                    Element* child = currentElement->children;
                    while (child->next != NULL) {
                        child = child->next;
                    }
                    child->next = element;
                }

                element->next = NULL;
                element->children = NULL;
                currentElement = element;
                level++;
            }
            else {
                // Move up one level in the tree
                currentElement = root;
                level--;
                if (level < 0) {
                    printf("Invalid XML format: %s\n", buffer);
                    return NULL;
                }
            }

            // Check if there are any attributes to parse
            start = end;
            while (*start != '\0') {
                if (*start == ' ') {
                    start++;
                    continue;
                }

                // Parse an attribute name
                end = strchr(start + 1, '=');
                if (end == NULL) {
                    break;
                }
                len = end - start - 1;
                strncpy(buffer, start + 1, len);
                buffer[len] = '\0';
                currentAttribute = (Attribute*) malloc(sizeof(Attribute));
                currentAttribute->next = NULL;
                strncpy(currentAttribute->name, buffer, strlen(buffer));

                // Parse the attribute value
                start = end + 1;
                end = strchr(start, '\"');
                if (end == NULL) {
                    break;
                }
                len = end - start - 1;
                strncpy(buffer, start + 1, len);
                buffer[len] = '\0';
                strncpy(currentAttribute->value, buffer, strlen(buffer));

                // Add the attribute to the current element
                if (currentElement->attributes == NULL) {
                    currentElement->attributes = currentAttribute;
                } 
                else {
                    Attribute* attribute = currentElement->attributes;
                    while (attribute->next != NULL) {
                        attribute = attribute->next;
                    }
                    attribute->next = currentAttribute;
                }

                start = end + 1;
            }
        } 
        else {
            // Parse the element data
            inElement = false;
            strncpy(currentElement->data, buffer, strlen(buffer));
        }
    }

    fclose(fp);
    return root;
}

int main() {
    Element* root = parseXML("example.xml");
    if (root == NULL) {
        printf("Unable to parse XML file\n");
        return 1;
    }

    printTree(root, 0);
    return 0;
}