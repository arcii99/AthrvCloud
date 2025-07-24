//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions declarations
void parseXML(char* xml);
void parseElement(char* xml, int* index, char* tag, char* value);
int hasAttribute(char* xml, int index);
void parseAttribute(char* xml, int* index, char* attribute, char* value);

// Main function
int main() {
    char* xml = "<person name='John Doe'><age>30</age><city>New York</city></person>";

    parseXML(xml);
    
    return 0;
}

// Function to parse XML
void parseXML(char* xml) {
    int index = 0;
    char tag[100];
    char value[100];
    
    while(xml[index] != '\0') {
        // If it's the start of a new element
        if(xml[index] == '<') {
            // Parse the element and get the tag and value
            parseElement(xml, &index, tag, value);
            printf("<%s>%s</%s>\n", tag, value, tag);
        }
        index++;
    }
}

// Function to parse an XML element
void parseElement(char* xml, int* index, char* tag, char* value) {
    int i = 0;
    
    // Skip the start tag
    *index += 1;
    
    // Parse the tag name
    while(xml[*index] != ' ' && xml[*index] != '>') {
        tag[i++] = xml[*index];
        *index += 1;
    }
    tag[i] = '\0';
    
    // Check if there are any attributes
    if(hasAttribute(xml, *index)) {
        // Parse the attributes
        char attribute[100];
        char attributeValue[100];
        while(xml[*index] != '>') {
            parseAttribute(xml, index, attribute, attributeValue);
        }
    }
    
    i = 0;
    
    // Parse the value
    while(xml[*index] != '<') {
        value[i++] = xml[*index];
        *index += 1;
    }
    value[i] = '\0';
    
    // Skip the end tag
    *index += 2 + strlen(tag);
}

// Function to check if an element has attributes
int hasAttribute(char* xml, int index) {
    if(xml[index] == ' ') {
        return 1;
    }
    return 0;
}

// Function to parse an attribute
void parseAttribute(char* xml, int* index, char* attribute, char* value) {
    int i = 0;
    
    // Skip any white space
    while(xml[*index] == ' ') {
        *index += 1;
    }
    
    // Parse the attribute name
    while(xml[*index] != '=') {
        attribute[i++] = xml[*index];
        *index += 1;
    }
    attribute[i] = '\0';
    
    // Skip any white space
    while(xml[*index] == ' ') {
        *index += 1;
    }
    
    // Skip the equal sign
    *index += 1;
    
    // Skip any white space
    while(xml[*index] == ' ') {
        *index += 1;
    }
    
    // Parse the attribute value
    i = 0;
    while(xml[*index] != '\'' && xml[*index] != '\"') {
        value[i++] = xml[*index];
        *index += 1;
    }
    value[i] = '\0';
    
    // Skip to the end of the attribute
    while(xml[*index] != '\'' && xml[*index] != '\"') {
        *index += 1;
    }
}