//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 100000

int scan_file(char *filename);

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Please input the filename(s) to scan.\n");
        return 1;
    }

    int total_infected_files = 0;

    for(int i = 1; i < argc; i++) {
        int result = scan_file(argv[i]);
        if(result == -1) {
            printf("Error: could not open file '%s'\n", argv[i]);
            continue;
        }
        if(result == 1) {
            printf("File '%s' is infected.\n", argv[i]);
            total_infected_files++;
        }
    }

    printf("Scan complete. %d files infected.\n", total_infected_files);
    return 0;
}

int scan_file(char *filename) {
    FILE *fptr;
    unsigned char buffer[MAX_FILE_SIZE];

    fptr = fopen(filename, "rb");

    if(fptr == NULL) {
        return -1;
    }

    fseek(fptr, 0, SEEK_END);
    long int file_size = ftell(fptr);
    rewind(fptr);

    if(file_size < 2) {
        fclose(fptr);
        return 0;
    }

    fread(buffer, 1, MAX_FILE_SIZE, fptr);

    int infected = 0;
    for(int i = 0; i < file_size - 2; i++) {
        if(buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r') {
            infected = 1;
            break;
        }
    }

    fclose(fptr);
    return infected;
}