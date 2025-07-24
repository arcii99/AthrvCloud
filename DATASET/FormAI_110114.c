//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char c;
    int virus_count = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == 'v' || c == 'i' || c == 'r' || c == 'u' || c == 's') { // Check for virus text
            virus_count++;
            printf("Warning: virus detected in file %s\n", filename);
            break;
        }
    }
    fclose(file);
    return virus_count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]...\n", argv[0]);
        return 1;
    }
    int total_viruses = 0;
    for (int i = 1; i < argc; i++) {
        total_viruses += scan_file(argv[i]);
    }
    printf("Total viruses detected: %d\n", total_viruses);
    return 0;
}