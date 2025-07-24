//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 100
#define MAX_ATTRIBUTES 10
#define MAX_ATTRIBUTE_SIZE 50

/*
  This struct represents an XML element.
*/
typedef struct {
    char *name;
    char *text;
    char *attributes[MAX_ATTRIBUTES][2];
    int num_attributes;
} Element;

/*
  This function parses a single XML element.
*/
void parse_element(char *xml, int *index, Element *e) {
    int name_start, name_end, text_start, text_end;
    int attribute_start, attribute_end, value_start, value_end;
    char *attribute_name, *attribute_value;

    // Find the element name
    name_start = *index + 1;
    while (xml[*index] != '>' && xml[*index] != ' ') {
        (*index)++;
    }
    name_end = *index - 1;
    e->name = (char *) malloc((name_end - name_start + 2) * sizeof(char));
    strncpy(e->name, &xml[name_start], name_end - name_start + 1);
    e->name[name_end - name_start + 1] = '\0';

    // Find the element attributes
    while (xml[*index] != '>') {
        attribute_start = *index + 1;
        attribute_end = attribute_start;
        value_start = attribute_end + 2;
        while (xml[attribute_end] != '=') {
            attribute_end++;
        }
        while (xml[value_end] != '"' && xml[value_end] != '\'') {
            value_end++;
        }
        attribute_name = (char *) malloc((attribute_end - attribute_start + 2) * sizeof(char));
        strncpy(attribute_name, &xml[attribute_start], attribute_end - attribute_start + 1);
        attribute_name[attribute_end - attribute_start + 1] = '\0';
        attribute_value = (char *) malloc((value_end - value_start + 2) * sizeof(char));
        strncpy(attribute_value, &xml[value_start], value_end - value_start + 1);
        attribute_value[value_end - value_start + 1] = '\0';
        e->attributes[e->num_attributes][0] = attribute_name;
        e->attributes[e->num_attributes][1] = attribute_value;
        e->num_attributes++;

        *index = value_end + 1;
    }

    // Find the element text
    text_start = *index + 1;
    while (xml[*index] != '<') {
        (*index)++;
    }
    text_end = *index - 1;
    e->text = (char *) malloc((text_end - text_start + 2) * sizeof(char));
    strncpy(e->text, &xml[text_start], text_end - text_start + 1);
    e->text[text_end - text_start + 1] = '\0';
}

/*
  This function parses an entire XML document.
*/
void parse_xml(char *xml, int length) {
    int index = 0, element_count = 0;
    Element elements[MAX_ELEMENT_SIZE];

    while (index < length) {
        if (xml[index] == '<') {
            if (xml[index + 1] == '/') {
                // This is a closing tag, so we're done with the current element
                index += 2;
                element_count--;
            } else {
                // This is an opening tag, so we need to parse the element
                Element e;
                e.num_attributes = 0;
                parse_element(xml, &index, &e);
                elements[element_count++] = e;
            }
        }
        index++;
    }

    // Print out the parsed elements
    printf("Parsed XML:\n");
    for (int i = 0; i < element_count; i++) {
        printf("%s ", elements[i].name);
        for (int j = 0; j < elements[i].num_attributes; j++) {
            printf("%s=\"%s\" ", elements[i].attributes[j][0], elements[i].attributes[j][1]);
        }
        printf(">%s</%s>\n", elements[i].text, elements[i].name);
    }
}

int main() {
    char xml[] = "<root><element1 attribute1=\"value1\">text1</element1><element2 attribute2=\"value2\">text2</element2></root>";
    parse_xml(xml, strlen(xml));
    return 0;
}