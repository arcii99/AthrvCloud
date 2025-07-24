//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";
    int num1, num2, sum, product;

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", input_filename);
        return 1;
    }

    // Read two integers from input file
    fscanf(input_file, "%d %d", &num1, &num2);

    // Perform some calculations
    sum = num1 + num2;
    product = num1 * num2;

    // Close input file
    fclose(input_file);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open file '%s'\n", output_filename);
        return 1;
    }

    // Write results to output file
    fprintf(output_file, "Sum: %d\n", sum);
    fprintf(output_file, "Product: %d\n", product);

    // Close output file
    fclose(output_file);

    printf("Results written to file '%s'\n", output_filename);

    return 0;
}