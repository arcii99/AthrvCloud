//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 512

void read_qr_code(char*);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: qr_reader [FILE_PATH]\n");
        exit(1);
    }
    
    read_qr_code(argv[1]);

    return 0;
}

void read_qr_code(char* file_path) {
    FILE* file = fopen(file_path, "r");

    if(file == NULL) {
        printf("Error: Could not read file\n");
        exit(1);
    }

    char data[MAX_PATH];
    memset(data, 0, sizeof(data));
    fgets(data, MAX_PATH, file);

    if(strlen(data) > 0) {
        printf("QR Code Data: %s", data);
    } else {
        printf("Error: QR Code data not found\n");
        exit(1);
    }

    fclose(file);

    read_qr_code(file_path); // Recursively call function to keep reading codes
}