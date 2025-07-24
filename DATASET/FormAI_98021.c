//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char filename[50]);
int is_infected(char filename[50]);

int main()
{
    char input[50];
    printf("Enter file name to scan: ");
    scanf("%s", input);
    scan(input);
    return 0;
}

void scan(char filename[50])
{
    if (is_infected(filename))
    {
        printf("The file \"%s\" is infected with a virus!\n", filename);
    }
    else 
    {
        printf("The file \"%s\" is not infected with any virus.\n", filename);
    }
}

int is_infected(char filename[50])
{
    char virus_signature[] = "c0d3Sc4nn3rV1ru5"; // signature of the virus to be detected
    FILE *file = fopen(filename, "r");
    char line[256];
    int found = 0;
    if (file)
    {
        while (fgets(line, sizeof(line), file))
        {
            if(strstr(line, virus_signature) != NULL)
            {
                found = 1;
                break;
            }
        }
        fclose(file);
    }
    return found;
}