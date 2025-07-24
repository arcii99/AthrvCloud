//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char* name;
    char** attributes;
    char* content;
    struct XMLNode** children;
    int num_attributes;
    int num_children;
} XMLNode;

char* get_next_token(char* start, char* end) {
    char* next = start;
    while (next < end && *next != '\n' && *next != '\t' && *next != ' ' && *next != '<' && *next != '>') {
        next++;
    }
    char* token = malloc(sizeof(char) * (next - start + 1));
    strncpy(token, start, next - start);
    token[next - start] = '\0';
    return token;
}

XMLNode* parse_xml(char* xml) {
    char* start = xml;
    char* end = start + strlen(xml);
    char* tag_start;
    char* tag_end;
    XMLNode* root = malloc(sizeof(XMLNode));
    root->num_attributes = root->num_children = 0;
    root->name = "";
    root->content = "";
    root->attributes = NULL;
    root->children = NULL;
    XMLNode** stack = malloc(sizeof(XMLNode*) * 100);
    int stack_top = -1;
    while (*start != '\0') {
        tag_start = strstr(start, "<");
        tag_end = strstr(start, ">");
        if (tag_start == NULL || tag_end == NULL) {
            printf("Error: Invalid XML\n");
            return NULL;
        }
        if (tag_start > start) {
            char* content = get_next_token(start, tag_start);
            if (strlen(content) > 0) {
                if (stack_top == -1) {
                    root->content = content;
                } else {
                    XMLNode* parent = stack[stack_top];
                    parent->children[parent->num_children - 1]->content = content;
                }
            }
            start = tag_start;
        }
        if (*tag_start == '<' && *(tag_start + 1) == '/') {
            stack_top--;
        } else if (*tag_end == '/') {
            char* tag = get_next_token(tag_start + 1, tag_end);
            XMLNode* node = malloc(sizeof(XMLNode));
            node->name = tag;
            node->num_children = node->num_attributes = 0;
            node->attributes = NULL;
            node->children = NULL;
            if (stack_top == -1) {
                printf("Error: Invalid XML\n");
                return NULL;
            }
            XMLNode* parent = stack[stack_top];
            parent->children[parent->num_children] = node;
            parent->num_children++;
        } else {
            char* tag = get_next_token(tag_start + 1, tag_end);
            XMLNode* node = malloc(sizeof(XMLNode));
            node->name = tag;
            node->num_children = node->num_attributes = 0;
            node->attributes = NULL;
            node->children = NULL;
            if (stack_top == -1) {
                root->children = malloc(sizeof(XMLNode*) * 100);
                root->children[0] = node;
                root->num_children++;
            } else {
                XMLNode* parent = stack[stack_top];
                parent->children = realloc(parent->children, sizeof(XMLNode*) * (parent->num_children + 1));
                parent->children[parent->num_children] = node;
                parent->num_children++;
            }
            stack[++stack_top] = node;
            start = tag_end + 1;
        }
    }
    return root;
}

void print_xml(XMLNode* root) {
    printf("<%s", root->name);
    int i;
    for (i = 0; i < root->num_attributes; i++) {
        printf(" %s=\"%s\"", root->attributes[i * 2], root->attributes[i * 2 + 1]);
    }
    if (strlen(root->content) > 0) {
        printf(">%s</%s>\n", root->content, root->name);
    } else if (root->num_children > 0) {
        printf(">\n");
        for (i = 0; i < root->num_children; i++) {
            print_xml(root->children[i]);
        }
        printf("</%s>\n", root->name);
    } else {
        printf("/>\n");
    }
}

int main() {
    char xml[] = "<books><book><title>Harry Potter</title><author>J.K. Rowling</author></book><book><title>The Hitchhiker's Guide to the Galaxy</title><author>Douglas Adams</author></book></books>";
    XMLNode* root = parse_xml(xml);
    print_xml(root);
    return 0;
}