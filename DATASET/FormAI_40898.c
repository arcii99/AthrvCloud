//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    char *name;
    Attribute *attributes;
    char *text;
    struct Node **children;
    int numOfAttributes;
    int numOfChildren;
} Node;

Node *parse(const char *xml, int size) {
    Node *root = (Node *) malloc(sizeof(Node));
    root->name = NULL;
    root->attributes = NULL;
    root->text = NULL;
    root->children = NULL;
    root->numOfAttributes = 0;
    root->numOfChildren = 0;
    
    char *buffer = (char *) calloc(size, sizeof(char));
    char *tag = (char *) calloc(size, sizeof(char));
    char *attrName = (char *) calloc(size, sizeof(char));
    char *attrValue = (char *) calloc(size, sizeof(char));
    int bufferIndex = 0;
    int tagIndex = 0;
    int attrNameIndex = 0;
    int attrValueIndex = 0;
    int i = 0;
    
    Node **currentNode = &root;
    while (i < size) {
        buffer[bufferIndex] = xml[i];
        if (xml[i] == '<') {
            bufferIndex = 0;
            tagIndex = 0;
            attrNameIndex = 0;
            attrValueIndex = 0;
            i++;
            if (xml[i] != '/') {
                while (xml[i] != '>' && i < size) {
                    tag[tagIndex++] = xml[i++];
                    if (xml[i] == ' ') {
                        tag[tagIndex++] = '\0';
                        i++;
                        while (xml[i] != '\"' && i < size) {
                            attrName[attrNameIndex++] = xml[i++];
                        }
                        i++;
                        while (xml[i] != '\"' && i < size) {
                            attrValue[attrValueIndex++] = xml[i++];
                        }
                        Attribute attribute;
                        attribute.name = (char *) malloc((attrNameIndex + 1) * sizeof(char));
                        attribute.value = (char *) malloc((attrValueIndex + 1) * sizeof(char));
                        strcpy(attribute.name, attrName);
                        strcpy(attribute.value, attrValue);
                        (*currentNode)->attributes = (Attribute *) realloc((*currentNode)->attributes, ((*currentNode)->numOfAttributes + 1) * sizeof(Attribute));
                        (*currentNode)->attributes[(*currentNode)->numOfAttributes++] = attribute;
                        attrNameIndex = 0;
                        attrValueIndex = 0;
                        attrName[0] = '\0';
                        attrValue[0] = '\0';
                    }
                }
                tag[tagIndex++] = '\0';
                Node *node = (Node *) malloc(sizeof(Node));
                node->name = (char *) malloc((tagIndex + 1) * sizeof(char));
                strcpy(node->name, tag);
                node->attributes = NULL;
                node->text = NULL;
                node->children = NULL;
                node->numOfAttributes = 0;
                node->numOfChildren = 0;
                (*currentNode)->children = (Node **) realloc((*currentNode)->children, ((*currentNode)->numOfChildren + 1) * sizeof(Node *));
                (*currentNode)->children[(*currentNode)->numOfChildren++] = node;
                currentNode = &node;
                tagIndex = 0;
                tag[0] = '\0';
            } else {
                while (xml[i] != '>' && i < size) {
                    tag[tagIndex++] = xml[i++];
                }
                tag[tagIndex - 1] = '\0';
                if (strcmp((*currentNode)->name, tag) == 0) {
                    currentNode = &root;
                } else {
                    currentNode = &((*currentNode)->children[(*currentNode)->numOfChildren - 1]);
                }
                tagIndex = 0;
                tag[0] = '\0';
            }
        } else if (xml[i] == '>') {
            buffer[bufferIndex++] = '\0';
            if (strlen(buffer) > 0) {
                (*currentNode)->text = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
                strcpy((*currentNode)->text, buffer);
            }
            buffer[0] = '\0';
            bufferIndex = 0;
        } else {
            bufferIndex++;
            i++;
        }
    }
    
    free(buffer);
    free(tag);
    free(attrName);
    free(attrValue);
    
    return root;
}

void printNode(Node *node) {
    printf("<%s", node->name);
    for (int i = 0; i < node->numOfAttributes; i++) {
        printf(" %s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    if (node->numOfChildren > 0 || node->text != NULL) {
        printf(">");
        printf("%s", node->text);
        for (int i = 0; i < node->numOfChildren; i++) {
            printNode(node->children[i]);
        }
        printf("</%s>", node->name);
    } else {
        printf("/>");
    }
}

int main() {
    const char *xml = "<bookstore><book category=\"cooking\"><title lang=\"en\">Everyday Italian</title><author>Giada De Laurentiis</author><year>2005</year><price>30.00</price></book><book category=\"children\"><title lang=\"en\">Harry Potter</title><author>J K. Rowling</author><year>2005</year><price>29.99</price></book><book category=\"web\"><title lang=\"en\">Learning XML</title><author>Erik T. Ray</author><year>2003</year><price>39.95</price></book></bookstore>";
    Node *root = parse(xml, strlen(xml));
    printNode(root);
    return 0;
}