//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB KB*KB
#define GB MB*KB

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error: Expected filename as command-line argument\n");
        return 1;
    }

    char* file = argv[1];
    FILE* fp = fopen(file, "rb");

    if(!fp)
    {
        printf("Error: Could not open file %s\n", file);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fclose(fp);

    printf("Size of %s\n", file);

    if (file_size < KB)
    {
        printf("%ld B\n", file_size);
    }
    else if (file_size < MB)
    {
        printf("%ld KB\n", file_size/KB);
    }
    else if (file_size < GB)
    {
        printf("%ld MB\n", file_size/MB);
    }
    else
    {
        printf("%ld GB\n", file_size/GB);
    }

    return 0;
}