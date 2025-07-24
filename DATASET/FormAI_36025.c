//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for handling XML parsing */
#define MAX_ELEMENT_LENGTH 100
#define MAX_ATTRIBUTE_LENGTH 100
#define MAX_ATTRIBUTE_NUM 10
#define MAX_TAG_STACK_DEPTH 100

/* Define structures for handling XML parsing */
struct XMLAttribute {
    char attribute_name[MAX_ATTRIBUTE_LENGTH];
    char attribute_value[MAX_ATTRIBUTE_LENGTH];
};

struct XMLElement {
    char element_name[MAX_ELEMENT_LENGTH];
    int num_attributes;
    struct XMLAttribute attributes[MAX_ATTRIBUTE_NUM];
    char element_content[MAX_ELEMENT_LENGTH];
};

/* Global variables */
struct XMLElement xml_elements[MAX_TAG_STACK_DEPTH];
int xml_element_stack_pointer = -1;

/* Function for parsing XML */
void parse_xml(char *xml) {
    int i = 0;
    char current_tag[MAX_ELEMENT_LENGTH];
    char current_attribute[MAX_ATTRIBUTE_LENGTH];
    char current_attribute_value[MAX_ATTRIBUTE_LENGTH];

    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            if (xml[i] == '/') {
                /* Pop the current element from the stack */
                xml_element_stack_pointer--;
            } else {
                /* Push the current element onto the stack */
                xml_element_stack_pointer++;

                /* Parse the current tag */
                int tag_index = 0;
                while (xml[i] != ' ' && xml[i] != '>') {
                    current_tag[tag_index] = xml[i];
                    i++;
                    tag_index++;
                }
                current_tag[tag_index] = '\0';

                /* Parse the attributes for the current tag */
                int current_attribute_index = 0;
                int current_attribute_value_index = 0;
                while (xml[i] != '>') {
                    if (xml[i] == ' ') {
                        i++;
                        current_attribute_index = 0;
                        current_attribute_value_index = 0;
                    } else if (xml[i] == '=') {
                        i++;
                    } else if (xml[i] == '"' || xml[i] == '\'') {
                        char delimiter = xml[i];
                        i++;
                        while (xml[i] != delimiter) {
                            if (current_attribute_value_index < MAX_ATTRIBUTE_LENGTH - 1) {
                                current_attribute_value[current_attribute_value_index] = xml[i];
                                current_attribute_value_index++;
                            }
                            i++;
                        }
                        current_attribute_value[current_attribute_value_index] = '\0';
                    } else {
                        current_attribute[current_attribute_index] = xml[i];
                        current_attribute_index++;
                        i++;
                    }
                }
                current_attribute[current_attribute_index] = '\0';

                /* Add the current element to the element stack */
                strcpy(xml_elements[xml_element_stack_pointer].element_name, current_tag);
                xml_elements[xml_element_stack_pointer].num_attributes = 1;
                strcpy(xml_elements[xml_element_stack_pointer].attributes[0].attribute_name, current_attribute);
                strcpy(xml_elements[xml_element_stack_pointer].attributes[0].attribute_value, current_attribute_value);

                /* Parse the element content */
                i++;
                int content_index = 0;
                while (xml[i] != '<') {
                    if (content_index < MAX_ELEMENT_LENGTH - 1) {
                        xml_elements[xml_element_stack_pointer].element_content[content_index] = xml[i];
                        content_index++;
                    }
                    i++;
                }
                xml_elements[xml_element_stack_pointer].element_content[content_index] = '\0';
            }
        }
        i++;
    }
}

/* Main function for testing XML parser */
int main() {
    char xml_input[] = "<students>\n"
                       "  <student id=\"1\">\n"
                       "    <name>John Doe</name>\n"
                       "    <age>23</age>\n"
                       "  </student>\n"
                       "  <student id=\"2\">\n"
                       "    <name>Jane Doe</name>\n"
                       "    <age>21</age>\n"
                       "  </student>\n"
                       "</students>\n";

    parse_xml(xml_input);

    /* Print the parsed elements and their attributes */
    printf("XML elements:\n");
    for (int i = 0; i <= xml_element_stack_pointer; i++) {
        printf("%s\n", xml_elements[i].element_name);
        printf("Attributes:\n");
        for (int j = 0; j < xml_elements[i].num_attributes; j++) {
            printf("%s=%s\n", xml_elements[i].attributes[j].attribute_name, xml_elements[i].attributes[j].attribute_value);
        }
        printf("Content: %s\n", xml_elements[i].element_content);
    }

    return 0;
}