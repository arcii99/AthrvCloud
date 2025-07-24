//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the XML element
typedef struct xml_element
{
    char *tag;
    char *value;
    int child_count;
    struct xml_element **child; // Array of child elements
} xml_element;

// Function to create a new XML element
xml_element *create_element(char *tag, char *value, int child_count)
{
    xml_element *elem = malloc(sizeof(xml_element));
    elem->tag = strdup(tag); // Copying tag string
    elem->value = strdup(value); // Copying value string
    elem->child_count = child_count; // Storing child count

    if (child_count > 0)
    {
        // Creating array of child elements
        elem->child = calloc(child_count, sizeof(xml_element*));
    }

    return elem;
}

// Function to free memory allocated to XML element
void free_element(xml_element *elem)
{
    free(elem->tag);
    free(elem->value);

    if (elem->child_count > 0)
    {
        for (int i = 0; i < elem->child_count; i++)
        {
            free_element(elem->child[i]); // Recursively free child elements
        }

        free(elem->child);
    }

    free(elem);
}

// Function to parse the XML using multivariable style
xml_element *parse_xml(char *xml_str, int *pos)
{
    int len = strlen(xml_str);
    char tag[50], value[100];
    int child_count = 0;
    xml_element *elem = NULL;

    while (*pos < len)
    {
        // Ignore leading white spaces
        while (xml_str[*pos] == ' ' || xml_str[*pos] == '\n' || xml_str[*pos] == '\r' || xml_str[*pos] == '\t')
        {
            (*pos)++;
        }

        if (xml_str[*pos] == '<')
        {
            (*pos)++; // Increment position

            if (xml_str[*pos] == '/') // Closing tag
            {
                (*pos)++; // Increment position

                // Copying tag name
                int i = 0;
                while (xml_str[*pos] != '>')
                {
                    tag[i++] = xml_str[(*pos)++];
                }
                tag[i] = '\0';

                // Closing tag found, return element
                return elem;
            }
            else // Opening tag
            {
                // Copying tag name
                int i = 0;
                while (xml_str[*pos] != ' ' && xml_str[*pos] != '>')
                {
                    tag[i++] = xml_str[(*pos)++];
                }
                tag[i] = '\0';

                // Counting child elements
                while (xml_str[*pos] != '>')
                {
                    if (xml_str[*pos] == '<' && xml_str[(*pos)+1] != '/')
                    {
                        child_count++;
                    }
                    (*pos)++;
                }

                (*pos)++; // Increment position

                // Copying element value
                int j = 0;
                while (xml_str[*pos] != '<')
                {
                    value[j++] = xml_str[(*pos)++];
                }
                value[j] = '\0';

                // Creating new element
                elem = create_element(tag, value, child_count);

                if (child_count > 0)
                {
                    // Parsing child elements recursively
                    int i = 0;
                    while (i < child_count)
                    {
                        elem->child[i] = parse_xml(xml_str, pos);
                        i++;
                    }
                }

                // Closing tag
                (*pos)++;
            }
        }
    }

    return NULL;
}

int main()
{
    char xml_str[] = "<bookstore>\n"
                     "  <book category=\"cooking\">\n"
                     "    <title lang=\"en\">Everyday Italian</title>\n"
                     "    <author>Giada De Laurentiis</author>\n"
                     "    <year>2005</year>\n"
                     "    <price>30.00</price>\n"
                     "  </book>\n"
                     "  <book category=\"children\">\n"
                     "    <title lang=\"en\">Harry Potter</title>\n"
                     "    <author>J.K. Rowling</author>\n"
                     "    <year>2005</year>\n"
                     "    <price>29.99</price>\n"
                     "  </book>\n"
                     "</bookstore>";

    int pos = 0;
    xml_element *root = parse_xml(xml_str, &pos);
    printf("Root tag: %s\n", root->tag);
    printf("Child count: %d\n", root->child_count);

    for (int i = 0; i < root->child_count; i++)
    {
        xml_element *elem = root->child[i];
        printf("\nTag: %s\n", elem->tag);
        printf("Value: %s\n", elem->value);
        printf("Child count: %d\n", elem->child_count);
    }

    free_element(root); // Free memory
    return 0;
}