//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTRIBS 10
#define MAX_TAGNAME 20
#define MAX_BUFFER_SIZE 100

// Structure to hold the parsed tag data
typedef struct tag_data {
    char tag_name[MAX_TAGNAME];
    char attrib_names[MAX_ATTRIBS][MAX_TAGNAME];
    char attrib_values[MAX_ATTRIBS][MAX_BUFFER_SIZE];
    int num_attribs;
    char data[MAX_BUFFER_SIZE];
} tag_data_t;

// Function to parse an XML tag
void parseTag(char *tag_string, tag_data_t *tag_data) {
    int i = 0;
    char *token = strtok(tag_string, " \t\r\n");
    while (token != NULL) {
        // Check if this is the tag name
        if (i == 0) {
            strcpy(tag_data->tag_name, token);
        }
        // Check if this is an attribute name-value pair
        else if (i % 2 != 0) {
            strcpy(tag_data->attrib_names[(i-1)/2], token);
        } else {
            strcpy(tag_data->attrib_values[(i-2)/2], token);
            tag_data->num_attribs++;
        }
        i++;
        token = strtok(NULL, " \t\r\n");
    }
}

int main() {
    char xml[] = "<person name=\"John\" age=\"25\">Hello World!</person>";
    char *start_tag = strchr(xml, '<'); // Find the start of the outermost tag
    char *end_tag = strchr(xml, '>'); // Find the end of the outermost tag
    int tag_length = end_tag - start_tag + 1;
    char tag_string[tag_length];
    strncpy(tag_string, start_tag, tag_length); // Extract the outermost tag
    tag_data_t tag_data = {0}; // Initialize tag_data struct
    parseTag(tag_string, &tag_data); // Parse the outermost tag
    printf("Tag Name: %s\n", tag_data.tag_name);
    for (int i = 0; i < tag_data.num_attribs; i++) {
        printf("Attribute %d - Name: %s, Value: %s\n", i+1, tag_data.attrib_names[i], tag_data.attrib_values[i]);
    }
    printf("Data: %s\n", tag_data.data);
    return 0;
}