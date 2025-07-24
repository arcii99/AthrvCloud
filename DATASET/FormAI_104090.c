//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARANOID 1

void parseXML(char *xmlString);

int main()
{
    char xmlString[] = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    parseXML(xmlString);
    return 0;
}

void parseXML(char *xmlString)
{
    int length = strlen(xmlString);

    if (PARANOID)
    {
        for (int i = 0; i < length; i++)
        {
            if (xmlString[i] != '<')
            {
                printf("Error: Invalid XML format, expected '<' at position %d\n", i);
                return;
            }

            int j = i + 1;
            while (j < length && xmlString[j] != '>')
            {
                if (xmlString[j] == '<')
                {
                    printf("Error: Invalid XML format, unexpected '<' at position %d\n", j);
                    return;
                }
                j++;
            }

            if (j == length)
            {
                printf("Error: Invalid XML format, expected '>' but reached end of string\n");
                return;
            }

            i = j;
        }

        printf("XML format is valid\n");
    }

    // Do XML parsing here...
}