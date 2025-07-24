//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct virus 
{
    char name[20];
    char signature[50];
};

int main() 
{
    char filename[50], buffer[1024];
    FILE *file;
    struct virus viruses[3];
    int i, j, found = 0, virus_size, file_size;

    // Define viruses to match with
    strcpy(viruses[0].name, "Worm Virus");
    strcpy(viruses[0].signature, "8s9di30j34d3294jf7d28fdif0i30dxf39ed");

    strcpy(viruses[1].name, "Trojan Virus");
    strcpy(viruses[1].signature, "7d0x3jjx0fd9cje03j23xkw0d3kxjc82ce");

    strcpy(viruses[2].name, "Spyware Virus");
    strcpy(viruses[2].signature, "cn1jkcm2hncv11j2nx239ndk0s3dmc1kc");

    printf("Enter the filename to be scanned: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Error! File not found.");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    for (i = 0; i < 3; i++) 
    {
        virus_size = strlen(viruses[i].signature);
        for (j = 0; j < file_size - virus_size; j++) 
        {
            fread(buffer, virus_size, 1, file);
            if (strcmp(buffer, viruses[i].signature) == 0)
            {
                printf("Virus Found! %s\n", viruses[i].name);
                found = 1;
                break;
            }
            fseek(file, -1 * (virus_size - 1), SEEK_CUR);
        }
        if (found == 1)
        {
            break;
        }
    }
    fclose(file);

    if (found == 0) 
    {
        printf("Scan Complete: No viruses detected.");
    }

    return 0;
}