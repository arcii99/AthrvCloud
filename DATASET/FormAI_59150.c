//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <string.h>

void scan_file(char* filename) {
    printf("Scanning file: %s\n", filename);
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    // Scan each line of the file
    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp)) {
        line_number++;
        // Check for known virus signatures
        if (strstr(line, "virus") != NULL || strstr(line, "malware") != NULL) {
            printf("WARNING: Virus detected on line %d of file %s\n", line_number, filename);
            break;
        }
    }
    // Close the file
    fclose(fp);
}

int main(int argc, char** argv) {
    // Check for command line arguments
    if (argc < 2) {
        printf("Usage: antivirus [file1] [file2] ... [fileN]\n");
        return 0;
    }
    // Scan each file
    for (int i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }
    printf("Scan complete!\n");
    return 0;
}