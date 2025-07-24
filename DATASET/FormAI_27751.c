//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_ATT_LEN 50
#define MAX_ATT_VAL_LEN 100
#define MAX_DATA_LEN 100

typedef struct {
    char tag[MAX_TAG_LEN];
    char att[MAX_ATT_LEN];
    char att_val[MAX_ATT_VAL_LEN];
    char data[MAX_DATA_LEN];
} xml_element;

void parse_element(char* xml_str, int* index, xml_element* element) {
    int i = 0;
    char c = xml_str[*index];
    
    // Parse tag
    while (c != '<' && c != '\0') {
        element->tag[i] = c;
        i++;
        (*index)++;
        c = xml_str[*index];
    }
    element->tag[i] = '\0';
    
    // Skip opening tag
    while (c != '>' && c != '\0') {
        (*index)++;
        c = xml_str[*index];
    }
    (*index)++;
    
    // Parse attributes and data
    while (c != '<' && c != '\0') {
        i = 0;
        
        // Parse attribute name
        while (c != '=' && c != '\0') {
            element->att[i] = c;
            i++;
            (*index)++;
            c = xml_str[*index];
        }
        element->att[i] = '\0';
        (*index)++;
        
        // Parse attribute value
        if (c == '"') {
            i = 0;
            (*index)++;
            c = xml_str[*index];
            while (c != '"' && c != '\0') {
                element->att_val[i] = c;
                i++;
                (*index)++;
                c = xml_str[*index];
            }
            element->att_val[i] = '\0';
            (*index)++;
        }
        
        // Parse data
        if (c != '>') {
            i = 0;
            while (c != '<' && c != '\0') {
                element->data[i] = c;
                i++;
                (*index)++;
                c = xml_str[*index];
            }
            element->data[i] = '\0';
        }
    }
}

int main() {
    char xml_str[200] = "<person name=\"John Smith\">25</person><person name=\"Jane Doe\">31</person>";
    int index = 0;
    xml_element element;
    
    while (xml_str[index] != '\0') {
        parse_element(xml_str, &index, &element);
        printf("Tag: %s\n", element.tag);
        printf("Attribute: %s=%s\n", element.att, element.att_val);
        printf("Data: %s\n", element.data);
        printf("\n");
    }
    
    return 0;
}