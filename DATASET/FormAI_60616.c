//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing XML element data
struct Element {
    char* name;
    char* value;
};

// Define function for parsing XML elements
struct Element parse_element(char* element_string) {
    struct Element element;
    char* name_start = strchr(element_string, '<') + 1;
    char* name_end = strchr(name_start, '>');
    int name_length = name_end - name_start;
    element.name = (char*) malloc((name_length + 1) * sizeof(char));
    strncpy(element.name, name_start, name_length);
    element.name[name_length] = '\0';
    char* value_start = name_end + 1;
    char* value_end = strchr(value_start, '<');
    int value_length = value_end - value_start;
    element.value = (char*) malloc((value_length + 1) * sizeof(char));
    strncpy(element.value, value_start, value_length);
    element.value[value_length] = '\0';
    return element;
}

// Define function for building XML element string
char* build_element_string(struct Element element) {
    int element_length = strlen(element.name) + strlen(element.value) + 5;
    char* element_string = (char*) malloc(element_length * sizeof(char));
    sprintf(element_string, "<%s>%s</%s>", element.name, element.value, element.name);
    return element_string;
}

int main() {
    // Define sample XML string
    char* xml_string = "<name>John</name><age>30</age><city>Boston</city>";
    
    // Parse XML string into individual elements
    char* xml_copy = (char*) malloc((strlen(xml_string) + 1) * sizeof(char));
    strcpy(xml_copy, xml_string);
    struct Element elements[3];
    for (int i = 0; i < 3; i++) {
        elements[i] = parse_element(xml_copy);
        xml_copy = strchr(xml_copy, '<') + 1;
    }
    
    // Print parsed XML elements
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", elements[i].name, elements[i].value);
    }
    
    // Build XML string from elements
    char* xml_string_copy = (char*) malloc(sizeof(char));
    xml_string_copy[0] = '\0';
    for (int i = 0; i < 3; i++) {
        char* element_string = build_element_string(elements[i]);
        xml_string_copy = (char*) realloc(xml_string_copy, (strlen(xml_string_copy) + strlen(element_string) + 1) * sizeof(char));
        strcat(xml_string_copy, element_string);
        free(element_string);
    }
    
    // Print built XML string
    printf("%s\n", xml_string_copy);
    
    // Free memory
    free(xml_copy);
    free(xml_string_copy);
    for (int i = 0; i < 3; i++) {
        free(elements[i].name);
        free(elements[i].value);
    }
    
    return 0;
}