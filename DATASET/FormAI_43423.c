//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to search for virus signatures in a file
void scan_file(char *filename)
{
    FILE *file;
    char signature[] = "virus"; // sample virus signature
    char buffer[1000];
    int i = 0, j = 0;

    // attempt to open the file
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("%s could not be opened.\n", filename);
        exit(1);
    }

    // read the file in chunks of 1000 bytes
    while (fread(buffer, sizeof(char), sizeof(buffer), file) > 0) {
        for (i = 0; i < sizeof(buffer); i++) {
            // check if a signature byte matches
            if (buffer[i] == signature[j]) {
                j++;
                // check if all signature bytes have been matched
                if (j == strlen(signature)) {
                    printf("Virus signature found in %s.\n", filename);
                    fclose(file);
                    return; // virus found, stop scanning
                }
            }
            else {
                j = 0; // reset signature index
            }
        }
    }

    printf("No virus signature found in %s.\n", filename);
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2) { // only one argument allowed - the file to scan
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    printf("Scanning %s...\n", filename);
    scan_file(filename);

    return 0;
}