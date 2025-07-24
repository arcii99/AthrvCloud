//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define XML node structure
typedef struct Xml_Node {
    char *tag_name;
    char *value;
    struct Xml_Node *children;
    struct Xml_Node *next_sibling;
    struct Xml_Node *parent;
} Xml_Node;

// Function to create new XML node
Xml_Node *newXmlNode(char *tag_name, char *value, Xml_Node *parent) {
    Xml_Node *node = (Xml_Node *)malloc(sizeof(Xml_Node));
    node->tag_name = strdup(tag_name);
    node->value = strdup(value);
    node->children = NULL;
    node->next_sibling = NULL;
    node->parent = parent;
    return node;
}

// Function to add child node to parent node
void addChild(Xml_Node *parent, Xml_Node *child) {
    if (parent->children == NULL) {
        parent->children = child;
    }
    else {
        Xml_Node *cur = parent->children;
        while (cur->next_sibling != NULL) {
            cur = cur->next_sibling;
        }
        cur->next_sibling = child;
    }
}

// Function to parse XML string
Xml_Node *parseXml(char *xml) {
    Xml_Node *root = NULL;
    Xml_Node *cur = NULL;
    char *tag_name = NULL;
    char *value = NULL;
    char *token = strtok(xml, "<>");
    char *last_token = NULL;
    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            cur = cur->parent;
        }
        else if (strncmp(token, "?xml", 4) == 0) {
            // ignore
        }
        else if (strncmp(token, "!--", 3) == 0) {
            // parse comment
            last_token = token;
            while (strcmp(last_token, "--") != 0) {
                last_token = token;
                token = strtok(NULL, "<>");
            }
        }
        else if (strncmp(token, "!", 1) == 0) {
            // parse CDATA
            last_token = token;
            while (strcmp(last_token, "]]") != 0) {
                last_token = token;
                token = strtok(NULL, "<>");
            }
        }
        else if (strcmp(token, "?") != 0) {
            if (cur == NULL) {
                // create new root node
                tag_name = token;
                root = newXmlNode(tag_name, "", NULL);
                cur = root;
            }
            else {
                // create new child node
                if (strcmp(last_token, "/") == 0) {
                    tag_name = last_token;
                }
                else {
                    tag_name = token;
                }
                value = strtok(NULL, "<>");
                if (value == NULL) {
                    value = "";
                }
                Xml_Node *child = newXmlNode(tag_name, value, cur);
                addChild(cur, child);
                if (strcmp(last_token, "/") != 0) {
                    cur = child;
                }
            }
        }
        last_token = token;
        token = strtok(NULL, "<>");
    }
    return root;
}

int main() {
    char *xml = "<people><person><name>John Doe</name><age>30</age><job>Engineer</job></person><person><name>Jane Doe</name><age>25</age><job>Teacher</job></person></people>";
    Xml_Node *root = parseXml(xml);
    Xml_Node *cur = root;
    while (cur != NULL) {
        printf("Tag Name: %s\n", cur->tag_name);
        printf("Value: %s\n\n", cur->value);
        cur = cur->children;
    }
    return 0;
}