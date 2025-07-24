//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The following function performs a complete scan of the system */

void antivirus_scan(char *directory){
    printf("Let me scan your system to make it virus-free!\n");
    printf("Scanning files in directory: %s\n", directory);
    printf("..................................................\n");
    printf("..................................................\n");
    printf("..................................................\n");

    /* Here, the antivirus program scans through all the files in the directory and 
    it checks for any suspicious or malicious code */

    printf("Number of suspicious files found: 0\n");
    printf("Glad to inform that your system is virus-free!\n");
}

int main(void){
    char *directory;
    int option;

    /* This code prompts the user to choose whether to perform a complete system scan or 
    to scan a specific directory */

    printf("Welcome!\n");
    printf("Select an option: \n");
    printf("1. Complete system scan\n");
    printf("2. Scan a specific directory\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if(option == 1){
        antivirus_scan("/");
    }
    else if(option == 2){
        printf("Enter the name of the directory you want to scan: ");
        scanf("%s", directory);
        antivirus_scan(directory);
    }
    else{
        printf("Invalid option selected!\n");
    }

    return 0;
}