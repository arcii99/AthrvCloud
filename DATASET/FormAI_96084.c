//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    // Opening the file in write mode and appending
    fptr = fopen("example.txt", "a");

    if (fptr == NULL)
    {
        printf("Error! Could not open file.");
        exit(1);
    }

    char buffer[100];
    int num;
    float f_num;

    // Taking input from user
    printf("Enter a string to write to file: ");
    fgets(buffer, 100, stdin);

    fprintf(fptr, "%s", buffer);

    printf("Enter an integer to write to file: ");
    scanf("%d", &num);

    fprintf(fptr, "%d\n", num);

    printf("Enter a floating point number to write to file: ");
    scanf("%f", &f_num);

    fprintf(fptr, "%.2f\n", f_num);

    printf("\nData written to file successfully!\n");

    // Closing the file
    fclose(fptr);

    return 0;
}