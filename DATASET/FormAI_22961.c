//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* value;
} attribute;

typedef struct {
    char* tag_name;
    attribute** attributes;
    int num_attributes;
    char* text_content;
    struct node* parent;
    struct node** children;
    int num_children;
} node;

node* parse_xml(char* xml_string);
char* get_element_name(char* xml_string);
attribute* get_attributes(char* xml_string, int* i);
int count_attributes(char* xml_string);
char* get_tag_contents(char* xml_string);
char* get_text_content(char* xml_string);
void add_child(node* parent, node* child);
void print_xml(node* root);

int main() {
    char* xml_string = "<xml version='1.0'><book author='J.K. Rowling'><title>Harry Potter and the Philosopher's Stone</title><publisher>Bloomsbury</publisher></book></xml>";
    node* root = parse_xml(xml_string);
    print_xml(root);
    return 0;
}

node* parse_xml(char* xml_string) {
    node* root;
    node* current;
    int i = 0;

    while (xml_string[i] != '\0') {
        if (xml_string[i] == '<') {
            if (xml_string[i+1] == '/') {
                current = current->parent;
                i = i + strlen(get_element_name(&xml_string[i])) + 2; // skip to end of closing tag
            } else if (xml_string[i+1] == '?') {
                i = i + 2; // skip past XML declaration
            } else {
                node* new_node = malloc(sizeof(node));
                new_node->tag_name = get_element_name(&xml_string[i]);
                new_node->attributes = get_attributes(&xml_string[i], &(new_node->num_attributes));
                new_node->text_content = get_text_content(&xml_string[i]);
                new_node->num_children = 0;
                new_node->parent = current;
                new_node->children = malloc(sizeof(node*));

                if (current == NULL) {
                    root = new_node;
                } else {
                    add_child(current, new_node);
                }

                current = new_node;

                i = i + strlen(new_node->tag_name) + 1;

                if (new_node->num_attributes > 0) {
                    i = i + strlen(new_node->attributes[new_node->num_attributes-1]->value) + strlen(new_node->attributes[new_node->num_attributes-1]->name) + 3;
                }

                if (new_node->text_content != NULL) {
                    i = i + strlen(new_node->text_content);
                }

                i = i + 2; // skip past closing bracket of opening tag
            }
        } else {
            printf("Invalid format\n");
            exit(0);
        }
    }

    return root;
}

char* get_element_name(char* xml_string) {
    char* element_name = malloc(sizeof(char) * 20); // max element name length of 20 characters
    int i = 0;

    while (xml_string[i+1] != ' ' && xml_string[i+1] != '>') {
        element_name[i] = xml_string[i+1];
        i++;
    }

    element_name[i] = '\0';

    return element_name;
}

attribute* get_attributes(char* xml_string, int* i) {
    int num_attributes = count_attributes(xml_string);
    attribute** attributes = malloc(sizeof(attribute*) * num_attributes);
    char* temp_string = malloc(sizeof(char) * strlen(xml_string));
    int j = 0;
    int k = 0;

    while (j < strlen(xml_string)) {
        if (xml_string[j+1] == '>') {
            break;
        }

        if (xml_string[j] == ' ') {
            attributes[k] = malloc(sizeof(attribute));
            attributes[k]->name = malloc(sizeof(char) * 20);
            attributes[k]->value = malloc(sizeof(char) * 20);
            int l = 0;

            while (temp_string[l] != '=') {
                attributes[k]->name[l] = temp_string[l];
                l++;
            }

            attributes[k]->name[l] = '\0';

            l = l + 2;
            int m = 0;

            while (temp_string[l] != '"') {
                attributes[k]->value[m] = temp_string[l];
                l++;
                m++;
            }

            attributes[k]->value[m] = '\0';
            k++;
            *i = j;
        }

        temp_string[j] = xml_string[j];
        j++;
    }

    return attributes;
}

int count_attributes(char* xml_string) {
    int num_attributes = 0;
    int i = 0;

    while (xml_string[i+1] != '>') {
        if (xml_string[i] == ' ' && xml_string[i-1] != '/') {
            num_attributes++;
        }

        i++;
    }

    return num_attributes;
}

char* get_text_content(char* xml_string) {
    char* text_content = NULL;
    int i = 0;

    while (i < strlen(xml_string) && xml_string[i] != '<') {
        if (xml_string[i] != '\n' && xml_string[i] != '\t' && xml_string[i] != '\r') {
            if (text_content == NULL) {
                text_content = malloc(sizeof(char) * 100);
                text_content[0] = '\0';
            }

            strncat(text_content, &xml_string[i], 1);
        }

        i++;
    }

    return text_content;
}

void add_child(node* parent, node* child) {
    parent->num_children++;
    parent->children = realloc(parent->children, sizeof(node*) * parent->num_children);
    parent->children[parent->num_children-1] = child;
}

void print_xml(node* root) {
    printf("<%s", root->tag_name);

    for (int i = 0; i < root->num_attributes; i++) {
        printf(" %s='%s'", root->attributes[i]->name, root->attributes[i]->value);
    }

    printf(">");

    if (root->text_content != NULL) {
        printf("%s", root->text_content);
    }

    for (int i = 0; i < root->num_children; i++) {
        print_xml(root->children[i]);
    }

    printf("</%s>", root->tag_name);
}