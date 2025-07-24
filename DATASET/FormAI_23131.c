//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 50
#define MAX_ATTR_NAME_LEN 50
#define MAX_ATTR_VAL_LEN 100
#define MAX_TEXT_LEN 1000

// data structures to store the XML elements
typedef struct {
    char name[MAX_TAG_NAME_LEN];
    char attributes[MAX_ATTR_NAME_LEN][MAX_ATTR_VAL_LEN];
    int num_attributes;
    char text[MAX_TEXT_LEN];
} XmlElement;

// function to parse the XML input and populate the XmlElement data structure
void parseXmlElement(char* xml_input, XmlElement* xml_element)
{
    char* current_pos = xml_input;
    char* tag_start;
    char* tag_end;
    char* attr_start;
    char* attr_end;
    int attr_len;
    
    // get the tag name
    tag_start = strchr(current_pos, '<');
    tag_end = strchr(tag_start, '>');
    strncpy(xml_element->name, tag_start+1, tag_end-tag_start-1);
    xml_element->name[tag_end-tag_start-1] = '\0';
    current_pos = tag_end+1;

    // get the attributes
    while (*(current_pos-1) != '>') {
        attr_start = strchr(current_pos, ' ');
        attr_end = strchr(attr_start, '=');
        attr_len = attr_end - attr_start;
        strncpy(xml_element->attributes[xml_element->num_attributes], attr_start+1, attr_len-1);
        xml_element->attributes[xml_element->num_attributes][attr_len-1] = '\0';
        attr_start = attr_end+2;
        attr_end = strchr(attr_start, '\"');
        attr_len = attr_end - attr_start;
        strncpy(xml_element->attributes[xml_element->num_attributes]+MAX_ATTR_NAME_LEN, attr_start, attr_len);
        xml_element->attributes[xml_element->num_attributes][MAX_ATTR_NAME_LEN+attr_len] = '\0';
        xml_element->num_attributes++;
        current_pos = attr_end+2;
    }

    // get the text
    tag_start = strchr(current_pos, '>') + 1;
    tag_end = strchr(tag_start, '<');
    strncpy(xml_element->text, tag_start, tag_end-tag_start);
    xml_element->text[tag_end-tag_start] = '\0';
}

int main()
{
    char xml_input[] = "<person fname=\"John\" lname=\"Doe\">Hello World!</person>";
    XmlElement xml_element;

    // parse the XML input and populate the XmlElement data structure
    parseXmlElement(xml_input, &xml_element);
    
    // print the parsed data
    printf("Name: %s\n", xml_element.name);
    for (int i=0; i<xml_element.num_attributes; i++) {
        printf("Attribute %d: %s=\"%s\"\n", i+1, xml_element.attributes[i], xml_element.attributes[i]+MAX_ATTR_NAME_LEN);
    }
    printf("Text: %s\n", xml_element.text);
    
    return 0;
}