//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define DATA_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    FILE* fin = fopen(input_file, "rb");
    if (fin == NULL) {
        printf("Failed to open input file '%s'!\n", input_file);
        return 1;
    }

    FILE* fout = fopen(output_file, "wb");
    if (fout == NULL) {
        printf("Failed to open output file '%s'!\n", output_file);
        fclose(fin);
        return 1;
    }

    unsigned char data[DATA_SIZE];
    size_t bytes_read;
    int sector_number = 0;
    size_t total_bytes_written = 0;

    while ((bytes_read = fread(data, sizeof(unsigned char), DATA_SIZE, fin)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (data[i] != 0xFF) {
                fseek(fout, sector_number * DATA_SIZE + i, SEEK_SET);
                fwrite(&data[i], sizeof(unsigned char), 1, fout);
                total_bytes_written++;
            }
        }
        sector_number++;
    }

    fclose(fin);
    fclose(fout);

    printf("Recovered %u bytes from file '%s' and saved in '%s'.\n", total_bytes_written, input_file, output_file);
    return 0;
}