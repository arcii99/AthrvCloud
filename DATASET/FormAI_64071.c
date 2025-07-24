//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_file(char *file_name);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide a file name to scan.\n");
        return 1;
    }

    int count = 0;
    for (int i = 1; i < argc; i++) {
        count += scan_file(argv[i]);
    }

    if (count == 0) {
        printf("No virus found in the scanned file(s).\n");
    }

    return 0;
}

int scan_file(char *file_name) {
    FILE *file_ptr = fopen(file_name, "rb");
    int virus_count = 0;

    if (file_ptr == NULL) {
        printf("Error opening file: %s\n", file_name);
        return virus_count;
    }

    // Scan for virus signature
    char virus_signature[] = "badcode";
    int signature_length = strlen(virus_signature);

    char buffer[1024];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(char), 1024, file_ptr)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == virus_signature[0]) {
                int match_count = 1;
                for (int j = 1; j < signature_length; j++) {
                    if (i + j >= bytes_read) {
                        // Not enough data in buffer to complete the comparison
                        // Need to read more data from file
                        fseek(file_ptr, -bytes_read + i + 1, SEEK_CUR);
                        break;
                    }

                    if (buffer[i + j] == virus_signature[j]) {
                        match_count++;
                    } else {
                        break;
                    }
                }

                if (match_count == signature_length) {
                    printf("Virus found in the file: %s\n", file_name);
                    virus_count++;
                    break;
                }
            }
        }

        if (virus_count > 0) {
            break;
        }
    }

    fclose(file_ptr);

    return virus_count;
}