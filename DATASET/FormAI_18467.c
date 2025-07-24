//FormAI DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // File pointer to hold reference to our file
    FILE *fptr;

    // Open file for writing
    fptr = fopen("./secret_data.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get secret data from user
    printf("Please enter your secret data: ");
    char secret_data[50];
    fgets(secret_data, 50, stdin);

    // Write secret data to file in a secure way
    int secret_data_len = strlen(secret_data);
    for (int i = 0; i < secret_data_len; i++)
    {
        fputc((int)secret_data[i] + 5, fptr);
    }

    // Close file
    fclose(fptr);

    // Re-open file for reading
    fptr = fopen("./secret_data.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read secret data from file and print it
    printf("Your secret data is: ");
    char c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", (char)(c - 5));
        c = fgetc(fptr);
    }

    // Close file
    fclose(fptr);

    return 0;
}