//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseXML(char* xml);

int main()
{
    char* sampleXML = "<person>\n"
                      "  <name>John</name>\n"
                      "  <age>23</age>\n"
                      "</person>\n";
    parseXML(sampleXML);

    return 0;
}

void parseXML(char* xml)
{
    int i = 0;
    char buffer[20];
    while (xml[i] != '\0')
    {
        if (xml[i] == '<')
        {
            i++;
            if (xml[i] == '/')
            {
                // Closing tag
                i++;
                int j = 0;
                memset(buffer, 0, sizeof(buffer));
                while (xml[i] != '>')
                {
                    buffer[j++] = xml[i++];
                }
                printf("Closing tag: %s\n", buffer);
            }
            else
            {
                // Opening tag
                int j = 0;
                memset(buffer, 0, sizeof(buffer));
                while (xml[i] != '>')
                {
                    buffer[j++] = xml[i++];
                }
                printf("Opening tag: %s\n", buffer);
            }
        }
        else if (xml[i] >= 32 && xml[i] <= 126)
        {
            // Text data
            int j = 0;
            memset(buffer, 0, sizeof(buffer));
            while (xml[i] != '<' && xml[i] != '\0')
            {
                buffer[j++] = xml[i++];
            }
            printf("Text data: %s\n", buffer);
        }
        else
        {
            i++;
        }
    }
}