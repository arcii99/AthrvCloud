//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for virus signatures
typedef struct Virus {
    char name[100];
    char signature[100];
} Virus;

// Array of virus signatures
Virus virus_db[] = {
    {"SARS-CoV-2", "70617373706F7274"},
    {"Ransomware", "52616E736F6D77617265"},
    {"Trojan", "54726F6A616E"},
    {"Worm", "576F726D"},
    {"Spyware", "53707977617265"}
};

// Function to read file content into a buffer
void read_file(FILE *fp, char *buffer) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        *buffer++ = c;
    }
    *buffer = '\0';
}

void scan_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found: %s\n", filename);
        return;
    }

    // Read file content into memory buffer
    char buffer[10000] = {0};
    read_file(fp, buffer);

    // Check for virus signature matches
    int num_signatures = sizeof(virus_db) / sizeof(Virus);
    for (int i = 0; i < num_signatures; i++) {
        char *match = strstr(buffer, virus_db[i].signature);
        if (match != NULL) {
            printf("Virus found: %s\n", virus_db[i].name);
            printf("Signature: %s\n", virus_db[i].signature);
            // Uncomment the line below to delete infected file
            //remove(filename);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide filename to scan\n");
        return 1;
    }

    printf("Scanning file: %s\n", argv[1]);
    scan_file(argv[1]);
    printf("Scan complete.\n");

    return 0;
}