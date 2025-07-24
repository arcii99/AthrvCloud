//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_VIRUS_SIGNATURES 100
#define MAX_SIGNATURE_LEN 50
#define MAX_FILE_PATH 100

char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LEN]; // Global array to store virus signatures
int n_sigs = 0;

// Function to add a virus signature to the global array
void add_virus_signature(char* sig) {
    if (n_sigs >= MAX_VIRUS_SIGNATURES) {
        printf("ERROR: Maximum number of virus signatures reached\n");
        exit(1);
    }

    strncpy(virus_signatures[n_sigs], sig, MAX_SIGNATURE_LEN);
    n_sigs++;
}

// Function to scan a file for virus signatures
int scan_file(char* file_path) {
    FILE* fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("ERROR: Cannot open file %s\n", file_path);
        exit(1);
    }

    char line[MAX_SIGNATURE_LEN];
    int line_num = 1;
    int n_matches = 0;
    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; i < n_sigs; i++) {
            if (strstr(line, virus_signatures[i])) {
                printf("Match found in file %s, line %d: %s\n", file_path, line_num, virus_signatures[i]);
                n_matches++;
            }
        }
        line_num++;
    }

    fclose(fp);

    return n_matches;
}

int main() {
    // Add virus signatures to the global array
    add_virus_signature("evil_code");
    add_virus_signature("malware");

    // Scan files
    int n_infected_files = 0;
    char file_path[MAX_FILE_PATH];
    while (1) {
        printf("Enter file path (or 'quit' to exit): ");
        scanf("%s", file_path);

        if (strcmp(file_path, "quit") == 0) {
            break;
        }

        if (scan_file(file_path) > 0) {
            printf("File %s is infected\n", file_path);
            n_infected_files++;
        }
        else {
            printf("File %s is not infected\n", file_path);
        }
    }

    printf("Scanning complete. %d infected files found.\n", n_infected_files);

    return 0;
}