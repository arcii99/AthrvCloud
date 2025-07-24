//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char file_name[100];

    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    input_file = fopen(file_name, "r");

    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", file_name);

    output_file = fopen(file_name, "w");

    if (output_file == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    int num1, num2, sum;

    fscanf(input_file, "%d", &num1);
    fscanf(input_file, "%d", &num2);

    sum = num1 + num2;

    fprintf(output_file, "The sum of %d and %d is %d.\n", num1, num2, sum);

    fclose(input_file);
    fclose(output_file);

    printf("Output written to %s!\n", file_name);

    return 0;
}