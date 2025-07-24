//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    int num;
    FILE *fptr;
 
    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
 
    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return errno;
    }
 
    if(fscanf(fptr, "%d", &num) == EOF)
    {
        if(ferror(fptr))
        {
            fprintf(stderr, "Error reading file: %s\n", strerror(errno));
            return errno;
        }
        else
        {
            fprintf(stderr, "End of file reached without reading any data.\n");
            return 1;
        }
    }
 
    printf("Number read from file: %d\n", num);
 
    if(fclose(fptr) != 0)
    {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        return errno;
    }
 
    return 0;
}