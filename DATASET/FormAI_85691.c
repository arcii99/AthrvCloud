//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[20];
    char ch;

    printf("Enter the name of the file to be opened: ");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Could not open file %s", filename);
        exit(1);
    }
    
    // Read and print content
    printf("The contents of %s file are:\n", filename);
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    
    // Close file
    fclose(fptr);
    
    return 0;
}