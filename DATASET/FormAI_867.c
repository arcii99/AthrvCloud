//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) 
{
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    strncpy(input, argv[1], BUFFER_SIZE);
    strncpy(output, argv[2], BUFFER_SIZE);

    FILE *fp_in, *fp_out;
    char buffer[BUFFER_SIZE];

    fp_in = fopen(input, "rb");
    if (fp_in == NULL) {
        perror("Failed to open input file");
        exit(1);
    }

    fp_out = fopen(output, "wb");
    if (fp_out == NULL) {
        perror("Failed to open output file");
        exit(1);
    }

    while (fread(buffer, 1, BUFFER_SIZE, fp_in)) {
        fwrite(buffer, 1, BUFFER_SIZE, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Backup of file %s completed successfully to %s\n", input, output);

    return 0;
}