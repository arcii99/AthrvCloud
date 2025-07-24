//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENT_SIZE 1000
#define MAX_ATTRIBUTE_SIZE 100

typedef struct Element
{
    char name[MAX_ELEMENT_SIZE];
    char attributes[MAX_ATTRIBUTE_SIZE][MAX_ELEMENT_SIZE];
    char values[MAX_ATTRIBUTE_SIZE][MAX_ELEMENT_SIZE];
    int attribute_count;
    bool has_nested_elements;
    struct Element *nested_elements;
} Element;

void parse_elements(const char *xml_string, int index, Element **parent_element)
{
    Element *element = malloc(sizeof(Element));
    element->attribute_count = 0;
    element->has_nested_elements = false;
    memset(&element->name, 0, sizeof(element->name));
    memset(&element->attributes, 0, sizeof(element->attributes));
    memset(&element->values, 0, sizeof(element->values));

    int i = index;
    while (xml_string[i] != '>' && xml_string[i] != '/' && xml_string[i] != '\0')
    {
        element->name[strlen(element->name)] = xml_string[i++];
    }

    if (xml_string[i] != '/')
    {
        while (xml_string[i] != '>')
        {
            if (xml_string[i] == '\"')
            {
                i++;
                while (xml_string[i] != '\"')
                {
                    element->attributes[element->attribute_count][strlen(element->attributes[element->attribute_count])] = xml_string[i++];
                }
                element->attribute_count++;
            }
            i++;
        }
    }

    if (xml_string[i + 1] != '\0')
    {
        element->has_nested_elements = true;
        i++;
        Element *nested_elements = malloc(sizeof(Element));
        element->nested_elements = nested_elements;
        int nested_index = 0;
        while (xml_string[i] != '<' && xml_string[i] != '\0')
        {
            nested_elements->name[strlen(nested_elements->name)] = xml_string[i++];
        }
        parse_elements(xml_string, i, &nested_elements);
    }

    *parent_element = element;

    if (xml_string[i] == '<' && xml_string[i + 1] == '/')
    {
        return;
    }

    parse_elements(xml_string, ++i, &element->nested_elements);
}

void print_element(Element *element)
{
    printf("<%s", element->name);

    for (int i = 0; i < element->attribute_count; i++)
    {
        printf(" %s=\"%s\"", element->attributes[i], element->values[i]);
    }

    if (!element->has_nested_elements)
    {
        printf("/>\n");
        return;
    }

    printf(">\n");

    Element *nested_elements = element->nested_elements;
    while (strlen(nested_elements->name) > 0)
    {
        print_element(nested_elements);
        nested_elements++;
    }

    printf("</%s>\n", element->name);
}

int main()
{
    const char *xml_string = "<catalog><book id=\"001\"><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author><year>1925</year><price>10.99</price></book><book id=\"002\"><title>To Kill a Mockingbird</title><author>Harper Lee</author><year>1960</year><price>12.99</price></book></catalog>";
    Element *root_element = malloc(sizeof(Element));
    parse_elements(xml_string, 1, &root_element);
    print_element(root_element);
    free(root_element);
    return 0;
}