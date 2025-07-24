//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an XML element
#define MAX_ELEMENT_LENGTH 50

// Define the maximum depth of nested XML elements
#define MAX_DEPTH 10

// Define a struct for holding information about an XML element
typedef struct {
    char tag[MAX_ELEMENT_LENGTH];
    char data[MAX_ELEMENT_LENGTH];
} element_info;

// Define a struct for holding information about the XML document
typedef struct {
    element_info element_stack[MAX_DEPTH];
    int stack_index;
} xml_info;

// Define a function for parsing an XML element and adding it to the element stack
void parse_element(xml_info *doc, char *element) {
    // Extract the tag and data from the element
    char *tag = strtok(element, " ");
    char *data = strtok(NULL, ">");
    data++;

    // Add the element to the element stack
    element_info *new_element = &(doc->element_stack[doc->stack_index]);
    strcpy(new_element->tag, tag);
    strcpy(new_element->data, data);
    doc->stack_index++;
}

// Define a function for printing the contents of an XML document
void print_xml(xml_info *doc) {
    // Print each element in the element stack
    for (int i = 0; i < doc->stack_index; i++) {
        element_info *element = &(doc->element_stack[i]);
        printf("Tag: %s, Data: %s\n", element->tag, element->data);
    }
}

int main() {
    // Create a new XML document
    xml_info doc;
    doc.stack_index = 0;

    // Parse some example XML elements and add them to the document
    parse_element(&doc, "<person name=\"John\">");
    parse_element(&doc, "<age>25</age>");
    parse_element(&doc, "<address>123 Main St.</address>");
    parse_element(&doc, "</person>");

    // Print the contents of the document
    printf("XML Document:\n");
    print_xml(&doc);

    return 0;
}