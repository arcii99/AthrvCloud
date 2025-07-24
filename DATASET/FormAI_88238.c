//FormAI DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    char key[] = "mysecretpassword";
    int keylen = strlen(key);

    char *buffer = (char *) malloc(1000 * sizeof(char));

    while (!feof(input_file)) {
        size_t bytes_read = fread(buffer, sizeof(char), 1000, input_file);

        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % keylen];
        }

        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    free(buffer);
    fclose(input_file);
    fclose(output_file);

    printf("File Encrypted successfully\n");
    return 0;
}