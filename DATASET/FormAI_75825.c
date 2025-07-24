//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1024

typedef enum {
    TAG_START,
    TAG_END,
    ATTR_START,
    ATTR_END,
    ATTR_KEY,
    ATTR_VALUE,
    TEXT
} token_t;

typedef struct {
    token_t type;
    char value[MAX_SIZE];
} token;

typedef struct {
    char *key;
    char *value;
} attribute;

typedef struct {
    char *tag_name;
    attribute *attributes;
    int attributes_count;
    int indentation_level;
    struct html_node_t *children;
    struct html_node_t *parent;
} html_node;

typedef struct html_node_t {
    html_node node;
    struct html_node_t *next;
} html_node_t;

void parse_html(char *html);
html_node_t *parse_tag(html_node_t *parent, char *tag);
void add_child(html_node_t *parent, html_node_t *child);
html_node_t *create_node(char *tag_name);
void print_node(html_node_t *node);
void print_indentation(int indentation_level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: html-beautifier <file.html>");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Unable to open file %s", argv[1]);
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    int size = ftell(file);

    fseek(file, 0L, SEEK_SET);

    char *html = (char *) malloc(size * sizeof(char));
    fread(html, sizeof(char), size, file);
    fclose(file);

    parse_html(html);

    return 0;
}

void parse_html(char *html) {
    html_node_t *root_node = create_node("body");
    html_node_t *current_node = root_node;

    int i = 0;
    while (html[i]) {
        char c = html[i];
        if (c == '<') {
            i++;
            if (html[i] == '/') {
                i++;
                char tag_name[MAX_SIZE];
                int j = 0;
                while (html[i] != '>') {
                    tag_name[j++] = html[i++];
                }
                tag_name[j] = '\0';
                if (strcmp(tag_name, current_node->node.tag_name) != 0) {
                    printf("Error: Invalid HTML");
                    return;
                }
                current_node = current_node->node.parent;
            } else {
                char tag[MAX_SIZE];
                int j = 0;
                while (html[i] != '>') {
                    tag[j++] = html[i++];
                }
                tag[j] = '\0';
                current_node = parse_tag(current_node, tag);
            }
        } else if (!isspace(c)) {
            i++;
            char text[MAX_SIZE];
            int j = 0;
            while (html[i] != '<' && isspace(html[i]) == 0) {
                text[j++] = html[i++];
            }
            text[j] = '\0';
            html_node_t *text_node = create_node("#text");
            strncpy(text_node->node.attributes[0].value, text, MAX_SIZE);
            add_child(current_node, text_node);
            i--;
        } else {
            i++;
        }
    }

    print_node(root_node);
}

html_node_t *parse_tag(html_node_t *parent, char *tag) {
    html_node_t *node = create_node(tag);
    add_child(parent, node);

    int i = 0;
    while (tag[i]) {
        char c = tag[i];
        if (c == ' ') {
            i++;
            continue;
        }
        if (c == '/') {
            return parent;
        }

        int j = 0;
        char key[MAX_SIZE];
        char value[MAX_SIZE];

        while (tag[i] != '=' && tag[i] != ' ') {
            key[j++] = tag[i++];
        }
        key[j] = '\0';

        j = 0;
        i++; // skip the '=' character
        while (tag[i] != ' ' && tag[i] != '\"') {
            i++;
        }
        char delimiter = tag[i];
        i++; // skip the delimiter

        while (tag[i] != delimiter) {
            value[j++] = tag[i++];
        }
        value[j] = '\0';

        attribute *attr = (attribute *) malloc(sizeof(attribute));
        attr->key = (char *) malloc(strlen(key) + 1);
        attr->value = (char *) malloc(strlen(value) + 1);
        strncpy(attr->key, key, strlen(key) + 1);
        strncpy(attr->value, value, strlen(value) + 1);

        node->node.attributes[node->node.attributes_count++] = *attr;
    }

    return node;
}

void add_child(html_node_t *parent, html_node_t *child) {
    child->node.parent = parent;
    if (parent->node.children == NULL) {
        parent->node.children = child;
    } else {
        html_node_t *current_node = parent->node.children;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = child;
    }
}

html_node_t *create_node(char *tag_name) {
    html_node_t *node = (html_node_t *) malloc(sizeof(html_node_t));
    node->node.tag_name = (char *) malloc(strlen(tag_name) + 1);
    strncpy(node->node.tag_name, tag_name, strlen(tag_name) + 1);
    node->node.attributes = (attribute *) malloc(MAX_SIZE * sizeof(attribute));
    node->node.children = NULL;
    node->node.attributes_count = 0;
    node->node.indentation_level = 0;
    return node;
}

void print_node(html_node_t *node) {
    if (strcmp(node->node.tag_name, "#text") == 0) {
        print_indentation(node->node.indentation_level);
        printf("%s\n", node->node.attributes[0].value);
    } else {
        print_indentation(node->node.indentation_level);
        printf("<%s", node->node.tag_name);
        for (int i = 0; i < node->node.attributes_count; i++) {
            printf(" %s=\"%s\"", node->node.attributes[i].key, node->node.attributes[i].value);
        }
        printf(">\n");
        html_node_t *current_node = node->node.children;
        while (current_node != NULL) {
            current_node->node.indentation_level = node->node.indentation_level + 1;
            print_node(current_node);
            current_node = current_node->next;
        }
        print_indentation(node->node.indentation_level);
        printf("</%s>\n", node->node.tag_name);
    }
}

void print_indentation(int indentation_level) {
    for (int i = 0; i < indentation_level; i++) {
        printf("  ");
    }
}