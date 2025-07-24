//FormAI DATASET v1.0 Category: File handling ; Style: content
/* In this program, we create a file named "data.txt" and write some data into it. Then we read the data from the file and print it on the screen. */

#include <stdio.h>

int main()
{
    FILE *fp; /* file pointer */

    char string[] = "This is some data that we will store in a file.\n";

    /* create and open the file */
    fp = fopen("data.txt", "w");

    /* check if file was successfully created and opened */
    if (fp == NULL)
    {
        printf("Error creating file.");
        return 1;
    }

    /* write the data into the file */
    fputs(string, fp);

    /* close the file */
    fclose(fp);

    /* open the file for reading */
    fp = fopen("data.txt", "r");

    /* check if file was successfully opened */
    if (fp == NULL)
    {
        printf("Error opening file.");
        return 1;
    }

    /* read the data from the file and print it on the screen */
    printf("Data from the file:\n");
    char c = fgetc(fp);
    while (c != EOF)
    {
        putchar(c);
        c = fgetc(fp);
    }

    /* close the file */
    fclose(fp);

    return 0;
}