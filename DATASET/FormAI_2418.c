//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* file_content = NULL;
    char* text_metadata = NULL;
    char* xml_metadata = NULL;
    int text_size = 0;
    int xml_size = 0;

    FILE *file_ptr;
    file_ptr = fopen("metadata.txt", "r");

    if (file_ptr != NULL)
    {
        fseek(file_ptr, 0L, SEEK_END);
        int file_size = ftell(file_ptr);
        rewind(file_ptr);
        file_content = (char*)malloc(sizeof(char) * (file_size + 1));
        fread(file_content, 1, file_size, file_ptr);
        fclose(file_ptr);
    }

    if (file_content != NULL)
    {
        char* token = strtok(file_content, "\n");

        while (token != NULL)
        {
            if (strncmp(token, "<text>", 6) == 0)
            {
                text_size = strlen(token) - 12;
                text_metadata = (char*)malloc(sizeof(char) * (text_size + 1));
                strncpy(text_metadata, token + 6, text_size);
            }
            else if (strncmp(token, "<xml>", 5) == 0)
            {
                xml_size = strlen(token) - 11;
                xml_metadata = (char*)malloc(sizeof(char) * (xml_size + 1));
                strncpy(xml_metadata, token + 5, xml_size);
            }

            token = strtok(NULL, "\n");
        }

        free(file_content);
    }

    if (text_metadata != NULL && xml_metadata != NULL)
    {
        // extract metadata from text and xml
        printf("Text Metadata: %s\n", text_metadata);
        printf("XML Metadata: %s\n", xml_metadata);

        free(text_metadata);
        free(xml_metadata);
    }

    return 0;
}