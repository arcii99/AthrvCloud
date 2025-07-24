//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum size of XML tags and attributes */
#define MAX_TAG_SIZE 50
#define MAX_ATT_SIZE 50

/* Struct to hold XML attributes */
struct xml_attribute {
    char name[MAX_ATT_SIZE];
    char value[MAX_ATT_SIZE];
};

/* Struct to hold XML nodes */
struct xml_node {
    char tag[MAX_TAG_SIZE];
    char value[MAX_TAG_SIZE];
    struct xml_attribute attributes[MAX_ATT_SIZE];
    int num_attributes;
};

/* Function to parse XML file and create node tree */
void parse_xml(char* filename, struct xml_node* root) {
    FILE *fp;
    char ch;
    char buffer[MAX_ATT_SIZE];
    int buffer_pos = 0;
    int is_tag = 0; // 0 if currently parsing node value, 1 if tag name, 2 if attribute name, 3 if attribute value
    int is_attr = 0; // 1 if currently parsing attribute, 0 otherwise
    int is_attval = 0; // 1 if currently parsing attribute value, 0 otherwise
    int node_count = 0;

    // Open XML file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Parse file character by character
    while ((ch = fgetc(fp)) != EOF) {

        // Ignore whitespace and line breaks
        if (ch == ' ' || ch == '\n' || ch == '\r') {
            continue;
        }

        // Check for start of tag or attribute
        if (ch == '<') {
            is_tag = 1;
            buffer_pos = 0;
            continue;
        } else if (ch == '\"') {
            if (is_attr) {
                is_attval = 1;
            }
            continue;
        }

        // Check for end of tag or attribute
        if (ch == '>') {
            if (!is_attr) {
                is_tag = 0;
                strcpy(root[node_count].tag, buffer);
                node_count++;
            } else {
                is_attr = 0;
                is_attval = 0;
                strcpy(root[node_count-1].attributes[root[node_count-1].num_attributes].value, buffer);
                root[node_count-1].num_attributes++;
            }
            buffer_pos = 0;
            continue;
        } else if (ch == ' ' && !is_attr) {
            is_attr = 1;
            strcpy(root[node_count-1].attributes[root[node_count-1].num_attributes].name, buffer);
            buffer_pos = 0;
            continue;
        }

        // Add character to buffer
        buffer[buffer_pos++] = ch;

        // Check for end of attribute value
        if (is_attval && ch == '\"') {
            is_attr = 0;
            is_attval = 0;
            strcpy(root[node_count-1].attributes[root[node_count-1].num_attributes].value, buffer);
            root[node_count-1].num_attributes++;
            buffer_pos = 0;
        }
    }

    // Close file
    fclose(fp);
}

int main() {
    struct xml_node root[50];

    // Parse XML file
    parse_xml("example.xml", root);

    // Print node tree
    for (int i = 0; i < 50; i++) {
        printf("Node %d:\n", i);
        printf("  Tag: %s\n", root[i].tag);
        printf("  Value: %s\n", root[i].value);
        printf("  Attributes:\n");
        for (int j = 0; j < root[i].num_attributes; j++) {
            printf("    %s = %s\n", root[i].attributes[j].name, root[i].attributes[j].value);
        }
    }

    return 0;
}