//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTR 10

typedef struct {
    char* name;
    char* value;
} Attribute;

typedef struct {
    char* name;
    Attribute attrs[MAX_ATTR];
    int numAttrs;
} Element;

typedef struct {
    Element* elements;
    int numElements;
} Document;

void parseDocument(Document* doc, const char* xml) {
    int len = strlen(xml);
    if (len == 0) {
        printf("Error: empty XML document\n");
        exit(EXIT_FAILURE);
    }
    char* xmlCopy = malloc(len + 1);
    if (xmlCopy == NULL) {
        printf("Error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(xmlCopy, xml);
    char* token = strtok(xmlCopy, "<>"); // split on opening and closing tags
    int stackLen = 0;
    Element* stack[MAX_ATTR];
    stack[stackLen++] = NULL; // push the root element onto the stack
    while (token != NULL) {
        int tokenLen = strlen(token);
        if (tokenLen == 0) continue;
        if (token[0] == '/') { // closing tag
            if (stackLen == 1) {
                printf("Error: unmatched closing tag: %s\n", token);
                exit(EXIT_FAILURE);
            }
            Element* elem = stack[--stackLen];
            if (strcmp(elem->name, &token[1]) != 0) {
                printf("Error: expected closing tag for %s, got %s\n", elem->name, token);
                exit(EXIT_FAILURE);
            }
        } else { // opening tag
            Element* parent = stack[stackLen - 1];
            Element* elem = &doc->elements[doc->numElements++];
            memset(elem, 0, sizeof(Element));
            elem->name = malloc(tokenLen + 1);
            if (elem->name == NULL) {
                printf("Error: out of memory\n");
                exit(EXIT_FAILURE);
            }
            strcpy(elem->name, token);
            elem->numAttrs = 0;
            elem->attrs[0].name = NULL;
            elem->attrs[0].value = NULL;
            if (parent != NULL) {
                parent->attrs[parent->numAttrs].name = malloc(tokenLen + 1);
                if (parent->attrs[parent->numAttrs].name == NULL) {
                    printf("Error: out of memory\n");
                    exit(EXIT_FAILURE);
                }
                strcpy(parent->attrs[parent->numAttrs].name, token);
            } else {
                stack[stackLen++] = elem; // push the root element onto the stack
            }
            token = strtok(NULL, "<>"); // parse attributes
            while (token != NULL && *token != '/') {
                int tokenLen = strlen(token);
                if (token[0] == ' ') {
                    if (elem->numAttrs == MAX_ATTR - 1) {
                        printf("Error: too many attributes in %s\n", elem->name);
                        exit(EXIT_FAILURE);
                    }
                    Attribute* attr = &elem->attrs[elem->numAttrs++];
                    attr->name = ++token;
                    char* end = strchr(token, '=');
                    if (end == NULL) {
                        printf("Error: invalid attribute %s in %s\n", token, elem->name);
                        exit(EXIT_FAILURE);
                    }
                    *end = '\0';
                    ++end;
                    if (*end != '\"') {
                        printf("Error: invalid attribute %s in %s\n", attr->name, elem->name);
                        exit(EXIT_FAILURE);
                    }
                    ++end;
                    attr->value = end;
                    end = strchr(end, '\"');
                    if (end == NULL) {
                        printf("Error: invalid attribute %s in %s\n", attr->name, elem->name);
                        exit(EXIT_FAILURE);
                    }
                    *end = '\0';
                }
                token = strtok(NULL, "<>");
            }
            if (strcmp(token, "/") == 0) { // self-closing tag
                if (parent == NULL) {
                    printf("Error: invalid self-closing tag: %s\n", elem->name);
                    exit(EXIT_FAILURE);
                }
            } else {
                stack[stackLen++] = elem; // push the new element onto the stack
            }
        }
        token = strtok(NULL, "<>");
    }
    free(xmlCopy);
    if (stackLen != 1) {
        printf("Error: unclosed tag: %s\n", stack[stackLen - 1]->name);
        exit(EXIT_FAILURE);
    }
}

int main() {
    Document doc;
    doc.numElements = 0;
    doc.elements = malloc(sizeof(Element) * 100);
    if (doc.elements == NULL) {
        printf("Error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    const char* xml = "<bookstore>"
                     "<book category=\"COOKING\">"
                     "<title lang=\"en\">Everyday Italian</title>"
                     "<author>Giada De Laurentiis</author>"
                     "<year>2005</year>"
                     "<price>30.00</price>"
                     "</book>"
                     "</bookstore>";
    parseDocument(&doc, xml);
    for (int i = 0; i < doc.numElements; i++) {
        printf("Element %d:\n", i);
        Element* elem = &doc.elements[i];
        printf("  Name: %s\n", elem->name);
        for (int j = 0; j < elem->numAttrs; j++) {
            Attribute* attr = &elem->attrs[j];
            printf("  Attribute %d:\n", j);
            printf("    Name: %s\n", attr->name);
            printf("    Value: %s\n", attr->value);
        }
    }
    return 0;
}