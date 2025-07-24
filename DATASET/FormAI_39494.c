//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for storing XML data
typedef struct node {
    char name[50];
    char value[100];
    struct node *sibling;
    struct node *child;
} xml_node;

// define function for parsing the XML data
void parse_xml_data(char *data) {
    xml_node *root = NULL;
    xml_node *current = NULL;
    char *tag_start = NULL;
    char *tag_end = NULL;
    char *tag_contents_start = NULL;
    char *tag_contents_end = NULL;
    char *cur_position = data;
    int tag_length, contents_length;

    while (*cur_position != '\0') {
        if (*cur_position == '<') {
            // start of a tag
            tag_start = cur_position;
            tag_end = strchr(tag_start, '>');
            if (tag_end == NULL) {
                printf("Error: Malformed tag.\n");
                return;
            }
            // start of tag name
            tag_start++;

            // is it a closing tag?
            if (*tag_start == '/') {
                if (current == NULL) {
                    // invalid XML
                    printf("Error: Closing tag with no matching opening tag.\n");
                    return;
                }
                // move up to parent node
                current = current->sibling;
            }
            else {
                // create new node
                xml_node *new_node = (xml_node *) malloc(sizeof(xml_node));
                if (new_node == NULL) {
                    printf("Error: Out of memory.\n");
                    return;
                }
                // set default values
                strcpy(new_node->name, "");
                strcpy(new_node->value, "");
                new_node->sibling = NULL;
                new_node->child = NULL;
                if (root == NULL) {
                    // first node
                    root = new_node;
                    current = new_node;
                } else {
                    // add node to sibling list
                    current->sibling = new_node;
                    current = new_node;
                }
                // copy tag name
                tag_end--;
                tag_length = tag_end - tag_start;
                if (tag_length >= 50) {
                    printf("Error: Tag name is too long.\n");
                    return;
                }
                strncpy(current->name, tag_start, tag_length);
                current->name[tag_length] = '\0';
                // is it a self-closing tag?
                if (*(tag_end - 1) == '/') {
                    continue;
                }
            }
        }
        else if (*cur_position == '>') {
            // end of a tag
            tag_contents_start = cur_position + 1;
            // find end of tag contents
            tag_contents_end = strchr(tag_contents_start, '<');
            if (tag_contents_end == NULL) {
                printf("Error: Malformed tag.\n");
                return;
            }
            tag_contents_end--;
            contents_length = tag_contents_end - tag_contents_start + 1;
            // copy tag contents
            strncpy(current->value, tag_contents_start, contents_length);
            current->value[contents_length] = '\0';
        }
        cur_position++;
    }
    printf("XML parsing complete.\n");
}

int main() {
    char *xml_data = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                     "<root>"
                     "<node1>Value 1</node1>"
                     "<node2 attribute1=\"value1\" attribute2=\"value2\">"
                     "<subnode>Value 2</subnode>"
                     "<subnode>Value 3</subnode>"
                     "</node2>"
                     "</root>";
    parse_xml_data(xml_data);
    return 0;
}