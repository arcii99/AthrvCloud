//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing XML tags and their attributes
struct XMLTag {
    char* name;
    char** attributes;
    int numAttributes;
};

// Function for parsing XML file and returning array of XMLTag structs
struct XMLTag* parseXML(char* filename) {
    // Open file in read mode
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    // Allocate initial memory for array of XMLTag structs
    struct XMLTag* tags = (struct XMLTag*)malloc(sizeof(struct XMLTag));
    int tagsSize = 1;
    int tagsIndex = 0;

    // Read in tags and their attributes
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL) {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Check if line is a tag
        if (buffer[0] == '<' && buffer[strlen(buffer) - 1] == '>') {
            // Initialize new XMLTag struct
            struct XMLTag tag;
            tag.numAttributes = 0;

            // Remove angle brackets from tag name
            int nameLength = strlen(buffer) - 2;
            tag.name = (char*)malloc((nameLength + 1) * sizeof(char));
            strncpy(tag.name, buffer + 1, nameLength);
            tag.name[nameLength] = '\0';

            // Check if tag has attributes
            char* attrStart = strchr(buffer, ' ');
            if (attrStart != NULL) {
                // Loop through attributes and add to struct
                char* attrEnd = strchr(attrStart, '>');
                while (attrStart < attrEnd) {
                    // Find name and value of attribute
                    char* nameStart = attrStart + 1;
                    char* valueStart = strchr(attrStart, '\"') + 1;
                    char* valueEnd = strchr(valueStart, '\"');

                    // Add attribute name to struct
                    int nameLength = valueStart - nameStart - 2;
                    char* name = (char*)malloc((nameLength + 1) * sizeof(char));
                    strncpy(name, nameStart, nameLength);
                    name[nameLength] = '\0';
                    tag.attributes = (char**)realloc(tag.attributes, (tag.numAttributes + 1) * sizeof(char*));
                    tag.attributes[tag.numAttributes] = name;

                    // Add attribute value to struct
                    int valueLength = valueEnd - valueStart;
                    char* value = (char*)malloc((valueLength + 1) * sizeof(char));
                    strncpy(value, valueStart, valueLength);
                    value[valueLength] = '\0';
                    tag.attributes[tag.numAttributes] = (char*)realloc(tag.attributes[tag.numAttributes], (strlen(value) + 1) * sizeof(char));
                    strcpy(tag.attributes[tag.numAttributes], value);

                    // Increment index and numAttributes
                    tagsIndex++;
                    tag.numAttributes++;
                    attrStart = valueEnd + 1;
                }
            }

            // Add tag struct to array and increment tagsIndex and tagsSize
            tags[tagsIndex] = tag;
            tagsIndex++;
            if (tagsIndex == tagsSize) {
                tagsSize *= 2;
                tags = (struct XMLTag*)realloc(tags, tagsSize * sizeof(struct XMLTag));
            }
        }
    }

    // Close file and return array of XMLTag structs
    fclose(fp);
    return tags;
}

int main() {
    // Call parseXML function and print out tag names and their attributes
    struct XMLTag* tags = parseXML("example.xml");
    for (int i = 0; i < 2; i++) {
        printf("Tag Name: %s\n", tags[i].name);
        for (int j = 0; j < tags[i].numAttributes; j++) {
            printf("Attribute Name: %s\tValue: %s\n", tags[i].attributes[j], tags[i].attributes[j + 1]);
            j++;
        }
    }
    // Free memory allocated for tag names and attributes
    for (int i = 0; i < 2; i++) {
        free(tags[i].name);
        for (int j = 0; j < tags[i].numAttributes; j++) {
            free(tags[i].attributes[j]);
        }
        free(tags[i].attributes);
    }
    // Free memory allocated for array of XMLTag structs
    free(tags);
    return 0;
}