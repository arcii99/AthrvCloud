//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define metadata structure
struct MetaData
{
    char tag[50];
    char value[100];
};

// Function to extract metadata from a given string
int extractMetadata(char *str, struct MetaData *metadata)
{
    int i=0, j=0, k=0;

    // Iterate through the string
    while(str[i]!='\0')
    {
        // Check if current character is a delimiter
        if(str[i]==';' || str[i]=='\n')
        {
            // Append null character to the value array
            metadata[k].value[j] = '\0';

            // Move to next metadata
            k++;

            // Reset the value index
            j=0;
        }
        // Check if current character is a colon
        else if(str[i]==':')
        {
            // Append null character to the tag array
            metadata[k].tag[j] = '\0';

            // Move to next character
            i++;

            // Reset the tag index
            j=0;

            // Extract the value
            while(str[i]!=';' && str[i]!='\n')
            {
                metadata[k].value[j] = str[i];
                i++;
                j++;
            }
        }
        // Otherwise, add character to tag or value array
        else
        {
            if(k==0)
            {
                metadata[k].tag[j] = str[i];
                j++;
            }
            else
            {
                metadata[k].value[j] = str[i];
                j++;
            }
        }

        // Move to next character
        i++;
    }

    // Return the number of metadata found
    return k;
}

int main()
{
    // Define a string to extract metadata from
    char str[] = "Title: The Catcher in the Rye; Author: J.D. Salinger; Year: 1951;\nGenre: Fiction; Publisher: Little, Brown and Company;";

    // Define metadata array
    struct MetaData metadata[10];

    // Extract metadata
    int count = extractMetadata(str, metadata);

    // Print the metadata
    int i;
    for(i=0; i<count; i++)
    {
        printf("%s: %s\n", metadata[i].tag, metadata[i].value);
    }

    // Exit program
    return 0;
}