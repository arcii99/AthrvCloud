//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xmlNode {
    char *tag;
    struct xmlNode *children;
    struct xmlNode *sibling;
} XmlNode;

void parseXml(char *xml, XmlNode **rootNode);
void addChildToNode(XmlNode **parentNode, XmlNode *childNode);
void printXmlNode(XmlNode *xmlNode);
void freeXmlNode(XmlNode *xmlNode);

int main() {
    char *xml = "<person><name>John</name><age>30</age><hobby>Soccer</hobby></person>";
    XmlNode *rootNode;
    parseXml(xml, &rootNode);
    printf("XML Parsed Successfully!\n");
    printXmlNode(rootNode);
    freeXmlNode(rootNode);
    return 0;
}

void parseXml(char *xml, XmlNode **rootNode) {
    XmlNode *currentNode = NULL;
    char *token;
    char *endToken;
    char *startOfToken;
    char *endOfToken;
    int tokenLength;
    token = strtok(xml, "<");
    while (token != NULL) {
        endToken = strstr(token, ">");
        
        if (token[0] == '/') { // This is a closing tag
            tokenLength = endToken - &token[1];
            char *closingTag = (char *) malloc(tokenLength + 1);
            strncpy(closingTag, &token[1], tokenLength);
            closingTag[tokenLength] = '\0';

            if (currentNode->tag != NULL && strcmp(currentNode->tag, closingTag) == 0) {
                currentNode = currentNode->children;
            } else {
                currentNode = currentNode->sibling;
            }

            free(closingTag);
        } else { // This is an opening tag
            tokenLength = endToken - token;
            char *openingTag = (char *) malloc(tokenLength + 1);
            strncpy(openingTag, token, tokenLength);
            openingTag[tokenLength] = '\0';

            XmlNode *newNode = (XmlNode *) malloc(sizeof(XmlNode));
            newNode->tag = openingTag;
            newNode->children = NULL;
            newNode->sibling = NULL;

            if (*rootNode == NULL) {
                *rootNode = newNode;
                currentNode = *rootNode;
            } else if (currentNode->children == NULL) {
                currentNode->children = newNode;
                currentNode = currentNode->children;
            } else {
                addChildToNode(&currentNode, newNode);
                currentNode = newNode;
            }
        }

        startOfToken = endToken + 1;
        token = strtok(startOfToken, "<");
        endOfToken = strstr(token, ">");
        tokenLength = endOfToken - token;
        char *text = (char *) malloc(tokenLength + 1);
        strncpy(text, token, tokenLength);
        text[tokenLength] = '\0';
        currentNode->tag = text;
    }
}

void addChildToNode(XmlNode **parentNode, XmlNode *childNode) {
    if ((*parentNode)->sibling == NULL) {
        (*parentNode)->sibling = childNode;
    } else {
        addChildToNode(&((*parentNode)->sibling), childNode);
    }
}

void printXmlNode(XmlNode *xmlNode) {
    if (xmlNode == NULL) {
        return;
    }

    printf("<%s>", xmlNode->tag);

    if (xmlNode->children != NULL) {
        printf("\n");
        printXmlNode(xmlNode->children);
    } else {
        printf("%s\n", xmlNode->tag);
    }

    if (xmlNode->sibling != NULL) {
        printXmlNode(xmlNode->sibling);
    }

    printf("</%s>\n", xmlNode->tag);
}

void freeXmlNode(XmlNode *xmlNode) {
    if (xmlNode == NULL) {
        return;
    }

    XmlNode *children = xmlNode->children;
    XmlNode *sibling = xmlNode->sibling;
    free(xmlNode->tag);
    free(xmlNode);

    if (children != NULL) {
        freeXmlNode(children);
    }

    if (sibling != NULL) {
        freeXmlNode(sibling);
    }
}