//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

// A function to check if a file exists or not
bool fileExists(const char *filename)
{
    struct stat buffer;    
    return (stat(filename, &buffer) == 0);
}

// A function to create a new file
void createFile(const char *filename)
{
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("\nError while creating the file: %s.\n", filename);
    }
    else
    {
        printf("\n%s file is successfully created.\n", filename);
        fclose(file);
    }
}

int main()
{
    char filename[50];
    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);
    
    if (fileExists(filename))
    {
        printf("\nFile %s already exists.\n", filename);
    }
    else
    {
        createFile(filename);
    }
    return 0;
}