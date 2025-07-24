//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum length of XML tags and attributes
#define MAX_LENGTH 100

// Constant for indicating that tag has no attributes
const char* NO_ATTR = "-";

// Function to parse the opening tag of XML element
void parse_opening_tag(char* tag, char* attributes)
{    
    printf("Opening tag: %s\n", tag);

    // If tag has no attributes
    if(strcmp(attributes, NO_ATTR) == 0)
    {
        printf("Attributes: None\n");
    }
    else
    {
        // Parse attributes if tag has any
        char* token = strtok(attributes, ",");
        printf("Attributes:\n");
        while(token != NULL)
        {
            printf("\t%s\n", token);
            token = strtok(NULL, ",");
        }
    }
}

// Function to parse the closing tag of XML element
void parse_closing_tag(char* tag)
{
    printf("Closing tag: %s\n", tag);
}

int main()
{
    char xml[MAX_LENGTH];
    int index = 0, opening_tag_start = 0, closing_tag_start = 0, i;

    printf("Enter XML string: ");
    fgets(xml, MAX_LENGTH, stdin);

    size_t length = strlen(xml);

    // Remove newline character from input string
    if(length > 0 && xml[length-1] == '\n')
    {
        xml[length-1] = '\0';
        length--;
    }

    for(i = 0; i < length; i++)
    {
        // Check for opening tag
        if(xml[i] == '<' && xml[i+1] != '/')
        {
            opening_tag_start = i+1;
            while(xml[i] != ' ')
            {
                i++;
            }
            int tag_length = i - opening_tag_start;
            char opening_tag[tag_length];
            strncpy(opening_tag, xml+opening_tag_start, tag_length);
            opening_tag[tag_length] = '\0';

            // Check for attributes
            if(xml[i] == ' ')
            {
                int attributes_start = i+1;
                while(xml[i] != '>')
                {
                    i++;
                }
                int attributes_length = i - attributes_start;
                char attributes[attributes_length];
                strncpy(attributes, xml+attributes_start, attributes_length);
                attributes[attributes_length] = '\0';
                parse_opening_tag(opening_tag, attributes);
            }
            else
            {
                parse_opening_tag(opening_tag, NO_ATTR);
            }
        }

        // Check for closing tag
        if(xml[i] == '<' && xml[i+1] == '/')
        {
            closing_tag_start = i+2;
            while(xml[i] != '>')
            {
                i++;
            }
            int tag_length = i - closing_tag_start;
            char closing_tag[tag_length];
            strncpy(closing_tag, xml+closing_tag_start, tag_length);
            closing_tag[tag_length] = '\0';

            parse_closing_tag(closing_tag);
        }
    }

    return 0;
}