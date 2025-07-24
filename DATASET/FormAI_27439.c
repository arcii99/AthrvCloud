//FormAI DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void writeToFile(FILE *file, int depth);

int main()
{
    FILE *file;
    int depth;

    printf("Enter depth:");
    scanf("%d", &depth);

    file = fopen("data.txt", "w");

    writeToFile(file, depth);

    fclose(file);

    return 0;
}

void writeToFile(FILE *file, int depth)
{
    if(depth > 0)
    {
        fputc('(', file);
        writeToFile(file, depth - 1);
        fputc(')', file);
        writeToFile(file, depth - 1);
    }
    else
    {
        fputc('X', file);
    }
}