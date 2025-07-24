//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XML tag structure
typedef struct {
    char* name;
    int num_attributes;
    char** attributes;
} XMLTag;

// free_memory function to clean up dynamically allocated memory
void free_memory(XMLTag* tag) {
    free(tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        free(tag->attributes[i]);
    }
    free(tag->attributes);
    free(tag);
}

// parse_tag function to parse an XML tag string
XMLTag* parse_tag(char* tag_str) {
    // allocate memory for the tag
    XMLTag* tag = (XMLTag*) malloc(sizeof(XMLTag));

    // separate tag name from attributes
    char* token = strtok(tag_str, " ");
    tag->name = (char*) malloc(strlen(token) + 1);
    strcpy(tag->name, token);

    // count number of attributes
    tag->num_attributes = 0;
    while ((token = strtok(NULL, " ")) != NULL) {
        tag->num_attributes++;
    }

    // allocate memory for attributes and copy them
    tag->attributes = (char**) malloc(tag->num_attributes * sizeof(char*));
    int i = 0;
    token = strtok(tag_str, "\"");
    while ((token = strtok(NULL, "\"")) != NULL) {
        tag->attributes[i] = (char*) malloc(strlen(token) + 1);
        strcpy(tag->attributes[i], token);
        i++;
        strtok(NULL, " ");
    }

    // return parsed tag
    return tag;
}

// main function to read XML file and extract tags
int main() {
    FILE* file = fopen("example.xml", "r");

    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            // check if line contains a tag
            if (line[0] == '<') {
                // parse tag and print out information
                XMLTag* tag = parse_tag(line);
                printf("Tag Name: %s\n", tag->name);
                printf("Number of Attributes: %d\n", tag->num_attributes);
                for (int i = 0; i < tag->num_attributes; i++) {
                    printf("Attribute %d: %s\n", i+1, tag->attributes[i]);
                }
                printf("\n");

                // free dynamically allocated memory for tag
                free_memory(tag);
            }
        }
        fclose(file);
    } else {
        printf("Error: failed to open file.\n");
    }

    return 0;
}