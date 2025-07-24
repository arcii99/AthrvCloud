//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ATTRIBUTE_STRING_LENGTH 100

typedef struct {
    char name[100];
    char value[100];
} Attribute;

typedef struct {
    char name[100];
    Attribute attributes[10];
    int num_attributes;
} Element;

Element parse_element(char* start_tag) {
    Element element;
    char* pos = start_tag + 1; // skip the < character
    char* name_start = pos;
    while (*pos != ' ' && *pos != '>') {
        pos++;
    }
    int name_length = pos - name_start;
    strncpy(element.name, name_start, name_length);
    element.name[name_length] = '\0';
    element.num_attributes = 0;
    while (*pos != '>') {
        pos++; // skip any whitespace
        char* attr_name_start = pos;
        while (*pos != '=') {
            pos++;
        }
        int attr_name_length = pos - attr_name_start;
        Attribute attribute;
        strncpy(attribute.name, attr_name_start, attr_name_length);
        attribute.name[attr_name_length] = '\0';
        pos++; // skip the =
        pos++; // skip the "
        char* attr_value_start = pos;
        while (*pos != '\"') {
            pos++;
        }
        int attr_value_length = pos - attr_value_start;
        strncpy(attribute.value, attr_value_start, attr_value_length);
        attribute.value[attr_value_length] = '\0';
        pos++; // skip the "
        element.attributes[element.num_attributes++] = attribute;
    }
    return element;
}

void print_element(Element element) {
    printf("Element: %s\n", element.name);
    for (int i=0; i<element.num_attributes; i++) {
        printf("    %s: %s\n", element.attributes[i].name, element.attributes[i].value);
    }
}

int main() {
    char xml_string[] = "<person name=\"Alice\" age=\"30\">Hello, world!</person>";
    char* pos = xml_string;
    while (*pos != '>') {
        pos++;
    }
    pos++;
    printf("Text: %s\n", pos);
    Element person = parse_element(xml_string);
    print_element(person);
    return 0;
}