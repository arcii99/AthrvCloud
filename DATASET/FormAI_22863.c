//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* key;
    char* value;
} XmlNode;

typedef struct XmlTag {
    char* name;
    int num_children;
    struct XmlTag** children;
    int num_attributes;
    XmlNode* attributes;
    char* inner_text;
} XmlTag;

XmlTag* parse_xml(char* xml_string) {
    // code to parse XML string and create a tree of XmlTags
}

int main() {
    char* xml_string = "<root><person name=\"John\" age=\"25\"><address>123 Main St.</address><city>New York</city></person></root>";
    XmlTag* root = parse_xml(xml_string);
    // code to interact with XmlTag tree and access data
    return 0;
}