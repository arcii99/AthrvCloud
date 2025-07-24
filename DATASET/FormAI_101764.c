//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xmlNode {
    char* tagName;
    char* value;
    struct xmlAttribute* attributes;
    struct xmlNode* child;
    struct xmlNode* sibling;
} xmlNode;

typedef struct xmlAttribute {
    char* name;
    char* value;
    struct xmlAttribute* next;
} xmlAttribute;

void parseOpeningTag(char* openingTag, xmlNode* node);
void parseClosingTag(char* closingTag, xmlNode* node);
void parseAttribute(char* attr, xmlNode* node);
void parseValue(char* value, xmlNode* node);

xmlNode* parseXML(char* xml) {
    xmlNode* rootNode = NULL;
    xmlNode* curNode = NULL;
    char* startTag = NULL;
    char* endTag = NULL;
    char* attr = NULL;
    char* value = NULL;
    int inOpeningTag = 0;
    int inClosingTag = 0;

    int i = 0;
    while (i < strlen(xml)) {
        if (xml[i] == '<' && xml[i + 1] != '/') {
            inOpeningTag = 1;
            startTag = &xml[i + 1];
        } else if (xml[i] == '<' && xml[i + 1] == '/') {
            inClosingTag = 1;
            endTag = &xml[i + 2];
        } else if (xml[i] == ' ' && inOpeningTag) {
            inOpeningTag = 0; 
            attr = &xml[i + 1];
        } else if (xml[i] == '>' && inOpeningTag) {
            inOpeningTag = 0;
            curNode = (xmlNode*)malloc(sizeof(xmlNode));
            curNode->attributes = NULL;
            curNode->child = NULL;
            curNode->sibling = NULL;
            parseOpeningTag(startTag, curNode);

            if (rootNode == NULL) {
                rootNode = curNode;
            } else {
                curNode->sibling = rootNode->child;
                rootNode->child = curNode;
            }

            startTag = NULL;
        } else if (xml[i] == '>' && inClosingTag) {
            inClosingTag = 0;
            curNode = rootNode;
            while (curNode != NULL) {
                if (strcmp(curNode->tagName, endTag) == 0) {
                    parseClosingTag(endTag, curNode);
                    break;
                }
                curNode = curNode->sibling;
            }

            endTag = NULL;
        } else if (xml[i] == '=' && attr != NULL) {
            parseAttribute(attr, curNode);
            attr = NULL;
        } else if (!inOpeningTag && !inClosingTag && xml[i] != '\r' && xml[i] != '\n') {
            value = &xml[i];
            while (xml[i] != '<') {
                i++;
            }
            xml[i] = '\0';

            parseValue(value, curNode);
            value = NULL;

            i--;
        }

        i++;
    }

    return rootNode;
}

void parseOpeningTag(char* openingTag, xmlNode* node) {
    char* p = strchr(openingTag, ' ');
    if (p != NULL) {
        *p = '\0';
        node->tagName = strdup(openingTag);
        parseAttribute(p + 1, node);
    } else {
        node->tagName = strdup(openingTag);
    }
}

void parseClosingTag(char* closingTag, xmlNode* node) {
    node->value = strdup(closingTag);
}

void parseAttribute(char* attr, xmlNode* node) {
    xmlAttribute* curAttr = NULL;
    char* p = strtok(attr, " =\"");

    while (p != NULL) {
        if (curAttr == NULL) {
            curAttr = (xmlAttribute*)malloc(sizeof(xmlAttribute));
            node->attributes = curAttr;
        } else {
            curAttr->next = (xmlAttribute*)malloc(sizeof(xmlAttribute));
            curAttr = curAttr->next;
        }

        curAttr->name = strdup(p);
        p = strtok(NULL, " =\"");
        curAttr->value = strdup(p);
        curAttr->next = NULL;

        p = strtok(NULL, " =\"");
    }
}

void parseValue(char* value, xmlNode* node) {
    node->value = strdup(value);
}

void printXML(xmlNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("<%s", node->tagName);
    xmlAttribute* curAttr = node->attributes;
    while (curAttr != NULL) {
        printf(" %s=\"%s\"", curAttr->name, curAttr->value);
        curAttr = curAttr->next;
    }

    if (node->child != NULL && node->value == NULL) {
        printf(">\n");
        xmlNode* child = node->child;
        while (child != NULL) {
            printXML(child, depth + 1);
            child = child->sibling;
        }
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tagName);
    } else if (node->value != NULL) {
        printf(">%s</%s>\n", node->value, node->tagName);
    } else {
        printf("/>\n");
    }
}

int main() {
    char* xml = "<root><person id=\"1\"><name>John Smith</name><age>31</age></person><person id=\"2\"><name>Jane Doe</name><age>27</age></person></root>";
    xmlNode* root = parseXML(xml);
    printXML(root, 0);
    return 0;
}