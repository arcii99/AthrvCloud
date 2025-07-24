//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>

/* Calculate the checksum of the input file */
unsigned short int calc_checksum(FILE *input_file) {
    unsigned short int checksum = 0;
    int c;

    while ((c = fgetc(input_file)) != EOF) {
        checksum += (unsigned short int) c;
    }

    return checksum;
}

int main(int argc, char **argv) {
    /* Open the input file */
    FILE *input_file;
    if (argc < 2) {
        printf("Error: No input file provided.\n");
        return 1;
    } else {
        input_file = fopen(argv[1], "rb");
        if (input_file == NULL) {
            printf("Error: Unable to open input file '%s'\n", argv[1]);
            return 1;
        }
    }

    /* Calculate the checksum */
    unsigned short int checksum = calc_checksum(input_file);

    /* Display the result */
    printf("Checksum: %u\n", checksum);

    /* Cleanup */
    fclose(input_file);

    return 0;
}