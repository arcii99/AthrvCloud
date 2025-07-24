//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_META_LENGTH 50
#define MAX_BUFFER_SIZE 1000

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("\nUsage: %s file_to_extract_metadata_from.dat", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if(fp==NULL)
    {
        printf("\nError: Unable to open the file\n");
        return -1;
    }

    unsigned char buffer[MAX_BUFFER_SIZE];
    int bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp);
    fclose(fp);

    if(bytes_read==0)
    {
        printf("\nError: Unable to read the file\n");
        return -1;
    }

    char *metadata = (char *) malloc(MAX_META_LENGTH+1);
    if(metadata==NULL)
    {
        printf("\nError: Unable to allocate memory\n");
        return -1;
    }

    memset(metadata, 0, MAX_META_LENGTH+1);

    int i;
    for(i=0; i<bytes_read; i++)
    {
        if(buffer[i]=='M' && buffer[i+1]=='E' && buffer[i+2]=='T' && buffer[i+3]=='A' && buffer[i+4]=='D' && buffer[i+5]=='A')
        {
            int j=0;

            while(buffer[i+j+6]!=0)
            {
                if(j>=MAX_META_LENGTH)
                {
                    printf("\nError: Metadata length exceeded maximum allowed size\n");
                    free(metadata);
                    return -1;
                }

                metadata[j]=buffer[i+j+6];
                j++;
            }

            printf("\nMetadata extracted from the file:\n%s\n", metadata);
        }
    }

    free(metadata);

    return 0;
}