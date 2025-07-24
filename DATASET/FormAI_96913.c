//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 100
#define MAX_ATTRIBUTE_SIZE 50

void extractMetadata(char* metadata, char* attribute)
{
    char* attributeStart = strstr(metadata, attribute);

    if(attributeStart != NULL)
    {
        attributeStart += strlen(attribute) + 3; //Skip attribute: and space
        char* attributeEnd = strstr(attributeStart, "\"");

        if(attributeEnd != NULL)
        {
            int attributeLength = attributeEnd - attributeStart;
            char extractedAttribute[MAX_ATTRIBUTE_SIZE] = "";
            strncat(extractedAttribute, attributeStart, attributeLength); //Extract attribute
            printf("'%s' : '%s'\n", attribute, extractedAttribute); //Print extracted attribute
        }
    }
}

int main()
{
    char metadata[MAX_METADATA_SIZE] = "<title attribute: \"Page Title\" description: \"This is the description\">";

    extractMetadata(metadata, "title");
    extractMetadata(metadata, "description");
    extractMetadata(metadata, "keywords");

    return 0;
}