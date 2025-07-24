//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char tag[20];
    int num_attributes;
    char attributes[10][20];
} xml_element;

xml_element* parse_element(char* element_string)
{
    xml_element* current_element = malloc(sizeof(xml_element));
    char temp_string[100];
    sscanf(element_string, "<%[^>]%[^\n]", current_element->tag, temp_string);
    char* attribute_string = strtok(temp_string, "\"");
    int i = 0;
    while (attribute_string != NULL)
    {
        if (i % 2 == 1)
        {
            strcpy(current_element->attributes[(i - 1) / 2], attribute_string);
            current_element->num_attributes++;
        }
        i++;
        attribute_string = strtok(NULL, "\"");
    }
    return current_element;
}

int main()
{
    char input_string[] = "<book author=\"Ken Thompson\" title=\"Unix Programming\"/>";
    char* element_string = strtok(input_string, " ");
    xml_element* parsed_element = parse_element(element_string);
    printf("Tag: %s\n", parsed_element->tag);
    printf("Number of attributes: %d\n", parsed_element->num_attributes);
    for (int i = 0; i < parsed_element->num_attributes; i++)
    {
        printf("Attribute %d: %s\n", i+1, parsed_element->attributes[i]);
    }
    free(parsed_element);
    return 0;
}