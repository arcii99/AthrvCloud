//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>

/*
This is a program that demonstrates how to handle files using C language.
We will read from an existing file 'input.txt' and write to a new file 'output.txt'.
The input file contains the numbers between 1 and 10, and the program will read these numbers and find their sum.
Then, it will write the sum to the output file.
*/

int main() {
    FILE *input_file, *output_file; // file pointers

    // Open input file in read mode
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Cannot open input file!\n");
        return 1; // terminate the program with error
    }

    // Open output file in write mode
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Cannot open output file!\n");
        return 1; // terminate the program with error
    }

    int num, sum = 0;
    while (fscanf(input_file, "%d", &num) != EOF) { // read until End-of-File
        sum += num; // add the number to sum
    }

    // Write the sum to the output file
    fprintf(output_file, "The total sum of numbers from 1 to 10 is: %d\n", sum);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File handling operations completed successfully.\n");

    return 0; // terminate the program with success
}