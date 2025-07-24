//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* This program takes an input image file and adds a watermark to it */
int main(int argc, char *argv[]) {
    FILE *f_in, *f_out;
    char *input_file, *output_file;
    int c;

    /* Parse command line arguments */
    if(argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    input_file = argv[1];
    output_file = argv[2];

    /* Open input file for reading */
    f_in = fopen(input_file, "rb");
    if(!f_in) {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    /* Open output file for writing */
    f_out = fopen(output_file, "wb");
    if(!f_out) {
        printf("Error opening output file\n");
        fclose(f_in);
        exit(EXIT_FAILURE);
    }

    /* Add watermark to output file */
    fprintf(f_out, "This is a digital watermark\n");

    /* Copy contents of input file to output file */
    while((c = fgetc(f_in)) != EOF) {
        fputc(c, f_out);
    }

    /* Close files */
    fclose(f_in);
    fclose(f_out);

    printf("Watermark added to %s and saved as %s\n", input_file, output_file);

    return 0;
}