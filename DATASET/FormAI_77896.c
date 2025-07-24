//FormAI DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration
void custom_compress(char* input_file, char* output_file);

int main() {
    char input_file[] = "sample.txt";
    char output_file[] = "compressed_sample.bin";

    // calling compression function
    custom_compress(input_file, output_file);

    return 0;
}

void custom_compress(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "wb");

    // storing original file name and length
    int len = strlen(input_file);
    fwrite(&len, sizeof(int), 1, output);
    fwrite(input_file, sizeof(char), len, output);

    char ch, prev_ch = 0;
    int count = 1;

    // iterating through input file and compressing data
    while((ch = fgetc(input)) != EOF) {
        if(ch == prev_ch) {
            count++;
        } else {
            fwrite(&count, sizeof(int), 1, output);
            fputc(prev_ch, output);
            prev_ch = ch;
            count = 1;
        }
    }

    // writing remaining data
    fwrite(&count, sizeof(int), 1, output);
    fputc(prev_ch, output);

    // closing input and output files
    fclose(input);
    fclose(output);

    printf("Compression Successful!\n");
}