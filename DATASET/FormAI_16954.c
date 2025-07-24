//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[50];
    int count = 0;
    printf("Hey there! I am going to help you count the number of characters in a file! :)\n\n");

    printf("Please enter the filename (include the extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("\nOops! The file could not be opened.\n");
        printf("Please make sure that the file exists and you have read permissions.\n");
        printf("Program terminating...\n");
        return 1;
    }
    else
    {
        printf("\nFile opened successfully! :)\n");
    }

    char ch = fgetc(fp);

    while (ch != EOF)
    {
        count++;
        ch = fgetc(fp);
    }

    printf("The number of characters in the file is: %d\n", count);

    fclose(fp);
    printf("\nFile closed successfully! :)\n\n");
    printf("Thank you for using my program! Have a nice day! :)\n");

    return 0;
}