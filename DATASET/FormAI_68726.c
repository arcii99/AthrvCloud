//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct xml_node {
    char* name;
    struct xml_node* children;
    char* content;
    struct xml_node* next;
} xml_node;

void clear_buffer(char* buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

void skip_spaces(char** p) {
    while (**p == ' ') (*p)++;
}

void parse_tag(char** p, xml_node** current) {
    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);
    skip_spaces(p);
    int i = 0;
    while (**p != '>' && **p != ' ' && i < BUFFER_SIZE) {
        buffer[i++] = **p;
        (*p)++;
    }
    xml_node* new_node = malloc(sizeof(xml_node));
    new_node->name = strdup(buffer);
    new_node->content = NULL;
    new_node->next = NULL;
    new_node->children = NULL;
    if (*current != NULL) {
        if ((*current)->children == NULL) {
            (*current)->children = new_node;
        } else {
            xml_node* child = (*current)->children;
            while (child->next != NULL) {
                child = child->next;
            }
            child->next = new_node;
        }
    }
    *current = new_node;
    if (**p == ' ') {
        while (**p != '>') {
            (*p)++;
        }
    }
}

void parse_close_tag(char** p, xml_node** current) {
    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);
    int i = 0;
    (*p)++;
    skip_spaces(p);
    while (**p != '>' && i < BUFFER_SIZE) {
        buffer[i++] = **p;
        (*p)++;
    }
    if (strcmp(buffer, (*current)->name) != 0) {
        printf("Error: expected closing tag for %s\n", (*current)->name);
        exit(-1);
    }
    *current = (*current)->next;
}

void parse_content(char** p, xml_node* current) {
    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);
    int i = 0;
    while (**p != '<' && i < BUFFER_SIZE) {
        buffer[i++] = **p;
        (*p)++;
    }
    current->content = strdup(buffer);
}

void parse_node(char** p, xml_node** current) {
    while (**p != '\0') {
        if (**p == '<') {
            if ((*p)[1] == '/') {
                parse_close_tag(p, current);
            } else {
                parse_tag(p, current);
            }
        } else {
            parse_content(p, *current);
        }
    }
}

void free_node(xml_node* node) {
    if (node == NULL) {
        return;
    }

    free(node->name);
    free(node->content);

    xml_node* child = node->children;
    while (child != NULL) {
        xml_node* next_child = child->next;
        free_node(child);
        child = next_child;
    }
    free(node);
}

void print_node(xml_node* node, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("<%s>\n", node->name);
    if (node->content != NULL) {
        for (int i = 0; i < indent + 1; i++) {
            printf("  ");
        }
        printf("%s\n", node->content);
    }
    xml_node* child = node->children;
    while (child !=NULL) {
        print_node(child, indent + 1);
        child = child->next;
    }
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->name);
}

int main() {
    char buffer[BUFFER_SIZE];
    clear_buffer(buffer);
    xml_node* root = NULL;
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: could not open file example.xml\n");
        return -1;
    }
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        i += strlen(buffer);
    }
    fclose(fp);
    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: could not open file example.xml\n");
        return -1;
    }
    char* data = malloc(i);
    char* p = data;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        strcat(p, buffer);
        p += strlen(buffer);
    }
    fclose(fp);
    parse_node(&data, &root);
    free(data);
    print_node(root, 0);
    free_node(root);
    return 0;
}