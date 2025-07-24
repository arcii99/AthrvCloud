//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100

typedef struct {
    char tag[MAX_DATA_SIZE];
    char value[MAX_DATA_SIZE];
} data_node;

int main() {
    FILE *fp;
    const char *filename = "example.xml";
    char buffer[MAX_DATA_SIZE];
    data_node nodes[MAX_DATA_SIZE];
    int num_nodes = 0;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    while (fgets(buffer, MAX_DATA_SIZE, fp)) {
        // Find the opening tag
        char *open_tag = strstr(buffer, "<");
        if (open_tag == NULL) {
            continue;
        }

        // Find the closing tag
        char *close_tag = strstr(buffer, ">");
        if (close_tag == NULL) {
            continue;
        }

        // Extract the tag name
        int tag_len = close_tag - open_tag - 1;
        strncpy(nodes[num_nodes].tag, open_tag + 1, tag_len);

        // Extract the value
        char *value_start = close_tag + 1;
        char *value_end = strstr(value_start, "<");
        int value_len = value_end - value_start;
        strncpy(nodes[num_nodes].value, value_start, value_len);
        nodes[num_nodes].value[value_len] = '\0';

        // Increment the number of nodes
        num_nodes++;
    }

    fclose(fp);

    // Print out the parsed XML
    for (i = 0; i < num_nodes; i++) {
        printf("<%s>%s</%s>\n", nodes[i].tag, nodes[i].value, nodes[i].tag);
    }

    return 0;
}