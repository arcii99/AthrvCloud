//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_VIRUS_SIGNATURES 1024
#define MAX_SIGNATURE_LENGTH 128
#define MAX_FILE_SIZE 1048576 // 1 MB

int scan_file(const char* file_path, const char* virus_signatures_path);
int load_virus_signatures(const char* virus_signatures_path, char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH], int num_signatures);
int check_file(const char* file_path, char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH], int num_signatures);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [file_path] [virus_signatures_path]\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    char* virus_signatures_path = argv[2];

    int result = scan_file(file_path, virus_signatures_path);

    if (result == 0) {
        printf("File is clean\n");
    } else if (result == 1) {
        printf("File is infected\n");
    } else {
        printf("Error scanning file\n");
    }

    return 0;
}

int scan_file(const char* file_path, const char* virus_signatures_path) {
    char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH];
    int num_signatures = load_virus_signatures(virus_signatures_path, virus_signatures, MAX_VIRUS_SIGNATURES);

    if (num_signatures == -1) {
        return -1;
    }

    return check_file(file_path, virus_signatures, num_signatures);
}

int load_virus_signatures(const char* virus_signatures_path, char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH], int num_signatures) {
    FILE *fp;

    fp = fopen(virus_signatures_path, "r");

    if (fp == NULL) {
        printf("Error loading virus signatures\n");
        return -1;
    }

    int i = 0;
    char signature[MAX_SIGNATURE_LENGTH];

    while (fgets(signature, MAX_SIGNATURE_LENGTH, fp) != NULL) {
        if (i >= num_signatures) {
            printf("Max number of virus signatures reached\n");
            break;
        }

        strtok(signature, "\n"); // remove newline character from signature
        strncpy(virus_signatures[i], signature, MAX_SIGNATURE_LENGTH);
        i++;
    }

    fclose(fp);

    return i;
}

int check_file(const char* file_path, char virus_signatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH], int num_signatures) {
    FILE *fp;
    unsigned char file_buffer[MAX_FILE_SIZE];

    fp = fopen(file_path, "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size too large\n");
        fclose(fp);
        return -1;
    }

    fread(file_buffer, file_size, 1, fp);

    for (int i = 0; i < num_signatures; i++) {
        if (strstr(file_buffer, virus_signatures[i]) != NULL) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}