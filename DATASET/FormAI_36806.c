//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing XML data
typedef struct xmldata {
    char *tag;
    char *value;
    struct xmldata *child;
    struct xmldata *sibling;
} xmldata;

// Recursive function to parse XML data
xmldata *parseXML(char *data) {
    xmldata *node = NULL;
    char *start = strstr(data, "<");
    char *end = NULL;
    if (start) {
        end = strstr(start, ">");
        if (end) {
            node = (xmldata *) malloc(sizeof(xmldata));
            node->tag = (char *) malloc(end - start);
            strncpy(node->tag, start+1, end-start-1);
            node->tag[end-start-1] = '\0';
            if (end[1] != '<') {
                node->value = (char *) malloc(strlen(end+1)+1);
                strcpy(node->value, end+1);
                node->child = node->sibling = NULL;
            } else {
                node->value = NULL;
                node->child = parseXML(end+1);
                if (node->child) {
                    node->sibling = parseXML((char *) node->child->tag);
                    if (node->sibling) {
                        node->sibling->child = parseXML((char *) node->sibling->tag);
                    }
                }
            }
        }
    }
    return node;
}

// Function to print XML data
void printXML(xmldata *node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("<%s>", node->tag);
        if (node->value) printf("%s", node->value);
        printf("\n");
        printXML(node->child, depth+1);
        printXML(node->sibling, depth);
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", node->tag);
    }
}

int main() {
    char *xml = "<root><node1>value1</node1><node2><node3>value3</node3><node4></node4></node2></root>";
    xmldata *data = parseXML(xml);
    printXML(data, 0);
    return 0;
}