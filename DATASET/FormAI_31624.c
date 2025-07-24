//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 512 // Define maximum file size for scanning

int scan_file(char *file_path); // Function to scan a file and return any malicious strings

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please specify the path of the file to scan\n");
        return 0;
    }

    char *file_path = argv[1];
    int status = scan_file(file_path);

    if (status == 1) {
        printf("The file %s is infected with a virus\n", file_path);
    } else {
        printf("The file %s is clean\n", file_path);
    }

    return 0;
}

int scan_file(char *file_path) {
    char buffer[MAX_FILE_SIZE]; // Create buffer for storing file contents
    FILE *file = fopen(file_path, "r"); // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while(fgets(buffer, MAX_FILE_SIZE, file) != NULL) { // Loop through each line of the file
        if (strstr(buffer, "malware") != NULL) { // Check for any occurrence of malicious string
            return 1; // Return positive status for infected file
        }
    }

    fclose(file); // Close the file
    return 0; // Return negative status for clean file
}