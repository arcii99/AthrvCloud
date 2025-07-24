//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char tag[50];
    char data[50];
    struct Node *parent;
    struct Node *sibling;
    struct Node *child;
}Node;

Node *stack[50]; //stack to keep track of current nodes while parsing
int top = -1; //initialize stack top to -1

void push(Node *node){
    stack[++top] = node;
}

Node *pop(){
    return stack[top--];
}

Node *createNode(char* tag, char* data){ //function to create a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->data, data);
    newNode->parent = newNode->sibling = newNode->child = NULL;
    return newNode;
}

void addChild(Node *parent, Node *child){ //function to add child node to a parent node
    if(parent->child == NULL){
        parent->child = child;
    }
    else{
        Node *temp = parent->child;
        while(temp->sibling != NULL){
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
    child->parent = parent;
}

Node *parseXML(char* xml){ //function to parse the XML data and create a tree of nodes
    Node *root = NULL, *currentNode = NULL;
    char *token = strtok(xml, "<>"); //tokenize the XML data by '<' and '>'
    while(token != NULL){
        if(token[0] == '/'){ //if tag is closing tag, pop the node from stack
            currentNode = pop();
        }
        else if(token[strlen(token)-1] == '/'){ //if tag is self-closing, create node and add it as a child
            Node *newNode = createNode(token, "");
            if(currentNode != NULL){
                addChild(currentNode, newNode);
            }
            else{
                root = newNode;
            }
        }
        else if(token[0] != '?'){ //for opening tag, create node and add it as a child
            Node *newNode = createNode(token, "");
            if(currentNode != NULL){
                addChild(currentNode, newNode);
            }
            push(newNode);
            currentNode = newNode;
        }
        token = strtok(NULL, "<>");
    }
    return root;
}

void printTree(Node *root, int level){ //function to print the tree of nodes
    if(root != NULL){
        for(int i=0; i<level; i++){
            printf("\t");
        }
        printf("%s", root->tag);
        if(strcmp(root->data, "") != 0){
            printf(" - %s", root->data);
        }
        printf("\n");
        printTree(root->child, level+1);
        printTree(root->sibling,level);
    }
}

int main(){
    char xml[] = "<bookstore><book><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author><price>20.00</price></book><book><title>To Kill a Mockingbird</title><author>Harper Lee</author><price>15.00</price></book></bookstore>";
    Node *root = parseXML(xml);
    printTree(root, 0);
    return 0;
}