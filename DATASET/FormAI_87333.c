//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[20], ch;
    long int size, i;
    FILE *fp, *fq;

    printf("Enter the name of the file you wish to recover: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    printf("The size of file is %ld bytes.\n", size);

    fq = fopen("recovered.txt", "w");

    for (i = size - 1; i >= 0; i--)
    {
        fseek(fp, i, SEEK_SET);
        ch = fgetc(fp);
        fputc(ch, fq);
    }

    printf("File has been successfully recovered and saved as recovered.txt.");

    fclose(fp);
    fclose(fq);

    return 0;
}