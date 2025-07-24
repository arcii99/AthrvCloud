//FormAI DATASET v1.0 Category: QR code reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given character is alphanumeric or not
bool is_alpha_numeric(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

// Function to read QR code from the given file
char* read_qr_code(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return NULL;
    }
    int pos = 0, size = 128;
    char* buffer = malloc(size * sizeof(char));
    char ch = fgetc(fp);
    while(ch != EOF) {
        if(!is_alpha_numeric(ch)) {
            break;
        }
        buffer[pos++] = ch;
        // If the buffer is full, double its size
        if(pos == size) {
            size *= 2;
            buffer = realloc(buffer, size * sizeof(char));
        }
        ch = fgetc(fp);
    }
    fclose(fp);
    buffer[pos] = '\0';
    return buffer;
}

int main() {
    char* filename = "./sample_qr_code.txt";
    char* qr_code = read_qr_code(filename);
    if(qr_code == NULL) {
        exit(0);
    }
    printf("QR Code: %s\n", qr_code);
    free(qr_code);
    return 0;
}