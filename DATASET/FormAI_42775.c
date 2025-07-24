//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTRIBUTE_COUNT 10

typedef struct {
    char* name;
    char* value;
} Attribute;

typedef struct _xml_node {
    char* name;
    char* text;
    Attribute attributes[MAX_ATTRIBUTE_COUNT];
    int attribute_count;
    struct _xml_node* children[10];
    struct _xml_node* parent;
} XMLNode;

XMLNode* parse_node(char* buffer, int buffer_size, int* position) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    memset(node, 0, sizeof(XMLNode));
    int i = *position;
    while (i < buffer_size) {
        if (buffer[i] == '<') {
            if (buffer[i+1] == '/') {
                // closing tag
                i += 2;
                int j = 0;
                char name[50];
                while (buffer[i] != '>') {
                    name[j++] = buffer[i++];
                }
                name[j] = '\0';
                if (strcmp(name, node->name) != 0) {
                    printf("Error: closing tag does not match opening tag.\n");
                    exit(1);
                }
                *position = i + 1;
                return node;
            } else {
                // opening tag
                i++;
                int j = 0;
                char name[50];
                while (buffer[i] != ' ' && buffer[i] != '>') {
                    name[j++] = buffer[i++];
                }
                name[j] = '\0';
                node->name = strdup(name);
                if (buffer[i] == ' ') {
                    // attributes
                    while (buffer[i] != '>') {
                        if (buffer[i] != ' ') {
                            j = 0;
                            char attr_name[50];
                            while (buffer[i] != '=') {
                                attr_name[j++] = buffer[i++];
                            }
                            attr_name[j] = '\0';
                            i++;
                            if (buffer[i] == '\"' || buffer[i] == '\'') {
                                char quote = buffer[i++];
                                j = 0;
                                char attr_value[50];
                                while (buffer[i] != quote) {
                                    attr_value[j++] = buffer[i++];
                                }
                                attr_value[j] = '\0';
                                node->attributes[node->attribute_count].name = strdup(attr_name);
                                node->attributes[node->attribute_count].value = strdup(attr_value);
                                node->attribute_count++;
                                i++;
                            } else {
                                printf("Error: attribute value not surrounded by quotes.\n");
                                exit(1);
                            }
                        }
                        i++;
                    }
                }
                if (buffer[i] == '>') {
                    // children or text
                    i++;
                    int text_start = i;
                    int j = 0;
                    while (i < buffer_size) {
                        if (buffer[i] == '<') {
                            if (buffer[i+1] == '/') {
                                // end of node
                                node->text = (char*)malloc(i - text_start + 1);
                                memcpy(node->text, buffer + text_start, i - text_start);
                                node->text[i - text_start] = '\0';
                                *position = i;
                                return node;
                            } else {
                                // new child node
                                XMLNode* child = parse_node(buffer, buffer_size, &i);
                                child->parent = node;
                                node->children[node->attribute_count] = child;
                            }
                        }
                        i++;
                    }
                }
            }
        } else if (buffer[i] == '>') {
            i++;
        } else {
            printf("Error: unexpected character '%c' found.\n", buffer[i]);
            exit(1);
        }
    }

    printf("Error: unexpected end of string.\n");
    exit(1);
}

XMLNode* parse_xml(char* buffer, int buffer_size) {
    int position = 0;
    XMLNode* root = parse_node(buffer, buffer_size, &position);
    return root;
}

void print_indent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

void print_node(XMLNode* node, int indent) {
    print_indent(indent);
    printf("<%s", node->name);
    for (int i = 0; i < node->attribute_count; i++) {
        printf(" %s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    if (node->text != NULL) {
        printf(">%s</%s>\n", node->text, node->name);
    } else if (node->children[0] != NULL) {
        printf(">\n");
        for (int i = 0; i < 10 && node->children[i] != NULL; i++) {
            print_node(node->children[i], indent + 1);
        }
        print_indent(indent);
        printf("</%s>\n", node->name);
    } else {
        printf("/>\n");
    }
}

int main() {
    char buffer[] = "<xml>\n"
                    "  <person name=\"John\" age=\"30\"/>\n"
                    "  <person name=\"Mary\" age=\"25\">\n"
                    "    <address street=\"123 Main St\" city=\"Anytown\" state=\"CA\"/>\n"
                    "  </person>\n"
                    "</xml>\n";
    XMLNode* root = parse_xml(buffer, strlen(buffer));
    print_node(root, 0);

    return 0;
}