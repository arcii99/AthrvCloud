//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multiplayer
// This is a sample XML parser program written in C language in a multiplayer style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for XML tags and attributes
#define TAG_SIZE 20
#define ATTR_SIZE 20

// Structure definition for holding XML tag and attributes
struct XmlTag {
    char tag[TAG_SIZE];
    char attrs[ATTR_SIZE][ATTR_SIZE];
    int attr_count;
};

// Function to parse the XML string and extract the tags and attributes
void parseXmlString(char* xmlString) {
    // Initialize variables
    int i = 0, j = 0, tag_flag = 0, attr_flag = 0;
    char cur_tag[TAG_SIZE], cur_attr[ATTR_SIZE];
    struct XmlTag xml_tags[10];
    int tag_index = -1;
    // Loop through each character of the XML string
    while(xmlString[i] != '\0') {
        // Check for opening tag
        if (xmlString[i] == '<' && xmlString[i+1] != '/') {
            tag_flag = 1;
            attr_flag = 0;
            tag_index++;
            j = 0;
            continue;
        }
        // Check for closing tag
        else if (xmlString[i] == '>' && xmlString[i-1] != '/') {
            tag_flag = 0;
            xml_tags[tag_index].tag[j] = '\0';
            xml_tags[tag_index].attr_count = 0;
            continue;
        }
        // Check for attribute
        else if (xmlString[i] == ' ' && xmlString[i-1] != '/') {
            attr_flag = 1;
            j = 0;
            continue;
        }
        else if (xmlString[i] == '=' && xmlString[i+1] == '\"') {
            continue;
        }
        else if (xmlString[i] == '\"') {
            attr_flag = 0;
            strcpy(xml_tags[tag_index].attrs[xml_tags[tag_index].attr_count], cur_attr);
            xml_tags[tag_index].attr_count++;
            continue;
        }
        // Check if character belongs to tag name or attribute name
        if (tag_flag) {
            xml_tags[tag_index].tag[j] = xmlString[i];
            j++;
            xml_tags[tag_index].tag[j] = '\0';
        }
        else if (attr_flag) {
            cur_attr[j] = xmlString[i];
            j++;
            cur_attr[j] = '\0';
        }
        i++;
    }
    // Print the extracted XML tags and attributes
    printf("\nExtracted XML tags and attributes:\n");
    for (i=0; i<=tag_index; i++) {
        printf("\nTag: %s", xml_tags[i].tag);
        printf("\nAttributes:");
        for (j=0; j<xml_tags[i].attr_count; j++) {
            printf("\n%s", xml_tags[i].attrs[j]);
        }
        printf("\n");
    }
}

// Main function to execute the program
int main() {
    // Sample XML string
    char xmlString[] = "<bookstore><book category=\"cooking\"><title lang=\"en\">Everyday Italian</title><author>Giada De Laurentiis</author><year>2005</year><price>30.00</price></book><book category=\"children\"><title lang=\"en\">Harry Potter</title><author>J K. Rowling</author><year>2005</year><price>29.99</price></book></bookstore>";
    printf("XML string: %s\n", xmlString);
    // Parse the XML string
    parseXmlString(xmlString);
    return 0;
}