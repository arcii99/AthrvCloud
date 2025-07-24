//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "this_is_a_virus" // Define virus signature

void scan_file(char* filename);
void remove_virus(char* filename);
int is_virus(FILE* file);

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Please specify file name(s) to scan.\n");
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }
    return 0;
}

void scan_file(char* filename) {
    // Open file
    FILE* file = fopen(filename, "rb+");
    if(file == NULL) {
        printf("Unable to open file %s.\n", filename);
        return;
    }
    // Check if file contains virus
    if(is_virus(file)) {
        printf("Virus detected in file %s.\n", filename);
        // Remove virus
        remove_virus(filename);
    }
    else {
        printf("File %s is clean.\n", filename);
    }
    fclose(file);
}

int is_virus(FILE* file) {
    char buffer[strlen(VIRUS_SIGNATURE)];
    // Read file and check for virus signature
    fread(buffer, sizeof(char), strlen(VIRUS_SIGNATURE), file);
    rewind(file); // Go back to beginning of file
    if(strcmp(buffer, VIRUS_SIGNATURE) == 0) {
        return 1; // Virus detected
    }
    else {
        return 0; // Virus not detected
    }
}

void remove_virus(char* filename) {
    // Open file
    FILE* file = fopen(filename, "rb+");
    if(file == NULL) {
        printf("Unable to open file %s.\n", filename);
        return;
    }
    // Get file size
    fseek(file, 0L, SEEK_END);
    int filesize = ftell(file);
    rewind(file); // Go back to beginning of file
    // Allocate buffer
    char* buffer = malloc(filesize * sizeof(char));
    if(buffer == NULL) {
        printf("Unable to allocate memory.\n");
        fclose(file);
        return;
    }
    // Read file
    fread(buffer, sizeof(char), filesize, file);
    // Remove virus signature
    char* virus_start = strstr(buffer, VIRUS_SIGNATURE);
    memset(virus_start, ' ', strlen(VIRUS_SIGNATURE));
    // Write file
    rewind(file); // Go back to beginning of file
    fwrite(buffer, sizeof(char), filesize, file);
    // Cleanup
    free(buffer);
    fclose(file);
    printf("File %s cleaned of virus.\n", filename);
}