//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void encrypt(char *input_filename, char *output_filename, char *key) {
    int key_len = strlen(key);
    int key_index = 0;
    char buf[BUF_SIZE];
    FILE *input_file, *output_file;
    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");
    
    while (fgets(buf, BUF_SIZE, input_file) != NULL) {
        for (int i = 0; i < strlen(buf); i++) {
            int c = buf[i];
            if (c >= 'a' && c <= 'z') {
                c = ((c - 'a') + (key[key_index] - 'a')) % 26 + 'a';
                key_index = (key_index + 1) % key_len;
            } else if (c >= 'A' && c <= 'Z') {
                c = ((c - 'A') + (key[key_index] - 'A')) % 26 + 'A';
                key_index = (key_index + 1) % key_len;
            }
            fputc(c, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }
    encrypt(argv[1], argv[2], argv[3]);
    return 0;
}