//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // scavenging for metadata in a post-apocalyptic world
    printf("Welcome to the metadata extractor program!\n");
    printf("Scavenging for metadata...\n");

    // accessing files in ruins
    FILE *filePointer;
    char buffer[1000];

    filePointer = fopen("ruins.dat", "r");

    if (filePointer == NULL)
    {
        printf("Unable to open file. Exiting program.\n");
        exit(0);
    }

    printf("Metadata extracted from ruins.dat:\n");

    // searching for metadata
    while (fgets(buffer, 1000, filePointer))
    {
        if (strstr(buffer, "Metadata"))
        {
            printf("%s\n", buffer);
        }
    }

    fclose(filePointer);

    // decrypting encrypted metadata
    printf("Decrypting encrypted metadata...\n");

    filePointer = fopen("encrypted.dat", "r");

    if (filePointer == NULL)
    {
        printf("Unable to open file. Exiting program.\n");
        exit(0);
    }

    printf("Metadata extracted from encrypted.dat:\n");

    while (fgets(buffer, 1000, filePointer))
    {
        for (int i = 0; buffer[i] != '\0'; ++i)
        {
            buffer[i] = buffer[i] - 4; // decrypting using a simple Caesar cipher with shift = 4
        }

        if (strstr(buffer, "Metadata"))
        {
            printf("%s\n", buffer);
        }
    }

    fclose(filePointer);

    // mapping metadata
    printf("Mapping metadata...\n");

    filePointer = fopen("coordinates.dat", "r");

    if (filePointer == NULL)
    {
        printf("Unable to open file. Exiting program.\n");
        exit(0);
    }

    printf("Metadata mapped to coordinates:\n");

    int x, y;
    
    while (fscanf(filePointer, "%d %d", &x, &y) == 2)
    {
        printf("Metadata found at coordinates %d, %d\n", x, y);
    }

    fclose(filePointer);

    printf("Metadata extraction completed successfully!\n");

    return 0;
}