//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define ELEMENT_CAPACITY 100

// A structure to represent an XML element
typedef struct {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_TAG_LENGTH];
} element_t;

// An array of elements to store parsed XML data
element_t elements[ELEMENT_CAPACITY];
int elementCount = 0;

// A function to parse the XML string and store the elements
void parseXmlString(char *xmlString) {
    char *tagStart;
    char *tagEnd;
    char *valueStart;
    char *valueEnd;
    char tag[MAX_TAG_LENGTH];
    char value[MAX_TAG_LENGTH];

    tagStart = strstr(xmlString, "<");
    while (tagStart != NULL) {
        // Find the end of the tag
        tagEnd = strstr(tagStart, ">");

        // Extract the tag and the value
        strncpy(tag, tagStart + 1, tagEnd - tagStart - 1);
        tag[tagEnd - tagStart] = '\0';
        valueStart = tagEnd + 1;
        valueEnd = strstr(valueStart, "<");
        strncpy(value, valueStart, valueEnd - valueStart);
        value[valueEnd - valueStart] = '\0';

        // Save the element in the array
        strncpy(elements[elementCount].tag, tag, MAX_TAG_LENGTH);
        strncpy(elements[elementCount].value, value, MAX_TAG_LENGTH);
        elementCount++;

        // Look for the next tag
        tagStart = strstr(valueEnd, "<");
    }
}

int main() {
    char xmlString[] = "<person><name>John</name><age>25</age></person>";
    parseXmlString(xmlString);

    // Print the parsed elements
    for (int i = 0; i < elementCount; i++) {
        printf("Tag: %s, Value: %s\n", elements[i].tag, elements[i].value);
    }

    return 0;
}