//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char filename[100];
    char c;

    printf("Enter the filename of the Ebook: ");
    scanf("%s", filename);

    // Attempt to open the file
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read through the file character by character and print to console
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }

    // Close the file and exit
    fclose(file);
    return 0; 
}