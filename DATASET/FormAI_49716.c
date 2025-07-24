//FormAI DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;
    char filename[50], ch;
    long size;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nFile could not be opened");
        exit(0);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) malloc(size);

    if (buffer == NULL)
    {
        printf("\nMemory allocation error");
        exit(1);
    }

    fread(buffer, size, 1, file);
    fclose(file);

    printf("\nThe contents of file are:\n\n");

    for (int i = 0; i < size; i++)
    {
        ch = buffer[i];
        printf("%c", ch);
    }

    free(buffer);
    return 0;
}