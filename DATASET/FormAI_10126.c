//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Unable to open input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Unable to open output file: %s\n", argv[2]);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        int length = strlen(buffer);
        for (int i = 0; i < length; ++i) {
            if (buffer[i] == ' ') {
                fputc('_', output_file);
            } else {
                fputc(buffer[i], output_file);
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}