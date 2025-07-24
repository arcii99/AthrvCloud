//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} Attribute;

typedef struct _Node {
    char* name;
    Attribute* attributes;
    int num_attributes;
    struct _Node** children;
    int num_children;
} Node;

Node* parse_xml(const char* input) {
    Node* root = NULL;
    Node* current_node = NULL;
    char* tag_start = NULL;
    char* attribute_start = NULL;
    bool inside_tag = false;
    bool inside_attribute = false;
    bool tag_closing = false;
    bool reading_tag_name = false;
    bool reading_attribute_name = false;
    bool reading_attribute_value = false;
    char tag_name[100];
    char attribute_name[100];
    char attribute_value[100];
    int current_attribute_index = 0;
    int num_children_read = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (!inside_tag && c == '<') {
            inside_tag = true;
            tag_start = &input[i];
            tag_closing = false;
            reading_tag_name = true;
            current_node = malloc(sizeof(Node));
            current_node->attributes = malloc(sizeof(Attribute) * 50);
            current_node->children = malloc(sizeof(Node*) * 50);
            current_attribute_index = 0;
            num_children_read = 0;
            current_node->num_attributes = 0;
            current_node->num_children = 0;
        }
        else if (inside_tag && reading_tag_name && !(c == '/' || c == ' ')) {
            tag_name[strlen(tag_name)] = c;
        }
        else if (inside_tag && reading_tag_name && (c == '/' || c == ' ')) {
            tag_name[strlen(tag_name)] = '\0';
            current_node->name = strdup(tag_name);
            reading_tag_name = false;
            reading_attribute_name = true;
        }
        else if (inside_tag && reading_attribute_name && !(c == '=')) {
            attribute_name[strlen(attribute_name)] = c;
        }
        else if (inside_tag && reading_attribute_name && (c == '=')) {
            reading_attribute_name = false;
            reading_attribute_value = true;
        }
        else if (inside_tag && reading_attribute_value && c == '\"') {
            if (inside_attribute) {
                Attribute* attribute = &current_node->attributes[current_attribute_index];
                attribute->value = strdup(attribute_value);
                current_node->num_attributes++;
                current_attribute_index++;
                inside_attribute = false;
                memset(&attribute_name, 0, sizeof(attribute_name));
                memset(&attribute_value, 0, sizeof(attribute_value));
            }
            else {
                inside_attribute = true;
            }
        }
        else if (inside_tag && reading_attribute_value) {
            attribute_value[strlen(attribute_value)] = c;
        }
        else if (inside_tag && c == '/') {
            tag_closing = true;
        }
        else if (inside_tag && c == '>') {
            inside_tag = false;
            if (!tag_closing) {
                if (root == NULL) {
                    root = current_node;
                }
                else {
                    current_node->num_children = num_children_read;
                    Node** children = current_node->children;
                    for (int j = 0; j < num_children_read; j++) {
                        Node* child = children[j];
                        if (child->name == NULL) {
                            free(child->attributes);
                            free(child->children);
                            free(child);
                        }
                    }
                    current_node = root;
                }
            }
            else {
                if (current_node->name == NULL) {
                    free(current_node->attributes);
                    free(current_node->children);
                    free(current_node);
                }
                current_node = root;
            }
            memset(&tag_name, 0, sizeof(tag_name));
        }
        else if (!inside_tag && current_node && isalnum(c)) {
            Node* child_node = malloc(sizeof(Node));
            child_node->name = NULL;
            child_node->attributes = NULL;
            child_node->children = NULL;
            child_node->num_attributes = 0;
            child_node->num_children = 0;
            char* child_input = &input[i];
            Node* child = parse_xml(child_input);
            if (child) {
                current_node->children[num_children_read] = child;
                num_children_read++;
            }
        }
    }

    return root;
}

int main() {
    const char* input = "<bookstore>\n"
                        "<book category=\"COOKING\">\n"
                        "  <title lang=\"en\">Everyday Italian</title>\n"
                        "  <author>Giada De Laurentiis</author>\n"
                        "  <year>2005</year>\n"
                        "  <price>30.00</price>\n"
                        "</book>\n"
                        "<book category=\"CHILDREN\">\n"
                        "  <title lang=\"en\">Harry Potter</title>\n"
                        "  <author>J K. Rowling</author>\n"
                        "  <year>2005</year>\n"
                        "  <price>29.99</price>\n"
                        "</book>\n"
                        "</bookstore>";

    Node* root = parse_xml(input);

    free(root->attributes);
    free(root->children);
    free(root);
    
    return 0;
}