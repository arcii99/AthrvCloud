//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
    char filename[MAX_STR_LEN];

    // Prompt user for filename input
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file in read mode
    FILE* file = fopen(filename, "r");

    // If file cannot be opened, exit program
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Define signature patterns for viruses
    char* sig_pattern1 = "virus_malware1";
    char* sig_pattern2 = "virus_malware2";

    // Read file contents into buffer
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* buffer = (char*) malloc(size);
    fread(buffer, size, 1, file);

    // Check for signature patterns in buffer
    if (strstr(buffer, sig_pattern1) != NULL || strstr(buffer, sig_pattern2) != NULL) {
        printf("WARNING: File %s contains virus/malware\n", filename);
    } else {
        printf("SUCCESS: File %s is clean\n", filename);
    }

    // Cleanup
    free(buffer);
    fclose(file);

    return 0;
}