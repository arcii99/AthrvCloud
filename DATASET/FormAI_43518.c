//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tag[50];
    char value[50];
} xml_element;

int main() {
    // read the XML string from a file
    FILE *fp = fopen("example.xml", "r");
    char xml_str[500];
    fgets(xml_str, 500, fp);
    fclose(fp);
    
    // create an array of XML elements
    xml_element elements[50];
    int element_count = 0;
    
    // loop through the XML string and parse the elements
    char *token = strtok(xml_str, "<>");
    while (token != NULL) {
        // extract the tag name and value
        if (strlen(token) > 0 && token[0] != '/') {
            strcpy(elements[element_count].tag, token);
        } else if (strlen(token) > 0) {
            strcpy(elements[element_count].value, token);
            element_count++;
        }
        token = strtok(NULL, "<>");
    }
    
    // print out the parsed elements
    for (int i = 0; i < element_count; i++) {
        printf("%s: %s\n", elements[i].tag, elements[i].value);
    }
    
    return 0;
}