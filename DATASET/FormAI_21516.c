//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    FILE* input_fp = fopen(input_file, "rb");
    if (!input_fp) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    FILE* output_fp = fopen(output_file, "wb");
    if (!output_fp) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    int total_bytes_read = 0;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        total_bytes_read += bytes_read;

        // search for the magic number indicating start of data
        char* data_start = strstr(buffer, "DATASTART");
        if (data_start) {
            // calculate offset from buffer start to data start
            int offset = data_start - buffer + strlen("DATASTART");
            // write data starting from offset to output file
            fwrite(buffer + offset, 1, bytes_read - offset, output_fp);
        }
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("Total bytes read from input file: %d\n", total_bytes_read);
    printf("Data recovery complete. Output written to file: %s\n", output_file);

    return 0;
}