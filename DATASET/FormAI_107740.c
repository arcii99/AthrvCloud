//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char file_name[50], virus_code[] = "c0deB0mb";
    FILE *file_ptr;

    printf("Welcome to C Antivirus Scanner!\n");

    printf("Please enter the name of the file you want to scan:");
    scanf("%s", file_name);

    file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL)
    {
        printf("ERROR: File does not exist or cannot be opened.\n");
        return 1;
    }

    char file_content[100000];

    while (fgets(file_content, 100000, file_ptr) != NULL)
    {
        if (strstr(file_content, virus_code) != NULL)
        {
            printf("*** WARNING: Virus Found! ***\n");
            printf("The virus code is: %s\n", virus_code);
            return 0;
        }
    }

    printf("Good news, your file is virus free!\n");

    fclose(file_ptr);

    return 0;
}