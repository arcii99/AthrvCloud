//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Function to check if a string contains a virus signature
int checkVirusSignature(char* str) {
    
    // List of virus signatures to check against
    char* virusSignatures[] = { "worm", "trojan", "spyware", "ransomware", "malware" };
    
    int i;
    
    // Loop through all virus signatures and check if the string contains any of them
    for(i = 0; i < 5; i++) {
        if(strstr(str, virusSignatures[i]) != NULL) {
            return 1;
        }
    }
    
    return 0;
}

int main() {

    char filename[100];
    char line[256];
    int lineNumber = 1;
    
    // Prompt the user for the filename to scan
    printf("Enter the filename to scan: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;    // remove newline character
    
    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    
    // Check that the file was successfully opened
    if(fp == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }
    
    // Read each line of the file and check for virus signatures
    while(fgets(line, 256, fp)) {
        if(checkVirusSignature(line)) {
            printf("Virus detected on line %d: %s\n", lineNumber, line);
        }
        lineNumber++;
    }
    
    // Close the file
    fclose(fp);
    
    return 0;
}