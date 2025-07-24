//FormAI DATASET v1.0 Category: Data recovery tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recover_data(char *filename) {
    FILE *infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    char header[10];
    int start_block;
    int size;
    int num_recovered = 0;

    while (fread(header, sizeof(header), 1, infile)) {
        if (memcmp(header, "DATA", 4) == 0) {
            start_block = (int)header[4];
            size = (int)header[5];

            char *data = malloc(size);
            fseek(infile, start_block, SEEK_SET);
            fread(data, size, 1, infile);

            char output_filename[20];
            sprintf(output_filename, "recovered_%d.txt", num_recovered);
            FILE *outfile = fopen(output_filename, "w");
            if (outfile == NULL) {
                printf("Unable to create output file\n");
                exit(1);
            }

            fwrite(data, size, 1, outfile);
            fclose(outfile);
            free(data);
            num_recovered++;
        }
    }

    fclose(infile);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    printf("Attempting to recover data from %s\n", argv[1]);
    recover_data(argv[1]);
    printf("Data recovery complete!\n");
    return 0;
}