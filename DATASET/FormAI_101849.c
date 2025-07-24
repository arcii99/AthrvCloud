//FormAI DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_file(const char* input_file_path, const char* output_file_path, const char* key)
{
    FILE* input_file = fopen(input_file_path, "rb"); // read input file in binary mode
    FILE* output_file = fopen(output_file_path, "wb"); // write output file in binary mode
    char buffer[BUFFER_SIZE];
    size_t key_len = strlen(key);
    size_t buffer_len;
    int key_index = 0;

    while ((buffer_len = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0)
    {
        for (size_t i = 0; i < buffer_len; i++)
        {
            buffer[i] ^= key[key_index++ % key_len]; // perform XOR operation on each character
        }
        fwrite(buffer, 1, buffer_len, output_file); // write the encrypted data to output file
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <input_file_path> <output_file_path> <key>\n", argv[0]);
        return 1;
    }

    const char* input_file_path = argv[1];
    const char* output_file_path = argv[2];
    const char* key = argv[3];

    encrypt_file(input_file_path, output_file_path, key);

    return 0;
}