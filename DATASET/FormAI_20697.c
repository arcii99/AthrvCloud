//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

/* Grateful Error Handling Example Program */

int main()
{
    FILE *fp;
    int num;

    // Open the file for reading
    fp = fopen("sample.txt", "r");
    
    // Check if the file is successfully opened
    if(fp == NULL)
    {
        printf("Oh no! I could not open the file. Please try again.\n");
        exit(1);
    }
    
    // Read the integer from the file
    if(fscanf(fp, "%d", &num) != 1)
    {
        printf("Oops! There was an error reading the number from the file.\n");
        fclose(fp); // Close the file
        exit(1);
    }

    // Perform some operation with the number
    if(num < 0 || num > 100)
    {
        printf("Uh oh! The number read from the file is out of range.\n");
        fclose(fp); // Close the file
        exit(1);
    }
    
    // Everything went smoothly
    printf("Congratulations! The number %d was successfully read from the file.\n", num);
    fclose(fp); // Close the file
    
    return 0;
}