//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_file(char *filename);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    scan_file(filename);

    return 0;
}

void scan_file(char *filename) {
    FILE *file;
    char c, signature[10];
    int i = 0, infected = 0;

    if((file = fopen(filename, "r")) == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Scanning file '%s'...\n", filename);

    while((c = fgetc(file)) != EOF) {
        // Check for virus signature
        if(c == 'C') {
            signature[i++] = c;
        } else if(c == 'V' && i == 1) {
            signature[i++] = c;
        } else if(c == 'S' && i == 2) {
            signature[i++] = c;
        } else if(c == 'c' && i == 3) {
            signature[i++] = c;
        } else if(c == 'a' && i == 4) {
            signature[i++] = c;
        } else if(c == 'n' && i == 5) {
            signature[i++] = c;
        } else if(c == 'n' && i == 6) {
            signature[i++] = c;
        } else if(c == 'e' && i == 7) {
            signature[i++] = c;
        } else if(c == 'd' && i == 8) {
            signature[i++] = c;
        } else {
            i = 0;
        }

        // Possible virus found
        if(i == 9) {
            printf("Possible virus found in file '%s' at offset %ld\n", filename, ftell(file) - 9);
            infected = 1;
            i = 0;
        }
    }

    if(!infected) {
        printf("File '%s' is clean\n", filename);
    }

    fclose(file);
}