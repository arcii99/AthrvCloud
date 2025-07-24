//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The following function scans files for viruses */
void scan_file(char* path_to_file) {
    FILE* file_to_scan = fopen(path_to_file, "r");
    char buffer[512];
    int is_virus_found = 0; // set to true if virus is detected
    while(fgets(buffer, 512, file_to_scan)) {
        if(strstr(buffer, "DELETE_SYSTEM")) {
            is_virus_found = 1;
            break; // we found the virus!
        }
    }

    if(is_virus_found) {
        printf("Oh no! The deadly virus DELETE_SYSTEM has been found and neutralized.\n");
    } else {
        printf("Great news! The file has been scanned and is free of any viruses.\n");
    }
}

/* Our hero, the antivirus program, is called to action */
int main() {
    printf("Welcome to the C Antivirus scanner!\n");
    printf("Please enter the path to the file you would like to scan, or type quit to exit:\n");

    /* The user inputs the file path to be scanned */
    char file_path[256];
    while(1) {
        scanf("%s", file_path);
        if(!strcmp(file_path, "quit")) {
            printf("Thank you for using the C Antivirus scanner. Goodbye!\n");
            return 0;
        }

        /* The antivirus program gets to work */
        scan_file(file_path);
        printf("Please enter the path to the file you would like to scan, or type quit to exit:\n");
    }
}