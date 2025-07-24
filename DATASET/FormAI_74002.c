//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define structure for XML node
typedef struct xml_node_struct {
    char* tag_name;
    char* tag_value;
    struct xml_node_struct* children_head;
    struct xml_node_struct* children_tail;
    struct xml_node_struct* next_sibling;
} xml_node;

// Define function to create a new XML node with given tag name and value
xml_node* create_xml_node(char* tag_name, char* tag_value) {
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->tag_name = strdup(tag_name);
    node->tag_value = strdup(tag_value);
    node->children_head = NULL;
    node->children_tail = NULL;
    node->next_sibling = NULL;
    return node;
}

// Define function to add a child node to an XML node
void add_child_node(xml_node* parent_node, xml_node* child_node) {
    if (parent_node->children_head == NULL) {
        parent_node->children_head = child_node;
        parent_node->children_tail = child_node;
    } else {
        parent_node->children_tail->next_sibling = child_node;
        parent_node->children_tail = child_node;
    }
}

// Define function to parse XML input and create XML nodes
xml_node* parse_xml_input(char* xml_input) {

    // Create root node to hold all other nodes
    xml_node* root_node = create_xml_node("root", "");

    // Define stack to hold parent nodes during parsing
    xml_node* stack[100];
    int stack_top = 0;
    stack[stack_top] = root_node;

    // Define state machine variables
    bool in_tag = false;
    bool in_value = false;
    bool in_comment = false;
    bool in_attribute = false;

    // Define variables to hold tag and value strings during parsing
    char tag_str[100];
    char value_str[100];
    int tag_str_pos = 0;
    int value_str_pos = 0;

    // Parse XML input character by character
    for (int i = 0; i < strlen(xml_input); i++) {
        char c = xml_input[i];

        // Check for beginning of a comment
        if (c == '<' && xml_input[i+1] == '!' && xml_input[i+2] == '-' && xml_input[i+3] == '-') {
            in_comment = true;
        }

        // Check for end of a comment
        if (in_comment && c == '-' && xml_input[i+1] == '-' && xml_input[i+2] == '>') {
            in_comment = false;
            i += 2;
            continue;
        }

        // Ignore characters inside comments
        if (in_comment) {
            continue;
        }

        // Check for beginning of a tag
        if (!in_tag && !in_value && c == '<') {
            in_tag = true;
            tag_str_pos = 0;
            memset(tag_str, 0, sizeof tag_str);
            continue;
        }

        // Check for end of a tag
        if (in_tag && !in_value && (isspace(c) || c == '>')) {
            in_tag = false;

            // Get tag name and value (if any)
            char* tag_name = tag_str;
            char* tag_value = "";
            if (value_str_pos > 0) {
                tag_value = value_str;
            }

            // Create new node with this tag name and value
            xml_node* node = create_xml_node(tag_name, tag_value);

            // Add node as child of current parent
            xml_node* parent = stack[stack_top];
            add_child_node(parent, node);

            // Push node onto stack as new parent
            stack_top++;
            stack[stack_top] = node;

            // Reset value string
            value_str_pos = 0;
            memset(value_str, 0, sizeof value_str);

            // If this is a self-closing tag, pop it right back off the stack
            if (c == '/') {
                stack_top--;
            }

            continue;
        }

        // Check for beginning of a value
        if (!in_tag && !in_value && !in_attribute) {
            in_value = true;
            value_str_pos = 0;
            memset(value_str, 0, sizeof value_str);
            continue;
        }

        // Check for end of a value
        if (in_value && c == '<' && !in_attribute) {
            in_value = false;

            // Get value string and add it to the current node
            xml_node* node = stack[stack_top];
            node->tag_value = strdup(value_str);

            // Reset value string
            value_str_pos = 0;
            memset(value_str, 0, sizeof value_str);

            continue;
        }

        // Check for beginning of an attribute
        if (in_tag && !in_value && c == ' ' && xml_input[i+1] != '/') {
            in_attribute = true;
            continue;
        }

        // Check for end of an attribute
        if (in_attribute && (isspace(c) || c == '=')) {
            in_attribute = false;
            continue;
        }

        // Check for beginning of an attribute value
        if (in_attribute && c == '"') {
            in_value = true;
            value_str_pos = 0;
            memset(value_str, 0, sizeof value_str);
            continue;
        }

        // Check for end of an attribute value
        if (in_value && c == '"') {
            in_value = false;

            // Get attribute name and value
            char* attr_name = "";
            char* attr_value = "";
            xml_node* node = stack[stack_top];
            if (value_str_pos > 0) {
                attr_value = value_str;
                char* eq = strchr(tag_str, '=');
                char* space = strchr(tag_str, ' ');
                if (eq && space && eq < space) {
                    attr_name = eq+1;
                } else {
                    attr_name = tag_str;
                }
                tag_str[eq-tag_str] = '\0';
                node->tag_name = strdup(tag_str);
            } else {
                char* eq = strchr(tag_str, '=');
                char* space = strchr(tag_str, ' ');
                if (eq && space && eq < space) {
                    attr_name = eq+1;
                } else {
                    attr_name = tag_str;
                }
            }

            // Add attribute to current node
            char* attr_str = (char*) malloc(strlen(attr_name) + strlen(attr_value) + 2);
            sprintf(attr_str, "%s=%s", attr_name, attr_value);
            add_child_node(node, create_xml_node(attr_name, attr_value));

            // Reset value string
            value_str_pos = 0;
            memset(value_str, 0, sizeof value_str);

            continue;
        }

        // Add characters to the current tag or value string
        if (in_tag) {
            tag_str[tag_str_pos++] = c;
        } else if (in_value) {
            value_str[value_str_pos++] = c;
        }

    }

    return root_node;

}

// Define function to recursively print an XML node and its children
void print_xml_node(xml_node* node, int depth) {
    // Print node with appropriate indentation
    char* indent = (char*) malloc(depth*2 + 1);
    memset(indent, ' ', depth*2);
    indent[depth*2] = '\0';
    printf("%s<%s>%s\n", indent, node->tag_name, node->tag_value);

    // Recurse on children, if any
    xml_node* child = node->children_head;
    while (child != NULL) {
        print_xml_node(child, depth+1);
        child = child->next_sibling;
    }

    // Print closing tag with appropriate indentation
    printf("%s</%s>\n", indent, node->tag_name);
    free(indent);
}

int main() {
    // Parse XML input string
    char* xml_input = "<root><person name=\"John\"><age>42</age><address><street>123 Main Street</street><city>Anytown</city></address></person></root>";
    xml_node* root_node = parse_xml_input(xml_input);

    // Print parsed XML tree
    print_xml_node(root_node, 0);

    // Clean up memory
    // TODO: implement cleanup function
    return 0;
}