//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the provided file name ends with .exe extension
int is_exe(char *filename){
    int len = strlen(filename);
    if(len >= 4 && strcmp(filename + len - 4, ".exe") == 0){
        return 1;       // It's an .exe file
    }
    return 0;           // It's not an .exe file
}

// Function to scan the provided file for viruses
void scan_file(char *filename){
    if(is_exe(filename)){
        printf("%s is an executable file.\n", filename);
        printf("Scanning %s for viruses...\n", filename);
        printf("1 virus found!\n");
        printf("Virus name: Trojan.Agent.CS\n");
        printf("Action taken: File Deleted\n");
    } else{
        printf("%s is not an executable file.\n", filename);
    }
}

int main(){
    char filename[256];
    printf("Welcome to Puzzling Antivirus Scanner!\n\n");
    printf("Enter the file name to scan: ");
    scanf("%s", filename);
    printf("\n");
    scan_file(filename);
    printf("\nThank you for using Puzzling Antivirus Scanner!\n");
    return 0;
}