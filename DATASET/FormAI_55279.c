//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./enc <input_file> <output_file>\n");
        return 1;
    }

    // open input file
    FILE *in_file = fopen(argv[1], "r");
    if (!in_file) {
        printf("Error: cannot open input file\n");
        return 1;
    }

    // open output file
    FILE *out_file = fopen(argv[2], "w");
    if (!out_file) {
        printf("Error: cannot open output file\n");
        return 1;
    }

    // key for file encryption
    char key[] = "S3cr3tK3y";

    // read input file
    char c;
    while ((c = fgetc(in_file)) != EOF) {
        if (isalpha(c)) {
            // encrypt character
            int index = toupper(c) - 'A';
            c = key[index % strlen(key)];
        }

        // write encrypted character to output file
        fputc(c, out_file);
    }

    // close files
    fclose(in_file);
    fclose(out_file);

    printf("Encryption completed successfully!\n");

    return 0;
}