//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// struct to hold information for each tag
typedef struct tag_info
{
    char name[100]; // tag name
    int num_attributes; // number of attributes
    char attributes[10][100]; // attribute names
    char values[10][100]; // attribute values
} TagInfo;

// function to parse XML content and store tag information in TagInfo array
int parseXML(char *xmlContent, TagInfo *tagInfoArray)
{
    int tagCount = 0; // to keep track of number of tags
    int i = 0;
    char c;

    while ((c = xmlContent[i++]) != '\0') // loop through characters in XML content
    {
        if (c == '<') // start of a tag
        {
            char tagName[100];
            int j = 0;
            char attrName[100];
            char attrValue[100];
            int k = 0;

            // get tag name
            while ((c = xmlContent[i++]) != '>')
            {
                if (c == ' ') // tag has attributes
                    break;
                tagName[j++] = c;
            }
            tagName[j] = '\0';

            // get attribute names and values
            while (c != '>')
            {
                if (c == ' ') // skip white space
                    continue;
                else if (c == '/') // self-closing tag, no attributes
                    break;
                else if (c == '\"') // attribute value enclosed in double quotes
                {
                    k = 0;
                    while ((c = xmlContent[i++]) != '\"')
                    {
                        attrValue[k++] = c;
                    }
                    attrValue[k] = '\0';
                    strcpy(tagInfoArray[tagCount].values[tagInfoArray[tagCount].num_attributes], attrValue);
                    tagInfoArray[tagCount].num_attributes++;
                }
                else if (c == '>') // end of attributes
                    break;
                else // attribute name
                {
                    k = 0;
                    while (c != '=')
                    {
                        attrName[k++] = c;
                        c = xmlContent[i++];
                    }
                    attrName[k] = '\0';
                    strcpy(tagInfoArray[tagCount].attributes[tagInfoArray[tagCount].num_attributes], attrName);
                }
            }

            strcpy(tagInfoArray[tagCount].name, tagName); // store tag name
            tagCount++;
        }
    }

    return tagCount; // return number of tags
}

int main()
{
    // sample XML content
    char xmlContent[] = "<bookstore>\n"
                        "<book category=\"children\" price=\"29.99\" cover=\"hardcover\">\n"
                        "<title>The Cat in the Hat</title>\n"
                        "<author>Dr. Seuss</author>\n"
                        "<year>1957</year>\n"
                        "</book>\n"
                        "<book category=\"cooking\" price=\"14.99\" cover=\"paperback\">\n"
                        "<title>The Joy of Cooking</title>\n"
                        "<author>Irma Rombauer</author>\n"
                        "<year>1931</year>\n"
                        "</book>\n"
                        "</bookstore>";

    TagInfo tagInfoArray[10]; // array to hold information for each tag
    int tagCount = parseXML(xmlContent, tagInfoArray); // parse XML content and get number of tags

    // print tag information
    for (int i = 0; i < tagCount; i++)
    {
        printf("Tag Name: %s\n", tagInfoArray[i].name);
        printf("Number of Attributes: %d\n", tagInfoArray[i].num_attributes);
        for (int j = 0; j < tagInfoArray[i].num_attributes; j++)
        {
            printf("%s=\"%s\"\n", tagInfoArray[i].attributes[j], tagInfoArray[i].values[j]);
        }
        printf("\n");
    }

    return 0;
}