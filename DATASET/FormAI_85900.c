//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp_input, *fp_output;
    char input_file[MAX_LINE_LENGTH], output_file[MAX_LINE_LENGTH];
    char ch;

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    fp_input = fopen(input_file, "r");

    if (fp_input == NULL) {
        printf("Error opening input file '%s'.\n", input_file);
        return EXIT_FAILURE;
    }

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    fp_output = fopen(output_file, "w");

    if (fp_output == NULL) {
        printf("Error opening output file '%s'.\n", output_file);
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(fp_input)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 32;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        fputc(ch, fp_output);
    }

    fclose(fp_input);
    fclose(fp_output);

    printf("File contents converted successfully.\n");

    return EXIT_SUCCESS;
}