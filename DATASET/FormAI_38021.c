//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_tag {
    char* name;
    char* content;
    int content_len;
    struct xml_tag* children;
    int children_len;
} xml_tag;

void print_tag(xml_tag* tag, int indent_level) {
    int i;
    for (i = 0; i < indent_level; i++) {
        printf("  ");
    }
    printf("<%s>", tag->name);
    if (tag->content_len > 0) {
        printf("%s", tag->content);
    } else {
        printf("\n");
        int i;
        for (i = 0; i < tag->children_len; i++) {
            print_tag(&(tag->children[i]), indent_level + 1);
        }
        for (i = 0; i < indent_level; i++) {
            printf("  ");
        }
    }
    printf("</%s>\n", tag->name);
}

xml_tag* parse_xml(char* input, int input_len) {
    xml_tag* root = malloc(sizeof(xml_tag));
    int curr_pos = 0;
    int start_pos;
    int i;
    while (curr_pos < input_len) {
        start_pos = curr_pos;
        while (input[curr_pos] != '<') {
            curr_pos++;
        }
        if (curr_pos > start_pos) {
            root->content = malloc((curr_pos - start_pos + 1) * sizeof(char));
            strncpy(root->content, input + start_pos, curr_pos - start_pos);
            root->content[curr_pos - start_pos] = '\0';
            root->content_len = curr_pos - start_pos;
        }
        start_pos = curr_pos;
        while (input[curr_pos] != '>') {
            curr_pos++;
        }
        if (input[start_pos + 1] == '/') {
            break;
        } else {
            xml_tag* child = malloc(sizeof(xml_tag));
            child->name = malloc((curr_pos - start_pos - 1) * sizeof(char));
            strncpy(child->name, input + start_pos + 1, curr_pos - start_pos - 1);
            child->name[curr_pos - start_pos - 1] = '\0';
            child->content = NULL;
            child->content_len = 0;
            child->children = NULL;
            child->children_len = 0;
            root->children_len++;
            root->children = realloc(root->children, (root->children_len) * sizeof(xml_tag));
            root->children[root->children_len - 1] = *child;
            free(child);
            curr_pos++;
            xml_tag* curr_child = &root->children[root->children_len - 1];
            while (strncmp(input + curr_pos, "</", 2) != 0) {
                xml_tag* new_child = parse_xml(input + curr_pos, input_len - curr_pos);
                curr_child->children_len++;
                curr_child->children = realloc(curr_child->children, (curr_child->children_len) * sizeof(xml_tag));
                curr_child->children[curr_child->children_len - 1] = *new_child;
                free(new_child);
            }
            curr_pos += strlen(curr_child->name) + 3;
        }
    }
    root->name = "root";
    return root;
}

int main() {
    char* input = "<root>\n  <person>\n    <name>Alice</name>\n    <age>26</age>\n  </person>\n  <person>\n    <name>Bob</name>\n    <age>31</age>\n  </person>\n</root>\n";
    xml_tag* root = parse_xml(input, strlen(input));
    print_tag(root, 0);
    return 0;
}