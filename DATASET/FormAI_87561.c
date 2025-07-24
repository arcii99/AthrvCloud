//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 100000

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }
    
    char *filename = argv[1];
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return 0;
    }

    char buf[MAX_FILE_LENGTH];
    size_t read_count = fread(buf, sizeof(char), MAX_FILE_LENGTH-1, fptr);
    fclose(fptr);

    if(read_count <= 0) {
        printf("Error: Failed to read file %s.\n", filename);
        return 0;
    }

    buf[read_count] = 0;
    int virus_found = 0;
    const char *virus_pattern = "virus_code";
    char *virus_pos = strstr(buf, virus_pattern);
    
    if(virus_pos != NULL) {
        virus_found = 1;
        printf("Virus found in file %s at position %ld.\n", filename, virus_pos-buf);
    } else {
        printf("No virus found in file %s.\n", filename);
    }
    
    return virus_found ? 1 : 0;
}