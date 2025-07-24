//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TAG_LENGTH 32
#define MAX_ATTR_LENGTH 64
#define MAX_VALUE_LENGTH 128
#define MAX_CHILDREN 10

typedef struct _xml_node {
    char tag[MAX_TAG_LENGTH];
    char attr[MAX_ATTR_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct _xml_node* parent;
    struct _xml_node* children[MAX_CHILDREN];
    int num_children;
} XmlNode;

void print_node(XmlNode* node, int depth) {
    // print the node's tag, attribute, and value
    printf("%*s<%s %s>%s\n", depth * 2, "", node->tag, node->attr, node->value);
    // recursively print the node's children
    for (int i = 0; i < node->num_children; i++) {
        print_node(node->children[i], depth + 1);
    }
    printf("%*s</%s>\n", depth * 2, "", node->tag);
}

bool parse_xml(char* xml, XmlNode* root) {
    // create a stack of nodes to keep track of the parent nodes
    XmlNode* stack[MAX_CHILDREN];
    int stack_pos = -1;
    // loop through each character in the xml string
    for (int i = 0; i < strlen(xml); i++) {
        // check for an opening tag
        if (xml[i] == '<' && xml[i + 1] != '/') {
            // find the tag name
            char tag[MAX_TAG_LENGTH];
            int tag_pos = 0;
            i++;
            while (xml[i] != ' ' && xml[i] != '>') {
                tag[tag_pos++] = xml[i++];
            }
            tag[tag_pos] = '\0';
            // create a new node with the tag name
            XmlNode* node = (XmlNode*)malloc(sizeof(XmlNode));
            strcpy(node->tag, tag);
            node->attr[0] = '\0';
            node->value[0] = '\0';
            node->parent = NULL;
            node->num_children = 0;
            // check for attributes
            while (xml[i] != '>') {
                // skip whitespace
                while (xml[i] == ' ') {
                    i++;
                }
                // find the attribute name
                char attr[MAX_ATTR_LENGTH];
                int attr_pos = 0;
                while (xml[i] != '=') {
                    attr[attr_pos++] = xml[i++];
                }
                attr[attr_pos] = '\0';
                i++; // skip the '=' character
                // find the attribute value
                char value[MAX_VALUE_LENGTH];
                int value_pos = 0;
                while (xml[i] != '"' && xml[i] != '\'') {
                    i++;
                }
                char quote = xml[i++];
                while (xml[i] != quote) {
                    value[value_pos++] = xml[i++];
                }
                value[value_pos] = '\0';
                // add the attribute to the node
                strcat(node->attr, attr);
                strcat(node->attr, "=");
                strcat(node->attr, value);
                strcat(node->attr, " ");
            }
            if (node->attr[0] != '\0') {
                // remove the trailing space
                node->attr[strlen(node->attr) - 1] = '\0';
            }
            // add the new node to the parent node's list of children
            if (stack_pos != -1) {
                node->parent = stack[stack_pos];
                stack[stack_pos]->children[stack[stack_pos]->num_children++] = node;
            } else {
                root->children[root->num_children++] = node;
            }
            // push the new node onto the stack
            stack[++stack_pos] = node;
        }
        // check for a closing tag
        else if (xml[i] == '<' && xml[i + 1] == '/') {
            // pop the current node off the stack
            stack_pos--;
        }
        // check for character data
        else {
            // find the character data value
            char value[MAX_VALUE_LENGTH];
            int value_pos = 0;
            while (xml[i] != '<') {
                value[value_pos++] = xml[i++];
            }
            value[value_pos] = '\0';
            // add the character data to the current node
            if (stack_pos != -1) {
                strcat(stack[stack_pos]->value, value);
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    XmlNode root;
    strcpy(root.tag, "root");
    root.attr[0] = '\0';
    root.value[0] = '\0';
    root.parent = NULL;
    root.num_children = 0;
    char* xml = "<root>\n  <person name='Alice' age='30'>\n    <city>San Francisco</city>\n    <state>CA</state>\n  </person>\n  <person name='Bob' age='40'>\n    <city>New York</city>\n    <state>NY</state>\n  </person>\n</root>";
    parse_xml(xml, &root);
    print_node(&root, 0);
    return 0;
}