//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG 50
#define MAX_ATT 50
#define MAX_ATT_VAL 100
#define MAX_VAL 1000

typedef struct attribute {
    char name[MAX_ATT];
    char value[MAX_ATT_VAL];
    struct attribute* next;
} Attribute;

typedef struct node {
    char tag[MAX_TAG];
    Attribute* att_list;
    char value[MAX_VAL];
    struct node* parent;
    struct node* child;
    struct node* next;
} Node;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void parse_attribute(Attribute** att_list, char* str) {
    char* att = strtok(str, "=");
    char* val = strtok(NULL, "=");
    if (!att || !val) {
        error("Invalid attribute format.");
    }
    Attribute* new_att = (Attribute*)malloc(sizeof(Attribute));
    if (!new_att) {
        error("Memory allocation error.");
    }
    strcpy(new_att->name, att);
    strcpy(new_att->value, val);
    new_att->next = *att_list;
    *att_list = new_att;
}

Node* parse_xml(char* xml_str) {
    Node* root = NULL;
    Node* curr_node = NULL;
    char* tag = NULL;
    char* val = NULL;
    char* att = NULL;
    char* att_list = NULL;

    char* token = strtok(xml_str, "<>");
    while (token) {
        if (strcmp(token, "\n") == 0) {
            token = strtok(NULL, "<>");
            continue;
        }
        if (token[0] == '/') {
            curr_node = curr_node->parent;
        }
        else if (token[0] == '?') {
            if (!root) {
                root = (Node*)malloc(sizeof(Node));
                if (!root) {
                    error("Memory allocation error.");
                }
                curr_node = root;
            }
            att = strstr(token, "version=");
            if (att) {
                parse_attribute(&curr_node->att_list, att);
            }
        }
        else {
            Node* new_node = (Node*)malloc(sizeof(Node));
            if (!new_node) {
                error("Memory allocation error.");
            }
            if (!curr_node) {
                error("Invalid XML format: no root element.");
            }
            strcpy(new_node->tag, token);
            new_node->parent = curr_node;
            if (!curr_node->child) {
                curr_node->child = new_node;
            }
            else {
                Node* sibling = curr_node->child;
                while (sibling->next) {
                    sibling = sibling->next;
                }
                sibling->next = new_node;
            }
            curr_node = new_node;

            att_list = strstr(token, " ");
            if (att_list) {
                att = strtok(att_list, "\"");
                while (att) {
                    if (att[0] != ' ') {
                        parse_attribute(&curr_node->att_list, att);
                    }
                    att = strtok(NULL, "\"");
                    att = strtok(NULL, "\"");
                }
            }
        }

        val = strtok(NULL, "<>");
        if (val) {
            strcpy(curr_node->value, val);
        }
        token = strtok(NULL, "<>");
    }

    return root;
}

void print_attribute_list(Attribute* att_list) {
    while (att_list) {
        printf(" %s=\"%s\"", att_list->name, att_list->value);
        att_list = att_list->next;
    }
}

void print_xml(Node* root, int indent_level) {
    if (!root) {
        return;
    }
    for (int i = 0; i < indent_level; i++) {
        printf(" ");
    }
    printf("<%s", root->tag);
    print_attribute_list(root->att_list);
    if (strcmp(root->value, "") == 0 && !root->child) {
        printf("/>\n");
    }
    else {
        printf(">");
        if (strcmp(root->value, "") != 0) {
            printf("%s", root->value);
        }
        printf("\n");
        Node* child = root->child;
        while (child) {
            print_xml(child, indent_level + 2);
            child = child->next;
        }
        for (int i = 0; i < indent_level; i++) {
            printf(" ");
        }
        printf("</%s>\n", root->tag);
    }
}

int main() {
    char xml_str[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<bookstore>\n  <book category=\"children\">\n    <title>The Cat in the Hat</title>\n    <author>Dr. Seuss</author>\n    <year>1957</year>\n  </book>\n  <book category=\"cooking\">\n    <title>The Joy of Cooking</title>\n    <author>Irma S. Rombauer</author>\n    <author>Marion Rombauer Becker</author>\n    <year>1931</year>\n  </book>\n</bookstore>";
    Node* root = parse_xml(xml_str);
    print_xml(root, 0);
    return 0;
}