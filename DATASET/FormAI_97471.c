//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length for the tags, attributes, and values
#define MAX_TAG_LEN 50
#define MAX_ATTR_LEN 50
#define MAX_VALUE_LEN 100

// Define the XML tag structure
typedef struct xml_tag {
    char name[MAX_TAG_LEN];
    int num_attr;
    char attr_names[MAX_ATTR_LEN][MAX_ATTR_LEN];
    char attr_values[MAX_VALUE_LEN][MAX_VALUE_LEN];
    struct xml_tag* children;
} xml_tag;

// Define the stack structure
typedef struct stack {
    int top;
    xml_tag* tags[100];
} stack;

// Initialize the stack
void init(stack* s) {
    s->top = -1;
}

// Push a tag onto the stack
void push(stack* s, xml_tag* tag) {
    if (s->top == 99) {
        printf("Stack overflow\n");
        exit(0);
    }
    s->tags[++s->top] = tag;
}

// Pop a tag off the stack
xml_tag* pop(stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(0);
    }
    return s->tags[s->top--];
}

// Parse the XML document
xml_tag* parse_xml(char* xml) {
    xml_tag* root = (xml_tag*) malloc(sizeof(xml_tag));
    xml_tag* curr = root;
    stack s;
    init(&s);
    char tag[MAX_TAG_LEN], attr[MAX_ATTR_LEN], value[MAX_VALUE_LEN];
    int tag_len = 0, attr_len = 0, value_len = 0;
    int in_tag = 0, in_attr = 0, in_value = 0, in_quotes = 0;
    int i;
    for (i = 0; i < strlen(xml); i++) {
        if (xml[i] == '<') {
            in_tag = 1;
            tag_len = 0;
        }
        else if (xml[i] == '>') {
            in_tag = 0;
            if (tag_len > 0) {
                tag[tag_len] = '\0';
                xml_tag* new_tag = (xml_tag*) malloc(sizeof(xml_tag));
                strcpy(new_tag->name, tag);
                new_tag->num_attr = 0;
                new_tag->children = NULL;
                if (curr == root) {
                    root = new_tag;
                }
                else {
                    push(&s, curr);
                    curr->children = new_tag;
                    curr = new_tag;
                }
            }
        }
        else if (in_tag) {
            if (xml[i] == ' ') {
                in_attr = 1;
                attr_len = 0;
            }
            else if (xml[i] == '/') {
                curr = pop(&s);
            }
            else {
                tag[tag_len++] = xml[i];
            }
        }
        else if (in_attr) {
            if (xml[i] == '=') {
                in_quotes = 1;
            }
            else if (xml[i] == '"' && in_quotes) {
                in_quotes = 0;
                value[value_len] = '\0';
                strcpy(curr->attr_names[curr->num_attr], attr);
                strcpy(curr->attr_values[curr->num_attr++], value);
                attr_len = 0;
                value_len = 0;
                in_attr = 0;
            }
            else if (in_quotes) {
                value[value_len++] = xml[i];
            }
            else if (!isspace(xml[i])) {
                attr[attr_len++] = xml[i];
            }
        }
        else {
            if (!isspace(xml[i])) {
                in_value = 1;
                value[value_len++] = xml[i];
            }
            else if (in_value) {
                in_value = 0;
                value[value_len] = '\0';
                xml_tag* new_tag = (xml_tag*) malloc(sizeof(xml_tag));
                strcpy(new_tag->name, "value");
                new_tag->num_attr = 0;
                strcpy(new_tag->attr_names[0], "value");
                strcpy(new_tag->attr_values[0], value);
                new_tag->children = NULL;
                curr->children = new_tag;
                value_len = 0;
            }
        }
    }
    return root;
}

// Print the XML document
void print_xml(xml_tag* tag, int level) {
    int i, j;
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s", tag->name);
    for (i = 0; i < tag->num_attr; i++) {
        printf(" %s=\"%s\"", tag->attr_names[i], tag->attr_values[i]);
    }
    if (tag->children == NULL) {
        printf("/>\n");
    }
    else {
        printf(">\n");
        xml_tag* child = tag->children;
        while (child != NULL) {
            print_xml(child, level + 1);
            child = child->children;
        }
        for (i = 0; i < level; i++) {
            printf("  ");
        }
        printf("</%s>\n", tag->name);
    }
}

int main() {
    char xml[] = "<person name=\"John Doe\">\n<age>30</age>\n<occupation>Engineer</occupation>\n</person>";
    xml_tag* root = parse_xml(xml);
    print_xml(root, 0);
    return 0;
}