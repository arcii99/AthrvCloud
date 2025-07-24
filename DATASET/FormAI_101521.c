//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Enter the name of the file ");

    char filename[100];
    scanf("%s", filename);
    printf("\n");

    FILE *file_ptr = fopen(filename, "w");

    if (file_ptr == NULL)
    {
        printf("Error opening file %s", filename);
        exit(1);
    }

    printf("Enter the content to be written in the file: ");
    char content[1000];
    scanf("%s", content);
    printf("\n");

    fprintf(file_ptr, "%s", content);

    fclose(file_ptr);

    FILE *read_ptr = fopen(filename, "r");

    if (read_ptr == NULL)
    {
        printf("Error opening file %s", filename);
        exit(1);
    }

    printf("Content of the file: ");
    char read_content[1000];

    while (fgets(read_content, sizeof(read_content), read_ptr) != NULL)
    {
        printf("%s", read_content);
    }

    fclose(read_ptr);

    return 0;
}