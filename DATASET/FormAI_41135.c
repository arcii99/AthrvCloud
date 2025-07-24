//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>

int main()
{
    FILE *fptr;
    char filename[100];
    char data[100];

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        printf("Error: Could not open file.");
        return 1;
    }

    printf("Enter data to be written to %s: ", filename);
    scanf("%s", data);

    fprintf(fptr, "%s", data);
    fclose(fptr);

    printf("Data saved successfully.\n");

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error: Could not open file.");
        return 1;
    }

    printf("Data read from %s: ", filename);

    while (fgets(data, 100, fptr) != NULL)
    {
        printf("%s", data);
    }

    fclose(fptr);

    return 0;
}