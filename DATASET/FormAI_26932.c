//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_DATA_LEN 1000

void recover_data(char *filename);

int main()
{
    char filename[MAX_FILENAME_LEN];

    printf("Enter the filename containing the data to be recovered: ");
    scanf("%s", filename);

    recover_data(filename);

    return 0;
}

void recover_data(char *filename)
{
    FILE *fp;
    char data[MAX_DATA_LEN];
    int i;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file for reading.\n");
        exit(1);
    }

    printf("Recovered data:\n");

    for (i = 0; i < MAX_DATA_LEN; i++)
    {
        fscanf(fp, "%c", &data[i]);
    }

    fclose(fp);

    printf("%s", data);
}