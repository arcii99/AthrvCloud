//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH_LENGTH 1000
#define MAX_FILE_SIZE 5000

void scan_file(char* file_path);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./scanner <file_path>\n");
        return 0;
    }
    scan_file(argv[1]);
    return 0;
}

void scan_file(char* file_path) {
    char file_text[MAX_FILE_SIZE];
    FILE* file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_path);
        return;
    }
    int file_size = fread(file_text, 1, MAX_FILE_SIZE, file);
    fclose(file);
    printf("Scanning file %s...\n", file_path);
    int virus_found = 0;
    for (int i = 0; i < file_size; i++) {
        if (i <= file_size - 4 && strcmp(file_text + i, "virus") == 0) {
            printf("Virus found at offset %d\n", i);
            virus_found = 1;
        }
        if (!isprint(file_text[i])) {
            printf("Non-printable character found at offset %d\n", i);
        }
    }
    if (virus_found) {
        printf("Status: Virus found in file %s\n", file_path);
    } else {
        printf("Status: No viruses found in file %s\n", file_path);
    }
}