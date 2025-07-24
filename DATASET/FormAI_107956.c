//FormAI DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    FILE* filePointer;
    char fileName[50];
    int num, sum=0;

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");

    if(filePointer == NULL)
    {
        perror("Error");
        printf("\nCould not open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    printf("The contents of the file are:\n");

    while(fscanf(filePointer, "%d", &num) > 0)
    {
        sum += num;
        printf("%d ", num);
    }

    if(feof(filePointer))
    {
        printf("\n\nEnd of file reached.\n");
    }
    else if(ferror(filePointer))
    {
        perror("Error");
        printf("\nAn error occurred while reading the file.");
        exit(EXIT_FAILURE);
    }

    fclose(filePointer);

    printf("\nThe sum of the numbers in the file is %d.\n", sum);

    return 0;
}