//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan file for virus signature
// returns true if virus found, otherwise false
int scan_for_virus(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return -1;
    }
    char buffer[1024];
    int virus_found = 0;
    while (fread(buffer, 1, sizeof(buffer), file) > 0 && !virus_found) {
        if (strstr(buffer, "virus_signature") != NULL) {
            printf("Virus found in file: %s\n", filename);
            virus_found = 1;
        }
    }
    fclose(file);
    return virus_found;
}

// Driver program to scan files and return number of infected files
int main(int argc, char* argv[]) {
    int infected_files = 0;
    for (int i = 1; i < argc; i++) {
        if (scan_for_virus(argv[i])) {
            infected_files++;
        }
    }
    printf("Number of infected files: %d\n", infected_files);
    return 0;
}