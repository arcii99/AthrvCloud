//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], data[1000];
    int ch, count = 0;

    printf("Enter the file name to recover data: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Error opening file.");
        exit(0);
    }

    printf("\nData Recovered from %s: \n\n", filename);

    while ((ch = fgetc(fp)) != EOF)
    {
        data[count] = ch;
        count++;
    }

    fclose(fp);

    printf("%s\n", data);

    return 0;
}