//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    if(fptr == NULL) 
    {
        printf("File not found.\n");
        exit(1);
    }

    int sum = 0;
    char c;
    while ((c = fgetc(fptr)) != EOF)
    {
        sum += c;
    }
    
    printf("Checksum: %d\n", sum);
    fclose(fptr);
    return 0;
}