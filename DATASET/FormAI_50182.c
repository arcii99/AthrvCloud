//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_XML_STRING_SIZE 100

struct element {
    char name[MAX_XML_STRING_SIZE];
    char value[MAX_XML_STRING_SIZE];
    struct element *children;
    struct element *next;
};

void parse_xml(char xml_string[], struct element *parent_element);
void print_element(struct element element);
void print_children(struct element element);

int main(void) {
    char xml_string[MAX_XML_STRING_SIZE] = "<root><person><name>John Doe</name><age>25</age></person><person><name>Jane Doe</name><age>23</age></person></root>";

    struct element root;
    strcpy(root.name, "root");
    root.next = NULL;
    root.children = NULL;

    parse_xml(xml_string, &root);

    print_element(root);

    return 0;
}

void parse_xml(char xml_string[], struct element *parent_element) {
    char *token;
    char *name;
    char *value;
    const char *delim = "<>/";
    struct element *new_element;
    bool is_closing_tag;

    token = strtok(xml_string, delim);

    while (token != NULL) {
        is_closing_tag = (token[0] == '/');

        if (!is_closing_tag) {
            new_element = malloc(sizeof(struct element));
            strcpy(new_element->name, token);
            new_element->next = parent_element->children;
            parent_element->children = new_element;

            value = strtok(NULL, delim);
            
            if (value != NULL && strcmp(value, "") != 0) {
                strcpy(new_element->value, value);
            } else {
                strcpy(new_element->value, "");
            }

            name = strtok(NULL, delim);
            parse_xml(name, new_element);
        }

        token = strtok(NULL, delim);

        if (is_closing_tag && strcmp(token, parent_element->name) == 0) {
            break;
        }
    }
}

void print_element(struct element element) {
    printf("<%s>", element.name);
    printf("%s", element.value);
    print_children(element);
    printf("</%s>\n", element.name);
}

void print_children(struct element element) {
    if (element.children == NULL) {
        return;
    }

    struct element *current_element = element.children;

    while (current_element != NULL) {
        print_element(*current_element);
        current_element = current_element->next;
    }
}