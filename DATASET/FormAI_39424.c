//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    char* attributes;
    char* text;
} Node;

// Function to parse a given XML file
void parseXML(char* xml) {
    char* token;
    Node node;
    int i;

    // Get the first tag
    token = strtok(xml, "<>");

    // Loop through all tags
    while(token != NULL) {
        // Remove whitespace
        if(token[0] == ' ' || token[0] == '\n' || token[0] == '\r') {
            token = strtok(NULL, "<>");
            continue;
        }

        // Check if current tag is a closing tag
        if(token[0] == '/') {
            token = strtok(NULL, "<>");
            continue;
        }

        // Initialize node
        node.name = NULL;
        node.attributes = NULL;
        node.text = NULL;

        // Check if current tag has attributes
        if(strchr(token, ' ')) {
            // Get node name
            node.name = strtok(token, " ");

            // Get attributes
            node.attributes = strtok(NULL, "<>");

            // Get text
            node.text = strtok(NULL, "<>");
        } else {
            // Get node name
            node.name = token;

            // Get text
            node.text = strtok(NULL, "<>");
        }

        // Output node
        printf("Node name: %s\n", node.name);
        if(node.attributes != NULL) {
            printf("Node attributes: %s\n", node.attributes);
        }
        if(node.text != NULL) {
            printf("Node text: %s\n", node.text);
        }

        // Get next tag
        token = strtok(NULL, "<>");
    }
}

int main() {
    // Example XML file
    char* xml = "<blog author=\"John\"><post>Sample post</post></blog>";

    // Parse XML file
    parseXML(xml);

    return 0;
}