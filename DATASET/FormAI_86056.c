//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 20
#define MAX_ATTRIBUTES 10

typedef struct {
    char name[MAX_TAG_SIZE];
    char value[MAX_TAG_SIZE];
} Attribute;

typedef struct {
    char tag[MAX_TAG_SIZE];
    Attribute attributes[MAX_ATTRIBUTES];
    int num_attributes;
    char content[MAX_TAG_SIZE];
} XMLNode;

void print_node(XMLNode node) {
    printf("<%s", node.tag);

    for (int i = 0; i < node.num_attributes; i++) {
        printf(" %s=\"%s\"", node.attributes[i].name, node.attributes[i].value);
    }

    if (strlen(node.content) == 0) {
        printf("/>\n");
    } else {
        printf(">%s</%s>\n", node.content, node.tag);
    }
}

int main() {
    XMLNode root;
    strcpy(root.tag, "root");
    root.num_attributes = 1;
    strcpy(root.attributes[0].name, "version");
    strcpy(root.attributes[0].value, "1.0");
    strcpy(root.content, "");

    XMLNode child;
    strcpy(child.tag, "child");
    child.num_attributes = 2;
    strcpy(child.attributes[0].name, "id");
    strcpy(child.attributes[0].value, "1");
    strcpy(child.attributes[1].name, "name");
    strcpy(child.attributes[1].value, "John");
    strcpy(child.content, "Hello, World!");

    root.content[0] = '\0';
    print_node(root);
    print_node(child);

    return 0;
}