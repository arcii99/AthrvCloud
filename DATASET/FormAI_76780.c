//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to hold parsed XML data
typedef struct {
    char* tag;
    char* content;
    struct Node* children;
    struct Node* next;
} Node;

// Function to remove any leading or trailing whitespace from the provided string
char* trim(char* str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (isspace(str[end])) end--;
    char* trimmed_str = malloc(end - start + 2);
    strncpy(trimmed_str, str + start, end - start + 1);
    trimmed_str[end - start + 1] = '\0';
    return trimmed_str;
}

// Function to parse an opening XML tag and return the corresponding Node
Node* parse_tag(char* line) {
    // Strip off the '<' at the beginning of the tag
    line++;

    // Find the end of the tag name
    char* tag_end = strchr(line, ' ');
    if (!tag_end) tag_end = strchr(line, '>');

    // Extract the tag name
    char* tag = malloc(tag_end - line + 1);
    strncpy(tag, line, tag_end - line);
    tag[tag_end - line] = '\0';

    // Create the Node to hold the tag and any child nodes
    Node* node = malloc(sizeof(Node));
    node->tag = tag;
    node->content = "";
    node->children = NULL;
    node->next = NULL;

    // Parse any attributes, adding them to the Node
    char* next_attr = line;
    while ((next_attr = strchr(next_attr + 1, ' '))) {
        char* attr_end = strchr(next_attr, '=');
        char* attr_name = trim(strncpy(malloc(attr_end - next_attr + 1), next_attr, attr_end - next_attr));
        char* attr_val = trim(strtok(NULL, "\""));
        node_set_attribute(node, attr_name, attr_val);
    }

    return node;
}

// Function to parse a closing XML tag and return the corresponding parent Node
Node* parse_close_tag(char* line, Node* parent) {
    // Strip off the '</' at the beginning of the tag
    line += 2;

    // Extract the tag name
    char* tag_end = strchr(line, '>');
    char* tag = malloc(tag_end - line + 1);
    strncpy(tag, line, tag_end - line);
    tag[tag_end - line] = '\0';

    // Verify that the closing tag matches the parent Node's tag
    if (strcmp(tag, parent->tag) != 0) {
        printf("Error: closing tag '%s' did not match opening tag '%s'\n", tag, parent->tag);
        exit(1);
    }

    // Return the parent Node, since we have finished parsing its children
    return parent;
}

// Function to add a child Node to the specified parent Node
void node_add_child(Node* parent, Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node* last_child = parent->children;
        while (last_child->next != NULL) {
            last_child = last_child->next;
        }
        last_child->next = child;
    }
}

// Function to set an attribute value in the specified Node
void node_set_attribute(Node* node, char* name, char* val) {
    // TODO: implement
}

// Function to parse an XML document and return the root Node
Node* parse_xml(char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    char* line = strtok(xml, "\n");
    while (line) {
        if (line[0] == '<') {
            if (line[1] == '/') {
                current = parse_close_tag(line, current);
            } else {
                Node* node = parse_tag(line);
                if (root == NULL) {
                    root = node;
                } else if (current == NULL) {
                    node_add_child(root, node);
                } else {
                    node_add_child(current, node);
                }
                current = node;
            }
        } else if (current) {
            current->content = realloc(current->content, strlen(current->content) + strlen(line) + 1);
            strcat(current->content, line);
        }
        line = strtok(NULL, "\n");
    }

    return root;
}

int main() {
    // Example XML document
    char* xml = "<root>\n"
                "  <person firstName=\"John\" lastName=\"Doe\">\n"
                "    <address>\n"
                "      <street>123 Main St.</street>\n"
                "      <city>Anytown</city>\n"
                "      <state>CA</state>\n"
                "      <zipCode>12345</zipCode>\n"
                "    </address>\n"
                "  </person>\n"
                "</root>\n";

    // Parse the XML document
    Node* root = parse_xml(xml);

    // TODO: do something with the parsed data

    return 0;
}