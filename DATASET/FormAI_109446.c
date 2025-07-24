//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_LEN 50

int virus_detected = 0;

// This function scans the file for virus signature and returns 1 if it is found
int scan_for_virus(char *file_contents, int size) {
    char virus_signature[MAX_LEN] = "execute_malware()";
    for (int i = 0; i < size; i++) {
        if (file_contents[i] == virus_signature[0]) {
            int j = 0, k = i;
            while (file_contents[k] == virus_signature[j] && virus_signature[j] != '\0') {
                j++;
                k++;
            }
            if (virus_signature[j] == '\0') {
                printf("\nVirus signature found at offset %d\n", i);
                virus_detected = 1;
                return 1;
            }
        }
    }
    return 0;
}

// This function reads the file and calls scan_for_virus() function on its contents
void scan_file(char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("\nError opening file %s\n", filename);
        return;
    }
    char file_contents[MAX_LEN];
    int size = 0;
    while (fgets(file_contents, MAX_LEN, fptr) != NULL) {
        size += strlen(file_contents);
        if (scan_for_virus(file_contents, strlen(file_contents))) {
            printf("\nVirus detected in file %s\n", filename);
            fclose(fptr);
            return;
        }
    }
    printf("\nFile %s scanned successfully\n", filename);
    fclose(fptr);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: ./antivirus <filename1> <filename2> ...\n");
        return 0;
    }
    int num_files = argc - 1;
    char *filenames[MAX_FILES];
    for (int i = 0; i < num_files; i++) {
        filenames[i] = argv[i+1];
    }
    printf("***** Initializing Antivirus Scanner *****\n\n");
    for (int i = 0; i < num_files; i++) {
        printf("Scanning file: %s\n", filenames[i]);
        scan_file(filenames[i]);
        if (virus_detected) {
            break;
        }
    }
    if (!virus_detected) {
        printf("\nNo viruses detected.\n");
    }
    printf("\n***** Antivirus Scan Complete *****\n");
    return 0;
}