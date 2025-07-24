//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILESIZE 1024

// Global variables for the virus signature and scanner results
char virusSignature[] = "e79a3ad364b7d152ba3d725f035c6273"; // MD5 of virus signature
char scannerResults[MAX_FILESIZE];

// Function to scan a file
void scanFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("%s not found!\n", filename);
        return;
    }

    // Read the file contents
    char fileContents[MAX_FILESIZE];
    fread(fileContents, 1, MAX_FILESIZE, file);

    // Calculate the MD5 hash of the file contents
    unsigned char md5Result[16];
    MD5(fileContents, strlen(fileContents), md5Result);

    // Convert the MD5 hash into a string
    char md5String[33];
    for (int i = 0; i < 16; i++) {
        sprintf(&md5String[i*2], "%02x", (unsigned int) md5Result[i]);
    }

    // Check if the file contains the virus signature
    if (strcmp(md5String, virusSignature) == 0) {
        sprintf(scannerResults, "%s contains the virus signature!\n", filename);
    }
    else {
        sprintf(scannerResults, "%s is clean.\n", filename);
    }

    fclose(file);
}

// Main function
int main() {
    char* filesToScan[] = {"file1.txt", "file2.txt", "file3.txt"}; // List of files to scan

    // Scan each file
    for (int i = 0; i < 3; i++) {
        scanFile(filesToScan[i]);
        printf("%s", scannerResults);
    }

    return 0;
}