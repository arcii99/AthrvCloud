//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_VIRUS_SIGNATURES 1000
#define MAX_SIGNATURE_LENGTH 50

typedef struct {
    char signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH];
    int count;
} virus_db;

void add_virus_signature(virus_db *database, char *signature) {
    if (database->count < MAX_VIRUS_SIGNATURES) {
        strcpy(database->signatures[database->count++], signature);
    }
}

void load_virus_database(virus_db *database) {
    printf("Loading virus database...\n");
    add_virus_signature(database, "signature1");
    add_virus_signature(database, "signature2");
    add_virus_signature(database, "signature3");
    printf("Virus database loaded with %d signatures.\n", database->count);
}

void scan_file(virus_db *database, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
    } else {
        char buffer[MAX_SIGNATURE_LENGTH];
        int virus_count = 0;
        while (fgets(buffer, MAX_SIGNATURE_LENGTH, fp) != NULL) {
            for (int i = 0; i < database->count; i++) {
                if (strstr(buffer, database->signatures[i]) != NULL) {
                    virus_count++;
                    printf("Virus detected in file: %s\n", filename);
                    break;
                }
            }
        }
        fclose(fp);
        printf("Scan complete. %d viruses detected in file: %s\n", virus_count, filename);
    }
}

int main() {
    virus_db database;
    database.count = 0;
    load_virus_database(&database);

    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to scan: ");
    scanf("%s", filename);
    scan_file(&database, filename);

    return 0;
}