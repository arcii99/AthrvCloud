//FormAI DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], buffer[100];
    int choice;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w+");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("1. Write to file\n");
    printf("2. Read file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter text to write to file: ");
            scanf(" %[^\n]", buffer);
            fprintf(fp, "%s", buffer);
            printf("Content written to file successfully.\n");
            break;
        case 2:
            while (fgets(buffer, 100, fp))
            {
                printf("%s", buffer);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    fclose(fp);

    return 0;
}