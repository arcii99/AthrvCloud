//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3 // Change this to modify encryption key

int main(int argc, char *argv[])
{
    FILE *file_in, *file_out;
    char *in_filename, *out_filename, *temp_filename;
    char ch, new_ch;
    int i;

    if (argc != 3)
    {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(1);
    }

    in_filename = argv[1];
    out_filename = argv[2];
    temp_filename = malloc(strlen(out_filename) + 5); // Allocate memory for temporary filename
    sprintf(temp_filename, "%s.tmp", out_filename); // Generate temporary filename by adding .tmp to output filename

    // Open input and output files
    file_in = fopen(in_filename, "rb");
    file_out = fopen(temp_filename, "wb");

    // Encryption process
    while ((ch = fgetc(file_in)) != EOF)
    {
        new_ch = ch + KEY; // Add encryption key to character
        fputc(new_ch, file_out); // Write encrypted character to output file
    }

    // Close input and output files
    fclose(file_in);
    fclose(file_out);

    // Rename temporary file to output filename
    remove(out_filename);
    rename(temp_filename, out_filename);
    free(temp_filename);

    printf("Encryption complete.\n");

    return 0;
}