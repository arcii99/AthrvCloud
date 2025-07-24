//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_LENGTH 1024

int main() {
    char filename[MAX_FILE_LENGTH];
    printf("Enter filename to scan: ");
    fgets(filename, MAX_FILE_LENGTH, stdin);

    FILE *file_to_scan = fopen(filename, "rb");
    if (file_to_scan == NULL) {
        printf("Failed to open file %s for scanning.\n", filename);
        return 1;
    }

    char buffer[1024];
    int file_size = 0;
    while (!feof(file_to_scan)) {
        int bytes_read = fread(buffer, sizeof(char), 1024, file_to_scan);
        file_size += bytes_read;

        // Implement your virus scanning logic here.
        // This is a simple example that just looks for the string "virus".
        for (int i=0; i<bytes_read; i++) {
            if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r'
                && buffer[i+3] == 'u' && buffer[i+4] == 's') {
                printf("WARNING: File %s contains a virus!\n", filename);
                fclose(file_to_scan);
                return 0;
            }
        }
    }

    printf("Scanned file %s (%d bytes) and found no viruses.\n", filename, file_size);
    fclose(file_to_scan);
    return 0;
}