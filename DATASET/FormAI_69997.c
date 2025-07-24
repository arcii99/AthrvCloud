//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_SIZE 100
#define MAX_ATTR_SIZE 100
#define MAX_ATTR_COUNT 10

typedef struct attribute {
    char name[MAX_ATTR_SIZE];
    char value[MAX_ATTR_SIZE];
} attribute;

typedef struct node {
    char tag[MAX_TAG_SIZE];
    attribute attrs[MAX_ATTR_COUNT];
    int attr_count;
    char content[MAX_TAG_SIZE];
    struct node* children[MAX_TAG_SIZE];
    int child_count;
} node;

int parse_element(char* xml_document, int pos, node* parent);
void print_node(node* n, int depth);

int main() {
    char xml_document[] = "<bookstore>\n"
                          "  <book category=\"cooking\">\n"
                          "    <title lang=\"en\">Everyday Italian</title>\n"
                          "    <author>Giada De Laurentiis</author>\n"
                          "    <year>2005</year>\n"
                          "    <price>30.00</price>\n"
                          "  </book>\n"
                          "  <book category=\"children\">\n"
                          "    <title lang=\"en\">Harry Potter</title>\n"
                          "    <author>J.K. Rowling</author>\n"
                          "    <year>2005</year>\n"
                          "    <price>21.99</price>\n"
                          "  </book>\n"
                          "</bookstore>\n";

    node root = {0};
    parse_element(xml_document, 0, &root);
    print_node(&root, 0);

    return 0;
}

int parse_element(char* xml_document, int pos, node* parent) {
    node current_node = {0};
    int content_start = 0;

    // Get tag name
    if (xml_document[pos] != '<') {
        return 0;
    }
    pos++;
    int tag_start = pos;
    while (isalpha(xml_document[pos]) || xml_document[pos] == '/') {
        pos++;
    }
    int tag_end = pos;
    memcpy(current_node.tag, xml_document + tag_start, tag_end - tag_start);

    // Check for end tag
    if (current_node.tag[0] == '/') {
        return 0;
    }

    // Get attributes
    while (xml_document[pos] != '>') {
        int attr_start = pos;
        while (isalpha(xml_document[pos])) {
            pos++;
        }
        int attr_end = pos;
        if (attr_end - attr_start > 0) {
            char attr_name[MAX_ATTR_SIZE] = "";
            char attr_value[MAX_ATTR_SIZE] = "";
            memcpy(attr_name, xml_document + attr_start, attr_end - attr_start);

            // Check for attribute values
            if (xml_document[pos] == '=') {
                pos++;
                if (xml_document[pos] == '\"' || xml_document[pos] == '\'') {
                    char quote_char = xml_document[pos];
                    pos++;
                    int value_start = pos;
                    while (xml_document[pos] != quote_char) {
                        pos++;
                    }
                    int value_end = pos;
                    memcpy(attr_value, xml_document + value_start, value_end - value_start);
                    current_node.attrs[current_node.attr_count++] = (attribute){attr_name, attr_value};
                }
            }
        }
        pos++;
    }

    // Check for self-closing tag
    if (xml_document[pos - 1] == '/') {
        parent->children[parent->child_count++] = &current_node;
        return pos;
    }

    pos++;

    // Get content and child nodes
    while (xml_document[pos] != '<') {
        if (xml_document[pos] != '\n' && !isspace(xml_document[pos])) {
            if (content_start == 0) {
                content_start = pos;
            }
        } else {
            if (content_start > 0) {
                int content_end = pos;
                memcpy(current_node.content, xml_document + content_start, content_end - content_start);
                content_start = 0;
            }
        }
        pos++;
    }

    // Add child nodes
    int child_start = pos;
    while (xml_document[pos] != '\0') {
        if (xml_document[pos] == '<') {
            int new_pos = parse_element(xml_document, pos, &current_node);
            pos = new_pos;
        } else if (xml_document[pos] == '>') {
            pos++;
            break;
        } else {
            pos++;
        }
    }

    parent->children[parent->child_count++] = &current_node;
    return pos;
}

void print_node(node* n, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s", n->tag);
    for (int i = 0; i < n->attr_count; i++) {
        printf(" %s=\"%s\"", n->attrs[i].name, n->attrs[i].value);
    }
    if (n->child_count > 0) {
        printf(">\n");
        if (strlen(n->content) > 0) {
            for (int i = 0; i <= depth; i++) printf("  ");
            printf("%s\n", n->content);
        }
        for (int i = 0; i < n->child_count; i++) {
            print_node(n->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", n->tag);
    } else {
        if (strlen(n->content) > 0) {
            printf(">%s</%s>\n", n->content, n->tag);
        } else {
            printf(" />\n");
        }
    }
}