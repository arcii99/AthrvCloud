//FormAI DATASET v1.0 Category: File Encyptor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define KEY 'F' // change this key to any character

int main(int argc, char *argv[]) {
    FILE *file_in, *file_out;
    char buffer[BUFFER_SIZE];
    size_t read_size;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file_in = fopen(argv[1], "rb");
    if (file_in == NULL) {
        fprintf(stderr, "Error: cannot open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    file_out = fopen(argv[2], "wb");
    if (file_out == NULL) {
        fprintf(stderr, "Error: cannot open %s for writing\n", argv[2]);
        fclose(file_in);
        exit(EXIT_FAILURE);
    }

    while ((read_size = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0) {
        for (size_t i = 0; i < read_size; i++) {
            buffer[i] ^= KEY; // apply XOR cipher with key
        }
        fwrite(buffer, 1, read_size, file_out);
    }

    fclose(file_in);
    fclose(file_out);
    printf("File has been encrypted successfully.\n");

    return 0;
}