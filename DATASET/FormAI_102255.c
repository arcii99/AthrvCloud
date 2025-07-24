//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct xml_node {
    char *name;
    char *value;
    struct xml_node *children;
    struct xml_node *next;
} xml_node;

/**
 * Parses the given XML string and returns the root node of the tree
 */
xml_node *parse_xml_string(char *xml_string) {
    xml_node *root_node = NULL;
    // TODO: Implement the XML parsing logic here
    
    return root_node;
}

/**
 * Prints the contents of the given XML node and all its children
 */
void print_xml_node(xml_node *node) {
    if (node == NULL) {
        return;
    }

    printf("<%s>", node->name);
    if (node->value != NULL) {
        printf("%s", node->value);
    }

    xml_node *child = node->children;
    if (child != NULL) {
        printf("\n");
    }
    while (child != NULL) {
        print_xml_node(child);
        child = child->next;
    }

    printf("</%s>\n", node->name);
}

int main() {
    char *xml_string = "<html><head><title>My Title</title></head><body><h1>Welcome to my website!</h1><p>This is the homepage of my website.</p></body></html>";

    xml_node *root_node = parse_xml_string(xml_string);
    if (root_node != NULL) {
        print_xml_node(root_node);
    }

    return 0;
}