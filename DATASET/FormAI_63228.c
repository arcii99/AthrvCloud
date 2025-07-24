//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    char source_file_name[50], target_file_name[50];
    FILE *source_file, *target_file;
    char buffer[BUFFER_SIZE];

    printf("Enter the source file name (with extension) : ");
    scanf("%s", source_file_name);
    printf("Enter the target file name (with extension) : ");
    scanf("%s", target_file_name);

    source_file = fopen(source_file_name, "rb");

    if(source_file == NULL)
    {
        printf("%s not found.\n", source_file_name);
        return 1;
    }

    target_file = fopen(target_file_name, "wb");

    if(target_file == NULL)
    {
        fclose(source_file);
        printf("%s could not be created.\n", target_file_name);
        return 2;
    }

    while(fread(buffer, BUFFER_SIZE,1,source_file))
    {
        fwrite(buffer, BUFFER_SIZE,1,target_file);
    }

    fclose(source_file);
    fclose(target_file);

    printf("\n%s successfully backed up to %s.\n", source_file_name, target_file_name);
    return 0;
}