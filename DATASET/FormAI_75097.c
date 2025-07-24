//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Representation of a node in the XML tree */
typedef struct xml_node {
    char *name;                         /* tag name */
    char *value;                        /* tag value */
    struct xml_node *first_child;       /* first child node */
    struct xml_node *next_sibling;      /* next sibling node */
} xml_node;

/* Parse an XML string and return the root node of the tree */
xml_node* parse_xml(char *xml_str) {
    /* TODO: implement parsing algorithm */
    xml_node *root = NULL;
    return root;
}

/* Print the contents of an XML tree */
void print_xml(xml_node *node, int indent_level) {
    if (node == NULL) {
        return;
    }
    /* Indentation */
    for (int i = 0; i < indent_level; i++) {
        printf(" ");
    }
    /* Print tag name and value */
    printf("<%s>%s\n", node->name, node->value);
    /* Recursively print child nodes */
    print_xml(node->first_child, indent_level + 2);
    /* Recursively print sibling nodes */
    print_xml(node->next_sibling, indent_level);
}

int main() {
    char *xml_str = "<book>\n"
                    "  <title>The C Programming Language</title>\n"
                    "  <author>Brian W. Kernighan and Dennis M. Ritchie</author>\n"
                    "  <publisher>Prentice Hall</publisher>\n"
                    "  <year>1978</year>\n"
                    "</book>";
    /* Parse the XML string */
    xml_node *root = parse_xml(xml_str);
    /* Print the XML tree */
    print_xml(root, 0);
    /* Free memory */
    /* TODO: implement memory deallocation function */
    return 0;
}