//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int index = 0;
    int length = 0;
    int isMetadata = 0;
    
    printf("Enter input string: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);
    
    // Iterate through input string
    for(int i=0; i<length; i++)
    {
        if(input[i] == '"')
        {
            if(isMetadata == 0)
            {
                // Start of metadata
                isMetadata = 1;
            }
            else
            {
                // End of metadata
                isMetadata = 0;
                
                // Copy metadata to output string
                output[index] = '\n';
                index++;
            }
        }
        else if(isMetadata == 1)
        {
            // Copy metadata to output string
            output[index] = input[i];
            index++;
        }
    }
    
    // Print output string
    printf("\nMetadata:\n%s", output);

    return 0;
}