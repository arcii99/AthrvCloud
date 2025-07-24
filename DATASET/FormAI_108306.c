//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to represent the XML nodes
typedef struct xml_node {
    char name[20];
    char* value;
    struct xml_node* children;
} xml_node;

// Function to create a new XML node
xml_node* create_node(char* name, char* value) {
    xml_node* node = (xml_node*)malloc(sizeof(xml_node));
    strcpy(node->name, name);
    node->value = (char*)malloc(strlen(value)+1);
    strcpy(node->value, value);
    node->children = NULL;
    return node;
}

// Function to add a child node to an XML node
void add_child(xml_node* parent, xml_node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        xml_node* cur = parent->children;
        while (cur->children != NULL) {
            cur = cur->children;
        }
        cur->children = child;
    }
}

// Function to print an XML node and all of its children
void print_node(xml_node* node, int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>", node->name);
    if (node->value != NULL) {
        printf("%s", node->value);
    }
    printf("\n");
    xml_node* cur = node->children;
    while (cur != NULL) {
        print_node(cur, level+1);
        cur = cur->children;
    }
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->name);
}

int main() {
    char* xml_string = "<xml><title>Example XML Document</title><author>John Smith</author><body><p>This is an example paragraph.</p><p>This is another example paragraph.</p></body></xml>";

    int i = 0, len = strlen(xml_string);
    xml_node* root = NULL, *cur = NULL;
    char name[20], value[100], buffer[100];

    // Loop through the XML string
    while (i < len) {
        if (xml_string[i] == '<') {
            i++;
            int j = 0;
            while (xml_string[i] != '>' && j < 20) {
                name[j] = xml_string[i];
                i++; j++;
            }
            name[j] = '\0';
            i++;
            if (xml_string[i] != '<') {
                int k = 0;
                while (xml_string[i] != '>' && k < 100) {
                    buffer[k] = xml_string[i];
                    i++; k++;
                }
                buffer[k] = '\0';
                cur = create_node(name, buffer);
            } else {
                cur = create_node(name, NULL);
            }
            if (root == NULL) {
                root = cur;
            } else {
                add_child(root, cur);
            }
        } else {
            i++;
        }
    }

    print_node(root, 0);

    return 0;
}