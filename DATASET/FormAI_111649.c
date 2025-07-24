//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_LENGTH 100
#define MAX_XML_ELEMENTS 1000

struct xml_element {
    char name[MAX_ELEMENT_LENGTH];
    char value[MAX_ELEMENT_LENGTH];
};

typedef struct xml_element XmlElement;

int main() {
    XmlElement elements[MAX_XML_ELEMENTS];
    int element_count = 0;

    FILE* xml_file = fopen("cyberpunk.xml", "r");
    if (!xml_file) {
        printf("Error: Failed to open XML file.\n");
        return -1;
    }

    char curr_char = '\0';
    char curr_name[MAX_ELEMENT_LENGTH];
    char curr_value[MAX_ELEMENT_LENGTH];
    int name_count = 0;
    int value_count = 0;
    int is_name = 0;
    int in_element = 0;

    while ((curr_char = fgetc(xml_file)) != EOF) {
        if (curr_char == '<') {
            is_name = 1;
            in_element = 1;
            if (name_count > 0) {
                strcpy(elements[element_count].name, curr_name);
                strcpy(elements[element_count].value, curr_value);
                element_count++;
            }
            name_count = 0;
            value_count = 0;
            memset(curr_name, 0, MAX_ELEMENT_LENGTH*sizeof(char));
            memset(curr_value, 0, MAX_ELEMENT_LENGTH*sizeof(char));
        }
        else if (curr_char == '>') {
            is_name = 0;
            in_element = 0;
        }
        else if (in_element) {
            if (is_name) {
                curr_name[name_count++] = curr_char;
            }
            else {
                curr_value[value_count++] = curr_char;
            }
        }
    }

    fclose(xml_file);

    printf("Parsed elements:\n");
    printf("-----------------\n");
    for (int i = 0; i < element_count; i++) {
        printf("Element %d:\n", i+1);
        printf("Name: %s\n", elements[i].name);
        printf("Value: %s\n", elements[i].value);
        printf("-----------------\n");
    }

    return 0;
}