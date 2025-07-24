//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store the XML attributes
typedef struct {
    char name[100];
    char value[100];
} attribute;

// Structure to store the XML tags
typedef struct xmltag {
    char name[100];
    attribute attr[10];
    char data[200];
    struct xmltag *child[10];
    int child_count;
} xmltag;

// Function to parse the XML data
void parseXml(char *xmlData, xmltag *root);
void parseTag(char *tagData, xmltag *tag);
void parseAttr(char *attrData, attribute *attr);
void addchild(xmltag *parent, xmltag *child);

int main() {
    char xmlData[] = "<bookstore>\n"
                    "  <book category=\"web\" price=\"29.99\">\n"
                    "    <title lang=\"en\">Learning XML</title>\n"
                    "    <author>Erik T. Ray</author>\n"
                    "  </book>\n"
                    "  <book category=\"web\" price=\"39.95\">\n"
                    "    <title lang=\"en\">XQuery Kick Start</title>\n"
                    "    <author>James McGovern</author>\n"
                    "    <author>Per Bothner</author>\n"
                    "    <author>Kurt Cagle</author>\n"
                    "    <author>James Linn</author>\n"
                    "    <author>Vaidyanathan Nagarajan</author>\n"
                    "  </book>\n"
                    "</bookstore>\n";

    xmltag root;
    strcpy(root.name, "root");

    // Start parsing the XML data
    parseXml(xmlData, &root);

    printf("Parsed %d child tags for %s tag!\n", root.child_count, root.name);
    return 0;
}

// Function to parse the XML data
void parseXml(char *xmlData, xmltag *root) {
    char *token1 = NULL, *token2 = NULL;
    char *xmlTag = strtok_r(xmlData, "\n", &token1);

    xmltag *parent = root, child;

    while (xmlTag != NULL) {
        if (xmlTag[0] == '<' && xmlTag[1] == '/') {
            // Closing tag encountered
            parent = (xmltag *) parent->child[parent->child_count - 1];
        } else if (xmlTag[0] == '<') {
            // Opening tag encountered
            parseTag(xmlTag, &child);
            addchild(parent, &child);
            parent = (xmltag *) parent->child[parent->child_count - 1];
        } else {
            // Text data encountered
            if (xmlTag[0] != '\0') {
                strcpy(parent->data, xmlTag);
            }
        }

        xmlTag = strtok_r(NULL, "\n", &token1);
    }
}

// Function to parse the XML tag
void parseTag(char *tagData, xmltag *tag) {
    char *token1 = NULL, *token2 = NULL;

    // Get the tag name
    token1 = strtok_r(tagData, "<>/ \t\n", &token2);
    strcpy(tag->name, token1);

    // Get the attributes
    while (token1 != NULL) {
        if (token1[strlen(token1) - 1] == '>') {
            break;
        }

        token1 = strtok_r(NULL, "<>/ \t\n", &token2);

        if (token1 != NULL) {
            parseAttr(token1, &tag->attr[tag->child_count]);
            tag->child_count++;
        }
    }
}

// Function to parse the attribute data
void parseAttr(char *attrData, attribute *attr) {
    char *token1 = NULL, *token2 = NULL;

    // Get the attribute name
    token1 = strtok_r(attrData, "=", &token2);
    strcpy(attr->name, token1);

    // Get the attribute value
    token1 = strtok_r(NULL, "\"", &token2);
    token1 = strtok_r(NULL, "\"", &token2);
    strcpy(attr->value, token1);
}

// Function to add a child tag to the parent tag
void addchild(xmltag *parent, xmltag *child) {
    parent->child[parent->child_count] = child;
    parent->child_count++;
}