//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LEN 100
#define MAX_ATTRS 10
#define MAX_ATTR_NAME_LEN 50
#define MAX_ATTR_VALUE_LEN 50

typedef struct attribute {
    char name[MAX_ATTR_NAME_LEN];
    char value[MAX_ATTR_VALUE_LEN];
} attribute;

typedef struct element {
    char tag[MAX_TAG_LEN];
    attribute attrs[MAX_ATTRS];
    int num_attrs;
    struct element *children;
    struct element *next;
} element;

// Function to parse the next token
char *parse_token(char *input, char *token) {
    while (*input != '\0' && isspace(*input))
        input++;

    if (*input == '\0')
        return NULL;

    int i = 0;
    while (*input != '\0' && !isspace(*input))
        token[i++] = *(input++);

    token[i] = '\0';

    return input;
}

// Function to parse the attributes of an element
void parse_attributes(char *input, attribute attrs[], int *num_attrs) {
    char attr_name[MAX_ATTR_NAME_LEN];
    char attr_value[MAX_ATTR_VALUE_LEN];
    while (*input != '>' && *input != '\0') {
        input = parse_token(input, attr_name);
        if (input == NULL) {
            printf("Error: Malformed attribute\n");
            exit(EXIT_FAILURE);
        }

        input = parse_token(input, attr_value);
        if (input == NULL) {
            printf("Error: Malformed attribute\n");
            exit(EXIT_FAILURE);
        }

        strcpy(attrs[*num_attrs].name, attr_name);
        strcpy(attrs[*num_attrs].value, attr_value);
        (*num_attrs)++;
    }
}

// Function to parse an XML element
element parse_element(char **input_ptr) {
    char *input = *input_ptr;
    char tag[MAX_TAG_LEN];

    input = parse_token(input, tag);
    if (input == NULL) {
        printf("Error: Malformed element\n");
        exit(EXIT_FAILURE);
    }

    element elem;
    strcpy(elem.tag, tag);
    elem.num_attrs = 0;

    parse_attributes(input, elem.attrs, &elem.num_attrs);

    // Check if this is a self-closing tag
    if (*input == '/') {
        input += 2; // skip past "/>"
        elem.children = NULL;
        elem.next = NULL;
        return elem;
    }

    input++; // skip past ">"

    // Parse the children of this element
    element *child = malloc(sizeof(element));
    element *prev = NULL;
    while (*input != '\0' && *input != '<') {
        *input_ptr = input;
        *child = parse_element(input_ptr);
        child->next = NULL;

        if (prev == NULL)
            elem.children = child;
        else
            prev->next = child;

        prev = child;
        child = malloc(sizeof(element));
    }

    *input_ptr = input;

    input += 2; // skip past "</"

    // Make sure the closing tag matches the opening tag
    char closing_tag[MAX_TAG_LEN];
    input = parse_token(input, closing_tag);
    if (input == NULL || strcmp(closing_tag, tag) != 0) {
        printf("Error: Mismatched tags\n");
        exit(EXIT_FAILURE);
    }

    input++; // skip past ">"

    return elem;
}

int main() {
    char *xml = "<people><person name=\"Alice\" age=\"25\"><child name=\"Bob\" age=\"3\"/></person><person name=\"Charlie\" age=\"42\"/></people>";
    element root = parse_element(&xml);

    // Print out the parsed XML
    element *elem = &root;
    while (elem != NULL) {
        printf("<%s", elem->tag);
        for (int i = 0; i < elem->num_attrs; i++)
            printf(" %s=\"%s\"", elem->attrs[i].name, elem->attrs[i].value);
        printf(">");

        if (elem->children != NULL) {
            printf("\n");
            element *child = elem->children;
            while (child != NULL) {
                child = child->next;
            }
        } else {
            printf("</%s>\n", elem->tag);
        }

        elem = elem->next;
    }

    return 0;
}