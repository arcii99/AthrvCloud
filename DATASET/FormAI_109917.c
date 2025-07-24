//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_LENGTH 100

struct Node { 
    char tag[MAX_LENGTH]; 
    char content[MAX_LENGTH]; 
    struct Node* parent; 
    struct Node* child; 
    struct Node* nextSibling; 
}; 

struct Node* createNode(char* tag, char* content) { 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    strcpy(node->tag, tag); 
    strcpy(node->content, content); 
    node->parent = NULL; 
    node->child = NULL; 
    node->nextSibling = NULL;
    return node; 
} 

struct Node* parseXML(char* xml) { 
    struct Node* root = NULL; 
    struct Node* currNode = NULL; 
    char* token = strtok(xml, "<>"); 
    while (token != NULL) { 
        if (strcmp(token, "/") == 0) { 
            currNode = currNode->parent; 
        } else if (token[0] == '?') { 
            // ignore declaration 
        } else if (root == NULL) { 
            root = createNode(token, ""); 
            currNode = root; 
        } else if (token[0] == '/') {
            // close tag 
            currNode = currNode->parent; 
        } else { 
            // open tag 
            char* contentToken = strtok(NULL, "<>"); 
            struct Node* newNode = createNode(token, contentToken); 
            if (currNode->child == NULL) { 
                currNode->child = newNode; 
            } else { 
                struct Node* sibling = currNode->child; 
                while (sibling->nextSibling != NULL) { 
                    sibling = sibling->nextSibling; 
                } 
                sibling->nextSibling = newNode; 
            } 
            newNode->parent = currNode; 
            if (contentToken[0] != '\0') { 
                currNode = newNode; 
            } 
        } 
        token = strtok(NULL, "<>"); 
    } 
    return root; 
} 

void printTree(struct Node* node, int depth) { 
    printf("%.*s%s%s\n", depth*2, "                      ", "<", node->tag); 
    if (node->content[0] != '\0') { 
        printf("%.*s%s\n", (depth+1)*2, "                      ", node->content); 
    } 
    struct Node* child = node->child; 
    while (child != NULL) { 
        printTree(child, depth+1); 
        child = child->nextSibling; 
    } 
    printf("%.*s%s%s\n", depth*2, "                      ", "</", node->tag); 
} 

int main() { 
    char xml[] = "<root><parent1>hello</parent1><parent2><child>world</child></parent2></root>"; 
    struct Node* root = parseXML(xml); 
    printTree(root, 0); 
    return 0; 
}