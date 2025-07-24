//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("error opening input file\n");
        return 1;
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("error opening output file\n");
        fclose(in_file);
        return 1;
    }

    // encryption key
    char key[] = "my secret key";

    int key_length = strlen(key);
    int i = 0;
    char byte;

    while (fread(&byte, 1, 1, in_file) == 1) {
        byte ^= key[i % key_length];
        fwrite(&byte, 1, 1, out_file);
        i++;
    }

    fclose(in_file);
    fclose(out_file);

    printf("encryption complete!\n");

    return 0;
}