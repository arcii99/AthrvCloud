//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE_LIMIT 1048576 // 1 MB limit for file size

int scan_file(char *filename);
int is_infected(unsigned char *buffer, size_t size);
void print_virus_found(char *file, char *virus);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }
    // loop through all the files
    for(int i = 1; i < argc; i++) {
        printf("Scanning file %s...\n", argv[i]);
        if(scan_file(argv[i])) {
            printf("Virus found in file %s!\n", argv[i]);
        } else {
            printf("File %s is clean.\n", argv[i]);
        }
    }
    return 0;
}

// function to scan a single file for viruses
int scan_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Could not open file %s.\n", filename);
        return 0; // return 0 (not infected)
    }
    fseek(fp, 0, SEEK_END); // move file pointer to end of file
    size_t size = ftell(fp); // get file size
    if(size > FILE_SIZE_LIMIT) { // check file size limit
        printf("File %s is too large (%ld bytes). Skipping...\n", filename, size);
        fclose(fp);
        return 0; // return 0 (not infected)
    }
    rewind(fp); // move file pointer back to beginning of file
    unsigned char *buffer = (unsigned char *)malloc(size);
    if(!buffer) { // check if buffer allocation failed
        printf("Could not allocate buffer for file %s.\n", filename);
        fclose(fp);
        return 0; // return 0 (not infected)
    }
    fread(buffer, 1, size, fp); // read file content into buffer
    fclose(fp);
    if(is_infected(buffer, size)) { // check if file is infected
        print_virus_found(filename, "MyVirus"); // print virus found message
        return 1; // return 1 (infected)
    }
    free(buffer); // free memory allocated for buffer
    return 0; // return 0 (not infected)
}

// function to check if buffer contains virus signature
int is_infected(unsigned char *buffer, size_t size) {
    unsigned char signature[] = {0x4d, 0x79, 0x56, 0x69, 0x72, 0x75, 0x73}; // signature of MyVirus
    if(size < sizeof(signature)) { // check if buffer is smaller than signature
        return 0; // return 0 (not infected)
    }
    for(int i = 0; i < size - sizeof(signature) + 1; i++) { // loop through buffer
        int j;
        for(j = 0; j < sizeof(signature); j++) { // loop through signature
            if(buffer[i+j] != signature[j]) {
                break; // mismatch found, move on
            }
        }
        if(j == sizeof(signature)) {
            return 1; // signature found, file infected
        }
    }
    return 0; // signature not found, file not infected
}

// function to print message about virus found in file
void print_virus_found(char *file, char *virus) {
    printf("Virus %s found in file %s!\n", virus, file);
    printf("Warning: This file may be harmful. Do not open or execute it.\n");
}