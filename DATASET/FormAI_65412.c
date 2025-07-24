//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>

// Function to add two integers
void add(int a, int b)
{
    int sum = a + b;
    printf("The sum of %d and %d is %d.\n", a, b, sum);
}

// Function to subtract two integers
void subtract(int a, int b)
{
    int diff = a - b;
    printf("The difference between %d and %d is %d.\n", a, b, diff);
}

int main()
{
    FILE *fp;
    fp = fopen("example.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Write to file
    fprintf(fp, "This is an example C File Handling program written in the style of Ken Thompson.");

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("example.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    char buff[255];

    // Read from file
    fgets(buff, 255, fp);
    printf("%s", buff);

    // Close file
    fclose(fp);

    // Call functions
    add(4, 5);
    subtract(9, 3);

    return 0;
}