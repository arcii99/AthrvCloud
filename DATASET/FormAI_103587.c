//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define TAG_SIZE 32

typedef struct XMLNode {
    char tag[TAG_SIZE];
    char value[MAX_SIZE];
    struct XMLNode* child;
    struct XMLNode* sibling;
} XMLNode;

void print_tree(XMLNode* node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    print_tree(node->child, level + 1);
    print_tree(node->sibling, level);
}

XMLNode* parse_element(FILE* fp) {
    char buffer[MAX_SIZE];
    char tag[TAG_SIZE];
    char value[MAX_SIZE];
    int index = 0;
    int is_closing = 0;

    // read the start tag
    char c = fgetc(fp);
    if (c == EOF) {
        return NULL;
    }
    if (c == '/') {
        is_closing = 1;
        c = fgetc(fp);
    }
    if (c == EOF) {
        return NULL;
    }
    while (c != '>' && index < TAG_SIZE - 1) {
        if (c == ' ') {
            c = fgetc(fp);
            continue;
        }
        tag[index++] = c;
        c = fgetc(fp);
    }
    tag[index] = '\0';

    // read the value, if any
    index = 0;
    while (c != '<' && c != EOF) {
        value[index++] = c;
        c = fgetc(fp);
    }
    value[index] = '\0';

    if (is_closing) {
        return NULL;
    }

    // allocate memory for the new node
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strcpy(node->tag, tag);
    strcpy(node->value, value);
    node->child = NULL;
    node->sibling = NULL;

    // read children
    while (1) {
        XMLNode* child = parse_element(fp);
        if (child == NULL) {
            break;
        }

        // add child to parent
        if (node->child == NULL) {
            node->child = child;
        } else {
            XMLNode* sibling = node->child;
            while (sibling->sibling != NULL) {
                sibling = sibling->sibling;
            }
            sibling->sibling = child;
        }
    }

    // read end tag
    index = 0;
    c = fgetc(fp);
    while (c != '>' && index < TAG_SIZE - 1) {
        tag[index++] = c;
        c = fgetc(fp);
    }
    tag[index] = '\0';

    if (strcmp(node->tag, tag) != 0) {
        printf("Error: mismatched tag '%s' for node '%s'\n", tag, node->tag);
        return NULL;
    }

    return node;
}

int main() {
    FILE* fp = fopen("example.xml", "r");
    XMLNode* root = parse_element(fp);
    fclose(fp);
    print_tree(root, 0);
    return 0;
}