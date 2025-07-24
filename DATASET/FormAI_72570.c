//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define SCAN_PATH "./scan_folder/" // Folder to scan
#define SIGNATURES_FILE "virus_signatures.txt" // File containing virus signatures

// Virus signature struct
typedef struct virus_signature_tag {
    char name[50];
    char signature[10];
} virus_signature;

int read_virus_signatures(virus_signature** signatures_ptr, int* count_ptr) {
    FILE* signature_file = fopen(SIGNATURES_FILE, "r");
    if (signature_file == NULL) {
        printf("Could not open file %s\n", SIGNATURES_FILE);
        return -1;
    }

    // Get number of signatures
    *count_ptr = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), signature_file) != NULL) (*count_ptr)++;

    // Allocate memory for signatures array
    *signatures_ptr = (virus_signature*) malloc((*count_ptr) * sizeof(virus_signature));

    // Read in signatures
    rewind(signature_file);
    int i = 0;
    while (fgets(buffer, sizeof(buffer), signature_file) != NULL) {
        sscanf(buffer, "%s %s", (*signatures_ptr)[i].name, (*signatures_ptr)[i].signature);
        i++;
    }

    fclose(signature_file);
    return 1;
}

int scan_file(char* path, virus_signature* signatures, int num_signatures) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        printf("Could not open file %s\n", path);
        return -1;
    }

    // Read in file contents
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    char* file_contents = (char*) malloc(file_size);
    int len = fread(file_contents, 1, file_size, file);
    fclose(file);
    if (len != file_size) {
        printf("Error reading file %s\n", path);
        return -1;
    }

    // Check against virus signatures
    for (int i = 0; i < num_signatures; i++) {
        int sig_len = strlen(signatures[i].signature);
        int file_offset = 0;
        while (file_offset <= file_size - sig_len) {
            if (memcmp(file_contents + file_offset, signatures[i].signature, sig_len) == 0) {
                printf("%s: %s\n", path, signatures[i].name);
                return 1;
            }
            file_offset++;
        }
    }

    return 0;
}

int scan_directory(char* path, virus_signature* signatures, int num_signatures) {
    DIR* dir;
    struct dirent* entry;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Could not open directory %s\n", path);
        return -1;
    }
    int result = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only check regular files
            char file_path[100];
            strcpy(file_path, path);
            strcat(file_path, entry->d_name);
            result += scan_file(file_path, signatures, num_signatures);
        }
    }
    closedir(dir);
    return result;
}

int main(int argc, char** argv) {
    // Read in virus signatures
    int num_signatures;
    virus_signature* signatures;
    if (read_virus_signatures(&signatures, &num_signatures) == -1) return -1;

    // Scan directory for viruses
    int num_infected = scan_directory(SCAN_PATH, signatures, num_signatures);
    if (num_infected > 0) printf("Found %d infected file(s)!\n", num_infected);
    else printf("Scan completed. No infected files found.\n");

    free(signatures);
    return 0;
}