//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if(file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char virus[] = "malware";
    char buffer[128];
    while(fgets(buffer, sizeof(buffer), file))
    {
        if(strstr(buffer, virus))
        {
            printf("Virus detected in file %s\n", filename);
            fclose(file);
            return 0;
        }
    }
    
    printf("No virus detected in file %s\n", filename);
    fclose(file);
    return 0;
}