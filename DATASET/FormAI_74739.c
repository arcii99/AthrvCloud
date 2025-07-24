//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPATHLEN 512
#define MAXSIZE 1048576

unsigned char buffer[MAXSIZE];

void scan_file(char*);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s [file_path]\n", argv[0]);
        return 0;
    }
    scan_file(argv[1]);
    return 0;
}

void scan_file(char* path) {
    printf("Scanning file: %s\n", path);
    FILE *in_file = fopen(path, "rb");
    if (!in_file) {
        printf("Error: Unable to open file.\n");
        return;
    }
    fseek(in_file, 0, SEEK_END);
    long file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);
    size_t read_size = fread(buffer, 1, MAXSIZE - 1, in_file);
    if (ferror(in_file) || !feof(in_file) || read_size != file_size) {
        printf("Error: Unable to read file.\n");
        fclose(in_file);
        return;
    }
    fclose(in_file);
    
    // scan for virus signatures
    unsigned char sig_1[] = { 0x83, 0xec, 0x0c, 0x8b, 0x45, 0x08, 0x8b, 0x08, 0x8d, 0x54, 0x24, 0x04, 0x52, 0x50 };
    unsigned char sig_2[] = { 0x5e, 0x5f, 0x5d, 0xc2, 0x08, 0x00 };

    int found_sig_1 = 0, found_sig_2 = 0;
    for (int i = 0; i < MAXSIZE - sizeof(sig_1); i++) {
        if (memcmp(buffer + i, sig_1, sizeof(sig_1)) == 0) {
            found_sig_1 = 1;
            break;
        }
    }
    for (int i = 0; i < MAXSIZE - sizeof(sig_2); i++) {
        if (memcmp(buffer + i, sig_2, sizeof(sig_2)) == 0) {
            found_sig_2 = 1;
            break;
        }
    }
    if (found_sig_1 || found_sig_2) {
        printf("Virus found!\n");
        return;
    }
    printf("File is clean.\n");
}