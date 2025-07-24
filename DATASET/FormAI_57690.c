//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 100

// XML data structure
typedef struct {
    char tag[MAX_CHARACTERS];
    char attributes[MAX_CHARACTERS];
    char value[MAX_CHARACTERS];
} Element;

// XML parser
void parse_xml(char* xml_input) {
    Element element;
    int index = 0;
    while (xml_input[index] != '\0') {
        if (xml_input[index] == '<') {
            char* tag_start = &xml_input[index+1];
            char* tag_end = strchr(tag_start, '>');
            if (tag_end) {
                int tag_length = tag_end - tag_start;
                strncpy(element.tag, tag_start, tag_length);
                element.tag[tag_length] = '\0'; // null-terminate
                index = tag_end - xml_input + 1;
                tag_start = &xml_input[index];
                tag_end = strchr(tag_start, '<');
                if (tag_end) {
                    int value_length = tag_end - tag_start;
                    strncpy(element.value, tag_start, value_length);
                    element.value[value_length] = '\0'; // null-terminate
                    index = tag_end - xml_input;
                    printf("Tag: %s, Value: %s\n", element.tag, element.value);
                }
                else {
                    printf("Error: Invalid XML format\n");
                    return;
                }
            }
            else {
                printf("Error: Invalid XML format\n");
                return;
            }
        }
        index++;
    }
}

// main function
int main() {
    char xml_input[MAX_CHARACTERS] = "<person age=\"25\">John</person>";
    parse_xml(xml_input);
    return 0;
}