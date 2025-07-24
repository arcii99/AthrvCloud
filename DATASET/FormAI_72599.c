//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 512
#define VIRUS_SIGNATURES "viruses.txt"

void scan_file(char *filename);
void check_file(FILE *file, char *filename);
int check_for_virus(char *line);
void log_virus(char *filename, char *virus);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify a file to scan.");
        return 1;
    }

    char *filename = argv[1];
    scan_file(filename);

    return 0;
}

void scan_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.");
        return;
    }

    check_file(file, filename);
    fclose(file);
}

void check_file(FILE *file, char *filename) {
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file) != NULL) {
        if (check_for_virus(line)) {
            log_virus(filename, line);
        }
    }
}

int check_for_virus(char *line) {
    FILE *virus_file = fopen(VIRUS_SIGNATURES, "r");
    if (virus_file == NULL) {
        printf("Virus signature database not found.");
        return 0;
    }

    char virus_signature[LINE_SIZE];

    while (fgets(virus_signature, LINE_SIZE, virus_file) != NULL) {
        virus_signature[strcspn(virus_signature, "\n")] = '\0'; // Remove new line character from signature

        if (strstr(line, virus_signature) != NULL) {
            fclose(virus_file);
            return 1;
        }
    }
    fclose(virus_file);
    return 0;
}

void log_virus(char *filename, char *virus) {
    FILE *virus_log = fopen("virus_log.txt", "a");
    if (virus_log == NULL) {
        printf("Unable to write virus log.");
        return;
    }

    fprintf(virus_log, "%s : %s", filename, virus);
    fclose(virus_log);
}