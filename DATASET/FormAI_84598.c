//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num;

    printf("Please select an option:\n1. Write to file\n2. Read from file");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            writeToFile();
            break;

        case 2:
            readFromFile();
            break;

        default:
            printf("Invalid choice. Please try again.");
    }

    return 0;
}

void writeToFile()
{
    FILE *fp;
    char filename[20], content[50];

    printf("Enter file name to write: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Error opening file.");
        exit(0);
    }

    printf("Enter content to write to file: ");
    scanf("%s", content);

    fputs(content, fp);

    printf("Content written to file successfully.");

    fclose(fp);
}

void readFromFile()
{
    FILE *fp;
    char filename[20], c;

    printf("Enter file name to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening file.");
        exit(0);
    }

    printf("Content of file:\n");

    while((c = getc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);
}