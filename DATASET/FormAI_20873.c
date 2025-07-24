//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for XML Node
typedef struct xml_node {
    char *tag;
    char *value;
    int n_attributes;
    char **attributes;
    struct xml_node **children;
} xml_node;

// Create a helper function to create a new XML Node
xml_node* create_node(char *tag, char *value, int n_attributes, char **attributes, int n_children) {
    xml_node *node = (xml_node*)malloc(sizeof(xml_node));
    node->tag = strdup(tag);
    node->value = strdup(value);
    node->n_attributes = n_attributes;
    node->attributes = attributes;
    node->children = (xml_node**)malloc(n_children * sizeof(xml_node*));
    return node;
}

// Create a helper function to parse the XML document
xml_node* parse_xml(char *xml, int n_nodes) {
    xml_node **nodes = (xml_node**)malloc(n_nodes * sizeof(xml_node*));
    int current_node = 0;
    char *current_tag = "";
    char *current_value = "";
    int n_attributes = 0;
    char **attributes = (char**)malloc(10 * sizeof(char*));
    int n_children = 0;
    int i;
    for(i = 0; i < strlen(xml); i++) {
        if(xml[i] == '<') {
            // Found a new tag
            int j;
            for(j = i + 1; xml[j] != '>'; j++) {
                current_tag = strncat(current_tag, &xml[j], 1);
            }
            if(xml[i + 1] == '/') {
                // End of a node, add the node to the list
                nodes[current_node] = create_node(current_tag, current_value, n_attributes, attributes, n_children);
                current_node++;
                current_tag = "";
                current_value = "";
                n_attributes = 0;
                n_children = 0;
            } else {
                // Start of a new node, add the tag to the attributes
                attributes[n_attributes] = strdup(current_tag);
                n_attributes++;
                current_tag = "";
            }
        } else if(xml[i] == '>') {
            // End of a tag
            if(xml[i - 1] == '/') {
                // A self closing tag, add the node to the list
                nodes[current_node] = create_node(current_tag, "", n_attributes, attributes, n_children);
                current_node++;
                current_tag = "";
                n_attributes = 0;
                n_children = 0;
            } else {
                // Start of a value
            }
        } else {
            // Character in between tags, add it to the value node
            current_value = strncat(current_value, &xml[i], 1);
        }
    }
    return nodes[0];
}

// Create a helper function to print the XML document
void print_xml(xml_node *node) {
    int i;
    printf("<%s", node->tag);
    for(i = 0; i < node->n_attributes; i++) {
        printf(" %s", node->attributes[i]);
    }
    printf(">");
    if(node->value) {
        printf("%s", node->value);
    } else {
        for(i = 0; i < 2*node->n_attributes; i++) {
            printf("\n");
        }
        for(i = 0; i < 2*node->n_attributes; i++) {
            printf(" ");
        }
        if(node->children) {
            for(i = 0; i < 10; i++) {
                if(node->children[i]) {
                    print_xml(node->children[i]);
                }
            }
        }
        printf("</%s>", node->tag);
    }
}

int main() {
    char xml[] = "<root><person name=\"John Smith\" age=\"35\"><email>john.smith@gmail.com</email><phone>555-1234</phone></person></root>";
    xml_node *root = parse_xml(xml, 4);
    print_xml(root);
    return 0;
}