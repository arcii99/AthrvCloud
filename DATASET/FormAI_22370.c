//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    char ch, fname1[20], fname2[20];

    printf("Enter the source filename: ");
    scanf("%s", fname1);

    fp1 = fopen(fname1, "r"); //opening file in read mode
    if(fp1 == NULL)
    {
        printf("Cannot open file %s\n", fname1);
        exit(0);
    }

    printf("Enter the destination filename: ");
    scanf("%s", fname2);

    fp2 = fopen(fname2, "w"); //opening file in write mode
    if(fp2 == NULL)
    {
        printf("Cannot open file %s\n", fname2);
        exit(0);
    }

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2); //writing the content of first file to second file
    }

    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}