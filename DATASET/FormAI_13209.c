//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2, *fp3;
    char ch;
    int count;

    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "r");
    fp3 = fopen("file3.txt", "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
    {
        printf("Error in opening files!\n");
        exit(1);
    }

    // Copy content of file1.txt to file3.txt 
    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp3);
        count++;
    }

    // Copy content of file2.txt to file3.txt 
    while ((ch = fgetc(fp2)) != EOF)
    {
        fputc(ch, fp3);
        count++;
    }

    printf("Successfully merged %d characters from file1.txt and file2.txt to file3.txt.\n", count);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}