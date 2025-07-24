//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Can you unlock the mystery of this C Metadata Extractor?\n");
    printf("Enter a file name: ");

    char filename[50];
    scanf("%s", filename);

    FILE *fileptr;
    fileptr = fopen(filename, "rb");
    
    struct Metadata {
        char magic[8];
        unsigned char version;
        unsigned char length;
        unsigned int checksum;
        char platform[16];
    };

    struct Metadata data;
    fread(&data, sizeof(struct Metadata), 1, fileptr); 
    fclose(fileptr);

    if (strcmp(data.magic, "MAGIC123") != 0) {
        printf("Invalid file.\n");
        return 1;
    }

    char* version_str = malloc(sizeof(char) * 4);
    sprintf(version_str, "%d.%d.%d", data.version / 100, (data.version / 10) % 10, data.version % 10);
    
    printf("Metadata:\n");
    printf("Version   : %s\n", version_str);
    printf("Length    : %d bytes\n", data.length);
    printf("Checksum  : 0x%08X\n", data.checksum);
    printf("Platform  : %s\n", data.platform);
  
    free(version_str);
    return 0;
}