//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

/*
This program demonstrates the building of an XML parser
using the C programming language. It can handle
simple XML files and read the contents within the tags.
*/

void parseXml(char* xml_text)
{
    char opening_tag[MAX_SIZE], closing_tag[MAX_SIZE], content[MAX_SIZE];
    int length = strlen(xml_text);
    int i = 0, j = 0, k = 0;
    int start_index = 0, end_index = 0;
    int is_opening_tag = 0, is_closing_tag = 0;

    while (i < length)
    {
        if (xml_text[i] == '<')
        {
            // The starting index of either an opening or closing tag
            start_index = i + 1;
            j = 0;
            k = 0;

            // Check if the tag is an opening tag or a closing tag
            if (xml_text[i+1] == '/')
            {   
                is_closing_tag = 1;
                i++; // Skip the '/' character
            }
            else
            {
                is_opening_tag = 1;
            }
        }
        else if (xml_text[i] == '>')
        {
            // The ending index of either an opening or closing tag
            end_index = i - 1;

            // Copy the tag name or content in a separate variable
            if (is_opening_tag)
            {
                strncpy(opening_tag, xml_text+start_index, end_index-start_index+1);
                opening_tag[end_index-start_index+1] = '\0';
                printf("Opening tag: %s\n", opening_tag);
                is_opening_tag = 0;
            }
            else if (is_closing_tag)
            {
                strncpy(closing_tag, xml_text+start_index, end_index-start_index+1);
                closing_tag[end_index-start_index+1] = '\0';
                printf("Closing tag: %s\n", closing_tag);
                is_closing_tag = 0;
            }
            else
            {
                strncpy(content, xml_text+start_index, end_index-start_index+1);
                content[end_index-start_index+1] = '\0';
                printf("Content: %s\n", content);
            }
        }

        i++;
    }
}

int main()
{
    char xml_text[] = "<bookstore>\n\
                        <book category = \"cooking\">\n\
                            <title>Everyday Italian</title>\n\
                            <author>Giada De Laurentiis</author>\n\
                            <year>2005</year>\n\
                            <price>30.00</price>\n\
                        </book>\n\
                        <book category = \"children\">\n\
                            <title>Harry Potter</title>\n\
                            <author>J.K. Rowling</author>\n\
                            <year>2005</year>\n\
                            <price>29.99</price>\n\
                        </book>\n\
                     </bookstore>";
                     
    parseXml(xml_text);

    return 0;
}