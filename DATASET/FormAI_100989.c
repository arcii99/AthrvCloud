//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";
    int a, b, sum;

    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    if (input_file == NULL) {
        printf("Error: could not open file %s for reading.\n", input_filename);
        return 1;
    }

    if (output_file == NULL) {
        printf("Error: could not open file %s for writing.\n", output_filename);
        return 1;
    }

    fscanf(input_file, "%d%d", &a, &b);
    sum = a + b;
    fprintf(output_file, "The sum of %d and %d is %d.\n", a, b, sum);

    printf("Results written to file %s.\n", output_filename);

    fclose(input_file);
    fclose(output_file);

    return 0;
}