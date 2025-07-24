//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the XML structure
typedef struct xml_node {
    char* element;
    char* content;
    struct xml_node* children;
    struct xml_node* siblings;
} xml_node;

// Helper function to create a new XML node
xml_node* new_xml_node(char* element, char* content) {
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->element = (char*) malloc((strlen(element) + 1) * sizeof(char));
    node->content = (char*) malloc((strlen(content) + 1) * sizeof(char));
    strcpy(node->element, element);
    strcpy(node->content, content);
    node->children = NULL;
    node->siblings = NULL;
    return node;
}

// Helper function to add a child node to an XML node
void add_child_xml_node(xml_node* parent, xml_node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        xml_node* sibling = parent->children;
        while (sibling->siblings != NULL) {
            sibling = sibling->siblings;
        }
        sibling->siblings = child;
    }
}

// Helper function to parse an XML string
xml_node* parse_xml(char* xml) {
    xml_node* root = NULL;
    xml_node* curr = NULL;
    char* element = NULL;
    char* content = NULL;
    char* token = strtok(xml, "<>");

    while (token != NULL) {
        if (strcmp(token, "") != 0 && token[0] != '/') {
            if (element == NULL) {
                element = token;
            } else {
                content = token;
                xml_node* node = new_xml_node(element, content);
                if (root == NULL) {
                    root = node;
                    curr = node;
                } else {
                    add_child_xml_node(curr, node);
                    curr = node;
                }
                element = NULL;
                content = NULL;
            }
        } else if (strlen(token) > 1 && token[0] == '/') {
            if (curr->siblings != NULL) {
                curr = curr->siblings;
            } else {
                curr = curr->children;
            }
        }
        token = strtok(NULL, "<>");
    }

    return root;
}

int main() {
    // Example XML string
    char xml[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><books><book><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author></book><book><title>To Kill a Mockingbird</title><author>Harper Lee</author></book></books>";

    // Parse the XML string
    xml_node* root = parse_xml(xml);

    // Print the parsed XML tree
    printf("Root element: %s\n", root->element);
    xml_node* child = root->children;
    while (child != NULL) {
        printf("  Element: %s\n", child->element);
        printf("  Content: %s\n", child->content);
        xml_node* sub_child = child->children;
        while (sub_child != NULL) {
            printf("    Element: %s\n", sub_child->element);
            printf("    Content: %s\n", sub_child->content);
            sub_child = sub_child->siblings;
        }
        child = child->siblings;
    }

    return 0;
}