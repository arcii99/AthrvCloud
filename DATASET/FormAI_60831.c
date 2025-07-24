//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char* tag;
    char* value;
    struct Node* child;
    struct Node* sibling;
};

struct Node* parseXML(char* xml) {
    // initialize stack to hold nodes
    struct Node* stack[100];
    int top = -1;
    
    // initialize root node
    struct Node* root = NULL;
    
    // loop through XML string
    for (int i=0; i<strlen(xml); i++) {
        // check if opening tag
        if (xml[i] == '<') {
            // check if closing tag
            if (xml[i+1] == '/') {
                // pop node from stack
                top--;
            } else {
                // get tag name
                char* tag = strtok(&xml[i+1], ">");
                
                // create new node
                struct Node* node = (struct Node*) malloc(sizeof(struct Node));
                node->tag = strdup(tag);
                node->value = NULL;
                node->child = NULL;
                node->sibling = NULL;
                
                // add node to parent
                if (top == -1) {
                    root = node;
                } else {
                    struct Node* parent = stack[top];
                    if (parent->child == NULL) {
                        parent->child = node;
                    } else {
                        struct Node* sibling = parent->child;
                        while (sibling->sibling != NULL) {
                            sibling = sibling->sibling;
                        }
                        sibling->sibling = node;
                    }
                }
                
                // push node onto stack
                stack[++top] = node;
            }
        } else if (xml[i] != '\n' && xml[i] != ' ') {
            // get node value
            char* value = strtok(&xml[i], "<");
            
            // set node value
            struct Node* node = stack[top];
            node->value = strdup(value);
            
            // skip ahead to next tag
            while (xml[i] != '<') {
                i++;
            }
            i--;
        }
    }
    
    return root;
}

int main() {
    // example XML string
    char* xml = "<bookstore>\n"
                "  <book category=\"COOKING\">\n"
                "    <title lang=\"en\">Everyday Italian</title>\n"
                "    <author>Giada De Laurentiis</author>\n"
                "    <year>2005</year>\n"
                "    <price>30.00</price>\n"
                "  </book>\n"
                "  <book category=\"CHILDREN\">\n"
                "    <title lang=\"en\">Harry Potter</title>\n"
                "    <author>J.K. Rowling</author>\n"
                "    <year>2000</year>\n"
                "    <price>29.99</price>\n"
                "  </book>\n"
                "</bookstore>";
                
    // parse XML
    struct Node* root = parseXML(xml);
    
    // print XML tree
    printf("%s\n", root->tag);
    struct Node* node = root->child;
    while (node != NULL) {
        printf("  %s\n", node->tag);
        printf("    %s: %s\n", node->child->tag, node->child->value);
        printf("    %s: %s\n", node->child->sibling->tag, node->child->sibling->value);
        printf("    %s: %s\n", node->child->sibling->sibling->tag, node->child->sibling->sibling->value);
        printf("    %s: %s\n", node->child->sibling->sibling->sibling->tag, node->child->sibling->sibling->sibling->value);
        node = node->sibling;
    }
    
    return 0;
}