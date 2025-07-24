//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_VIRUS_SIGNATURES 100
#define MAX_VIRUS_NAME_SIZE 50
#define MAX_FILE_CONTENT_SIZE 10000

struct VirusSignature {
    char name[MAX_VIRUS_NAME_SIZE];
    char signatures[MAX_VIRUS_SIGNATURES][MAX_FILE_CONTENT_SIZE];
    int num_signatures;
};

// Function to load virus signatures from a file
int load_virus_signatures(struct VirusSignature *virus_signatures, const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    char signature[MAX_FILE_CONTENT_SIZE];
    char virus_name[MAX_VIRUS_NAME_SIZE];

    int virus_count = 0;
    while(fgets(virus_name, MAX_VIRUS_NAME_SIZE, file) != NULL) {
        virus_name[strcspn(virus_name, "\n")] = 0;
        strcpy(virus_signatures[virus_count].name, virus_name);
        virus_signatures[virus_count].num_signatures = 0;

        while(fgets(signature, MAX_FILE_CONTENT_SIZE, file) != NULL) {
            signature[strcspn(signature, "\n")] = 0;
            strcpy(virus_signatures[virus_count].signatures[virus_signatures[virus_count].num_signatures], signature);
            virus_signatures[virus_count].num_signatures++;

            if(strcmp(signature, "###VIRUS END###") == 0) {
                break;
            }
        }

        virus_count++;
    }

    fclose(file);

    return virus_count;
}

// Function to scan a file for viruses
int scan_file(const char *filename, struct VirusSignature *virus_signatures, int num_viruses) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    char file_content[MAX_FILE_CONTENT_SIZE];

    int virus_count = 0;
    for(int i=0; i<num_viruses; i++) {
        int virus_detected = 1;

        for(int j=0; j<virus_signatures[i].num_signatures; j++) {
            char *signature = virus_signatures[i].signatures[j];

            if(fgets(file_content, MAX_FILE_CONTENT_SIZE, file) == NULL) {
                virus_detected = 0;
                break;
            }

            file_content[strcspn(file_content, "\n")] = 0;

            if(strcmp(signature, file_content) != 0) {
                virus_detected = 0;
                break;
            }
        }

        if(virus_detected == 1) {
            printf("File %s is infected with virus: %s\n", filename, virus_signatures[i].name);
            virus_count++;
        }

        rewind(file);
    }

    fclose(file);

    return virus_count;
}

int main() {
    char filename[MAX_FILE_NAME_SIZE];

    struct VirusSignature virus_signatures[MAX_VIRUS_SIGNATURES];
    int num_viruses = load_virus_signatures(virus_signatures, "viruses.txt");

    printf("Enter file name to scan: ");
    scanf("%s", filename);

    int num_viruses_detected = scan_file(filename, virus_signatures, num_viruses);

    if(num_viruses_detected == 0) {
        printf("No viruses found.\n");
    }

    return 0;
}