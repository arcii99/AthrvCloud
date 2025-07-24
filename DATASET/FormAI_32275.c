//FormAI DATASET v1.0 Category: File handling ; Style: peaceful
/*

Here is an example program that demonstrates file handling in C. In this program, we will read a file named "input.txt" and create a new file named "output.txt" in which we will write the same content as in the input file but sorted in ascending order.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of each line in the file

int compare(const void *a, const void *b); // Function to compare two string elements

int main()
{
    FILE *input_file, *output_file;
    char line[MAX_LENGTH];
    char *lines[MAX_LENGTH];
    int total_lines = 0;

    // Open the input file in read mode
    input_file = fopen("input.txt", "r");

    // If file not found, print an error message and exit
    if (input_file == NULL)
    {
        printf("File not found!\n");
        exit(1);
    }

    // Read the file line by line and store each line in an array of strings
    while (fgets(line, MAX_LENGTH, input_file))
    {
        lines[total_lines] = strdup(line);
        total_lines++;
    }

    // Close the input file
    fclose(input_file);

    // Sort the array of strings using qsort in ascending order
    qsort(lines, total_lines, sizeof(char *), compare);

    // Open the output file in write mode
    output_file = fopen("output.txt", "w");

    // If file cannot be created, print an error message and exit
    if (output_file == NULL)
    {
        printf("Unable to create file!\n");
        exit(1);
    }

    // Write the sorted content to the output file
    for (int i = 0; i < total_lines; i++)
    {
        fputs(lines[i], output_file);
    }

    // Close the output file
    fclose(output_file);

    printf("Successfully sorted and written to output.txt!\n");

    // Free dynamically allocated memory
    for (int i = 0; i < total_lines; i++)
    {
        free(lines[i]);
    }

    return 0;
}

// Function to compare two string elements
int compare(const void *a, const void *b)
{
    const char **pa = (const char **)a;
    const char **pb = (const char **)b;

    return strcmp(*pa, *pb);
}