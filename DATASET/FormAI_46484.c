//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure representing an XML tag
typedef struct XMLTag {
    char* name;
    char** attributes;
    int attr_count;
    char** children;
    int child_count;
} XMLTag;

// Function to create a new XML Tag
XMLTag* newTag(char* tag_name) {
    XMLTag* tag = (XMLTag*) malloc(sizeof(XMLTag));
    tag->name = strdup(tag_name);
    tag->attributes = (char**) malloc(sizeof(char*) * MAX_SIZE);
    tag->children = (char**) malloc(sizeof(char*) * MAX_SIZE);
    tag->attr_count = 0;
    tag->child_count = 0;
    return tag;
}

// Function to add an attribute to an XML Tag
void addAttribute(XMLTag* tag, char* attribute) {
    tag->attributes[tag->attr_count++] = strdup(attribute);
}

// Function to add a child tag to an XML Tag
void addChild(XMLTag* tag, char* child) {
    tag->children[tag->child_count++] = strdup(child);
}

// Function to parse an XML string and return the corresponding XML Tag
XMLTag* parseXML(char* xml) {
    char token[MAX_SIZE];
    char* ptr = xml;
    int len = strlen(xml);

    XMLTag* root = NULL;
    XMLTag* current = NULL;
    while (ptr < xml + len) {
        if (*ptr == '<') {
            // tag start found
            ptr++;
            char* tag_name = token;
            while (*ptr != '>' && *ptr != ' ') {
                *tag_name++ = *ptr++;
            }
            *tag_name = '\0';

            XMLTag* tag = newTag(token);
            if (current) {
                addChild(current, tag_name);
            } else {
                root = tag;
            }
            current = tag;

            // parse attributes
            while (*ptr != '>') {
                if (*ptr == ' ') {
                    // attribute start found
                    ptr++;
                    char* attr_name = token;
                    while (*ptr != '=') {
                        *attr_name++ = *ptr++;
                    }
                    *attr_name = '\0';

                    ptr++; // skip the '=' character
                    char* attr_value = token;
                    if (*ptr == '\'') {
                        ptr++; // skip the opening quote
                        while (*ptr != '\'') {
                            *attr_value++ = *ptr++;
                        }
                        ptr++; // skip the closing quote
                    } else if (*ptr == '\"') {
                        ptr++; // skip the opening quote
                        while (*ptr != '\"') {
                            *attr_value++ = *ptr++;
                        }
                        ptr++; // skip the closing quote
                    } else {
                        while (*ptr != ' ') {
                            *attr_value++ = *ptr++;
                        }
                    }
                    *attr_value = '\0';

                    char* attr = (char*) malloc(sizeof(char) * (MAX_SIZE + MAX_SIZE));
                    snprintf(attr, MAX_SIZE + MAX_SIZE, "%s=\"%s\"", attr_name, attr_value);
                    addAttribute(current, attr);
                    free(attr);
                } else {
                    ptr++; // skip any whitespace
                }
            }
            ptr++; // skip the closing '>' character
        } else {
            // text node found
            char* text = token;
            while (*ptr != '<') {
                *text++ = *ptr++;
            }
            *text = '\0';

            char* child = strdup(token);
            addChild(current, child);
        }
    }

    return root;
}

// Function to print out an XML Tag
void printTag(XMLTag* tag, int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("<%s", tag->name);
    for (int i = 0; i < tag->attr_count; i++) {
        printf(" %s", tag->attributes[i]);
    }
    if (tag->child_count == 0) {
        printf("/>\n");
    } else {
        printf(">\n");
        for (int i = 0; i < tag->child_count; i++) {
            XMLTag* child = parseXML(tag->children[i]);
            printTag(child, level + 1);
        }
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("</%s>\n", tag->name);
    }
}

int main() {
    char* xml = "<bookstore>\n"
                "  <book category=\"cooking\" cover=\"paperback\">\n"
                "    <title lang=\"en\">Everyday Italian</title>\n"
                "    <author>Giada De Laurentiis</author>\n"
                "    <year>2005</year>\n"
                "    <price>30.00</price>\n"
                "  </book>\n"
                "  <book category=\"children\" cover=\"hardcover\">\n"
                "    <title lang=\"en\">Harry Potter</title>\n"
                "    <author>J.K. Rowling</author>\n"
                "    <year>1997</year>\n"
                "    <price>42.50</price>\n"
                "  </book>\n"
                "</bookstore>";
    XMLTag* root = parseXML(xml);
    printTag(root, 0);
    return 0;
}