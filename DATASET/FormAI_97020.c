//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_to_scan[50];
    printf("Welcome to the C Antivirus scanner!\n");
    printf("Please enter the file name to be scanned: ");
    scanf("%s", file_to_scan);  
    printf("Scanning file: %s\n", file_to_scan);

    // check for viruses 
    char* viruses[] = {"malware", "trojan", "worm", "spyware", "adware"};
    int num_viruses = sizeof(viruses) / sizeof(viruses[0]);
    for (int i=0; i<num_viruses; i++) {
        if (strstr(file_to_scan, viruses[i])) {
            printf("Virus detected: %s\n", viruses[i]);
            printf("Deleting infected file...\n");
            remove(file_to_scan);
            printf("File deleted. Your system is now safe.\n");
            return 0; // exit program on virus detection
        }
    }

    printf("No viruses detected. Your system is safe.\n");
    return 0;
}