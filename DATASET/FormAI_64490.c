//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 100

typedef struct {
    char tag[MAX_CHARACTERS];
    char value[MAX_CHARACTERS];
} xml_node;

// Function to parse the XML string
void parse_xml(char* xml_string, xml_node* nodes, int* num_nodes) {
    char* current_token = strtok(xml_string, "<>");
    int index = 0;
    while (current_token != NULL) {
        // check if the token is a tag
        if (current_token[0] == '/') {
            index--;
        } else if (current_token[0] != '?') {
            // create a new node and add it to the array of nodes
            xml_node new_node;
            strcpy(new_node.tag, current_token);
            strcpy(new_node.value, "");

            // check if the next token is a value or an opening tag
            char* next_token = strtok(NULL, "<>");
            if (next_token[0] != '/') {
                strcpy(new_node.value, next_token);
            }

            nodes[index] = new_node;
            index++;
        }
        current_token = strtok(NULL, "<>");
    }
    *num_nodes = index;
}

int main() {
    char xml[] = "<?xml version=\"1.0\"?><book><title>Harry Potter and the Philosopher's Stone</title><author>J.K. Rowling</author><year>1997</year></book>";
    xml_node nodes[MAX_CHARACTERS];
    int num_nodes;

    parse_xml(xml, nodes, &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Tag: %s Value: %s\n", nodes[i].tag, nodes[i].value);
    }

    return 0;
}