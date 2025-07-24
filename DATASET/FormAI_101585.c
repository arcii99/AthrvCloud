//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_ATTRIBUTES 10

typedef struct {
    char name[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
} attribute;

typedef struct {
    char tag[MAX_TAG_LENGTH];
    attribute attributes[MAX_ATTRIBUTES];
    int numAttributes;
    char content[MAX_LINE_LENGTH];
} xml_element;

void parse_element(char* line, xml_element* element) {
    int i = 0;
    int j = 0;
    int k = 0;

    // Get tag name
    while (line[i] != ' ' && line[i] != '>') {
        element->tag[j++] = line[i++];
    }
    element->tag[j] = '\0';

    // Get attributes
    while (line[i] != '>') {
        if (line[i] != ' ') {
            // Start of attribute name
            k = 0;
            while (line[i] != '=') {
                element->attributes[element->numAttributes].name[k++] = line[i++];
            }
            element->attributes[element->numAttributes].name[k] = '\0';

            // Start of attribute value
            k = 0;
            i++; // Skip '='
            i++; // Skip opening '"' of attribute value
            while (line[i] != '"') {
                element->attributes[element->numAttributes].value[k++] = line[i++];
            }
            element->attributes[element->numAttributes].value[k] = '\0';

            element->numAttributes++;
        }
        i++;
    }

    // Get content
    i++; // Skip '>'
    j = 0;
    while (line[i] != '<') {
        element->content[j++] = line[i++];
    }
    element->content[j] = '\0';
}

int main() {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    xml_element element;

    fp = fopen("example.xml", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Parse element
        parse_element(line, &element);

        // Print element
        printf("Tag: %s\n", element.tag);
        for (int i = 0; i < element.numAttributes; i++) {
            printf("Attribute %d: %s=%s\n", i, element.attributes[i].name, element.attributes[i].value);
        }
        printf("Content: %s\n\n", element.content);

        // Clear element
        element.numAttributes = 0;
        memset(element.tag, 0, sizeof(element.tag));
        memset(element.content, 0, sizeof(element.content));
    }

    fclose(fp);

    return 0;
}