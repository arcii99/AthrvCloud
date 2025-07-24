//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to C Antivirus Scanner!\n\n");
    char fileName[100];
    printf("Enter the name of the file to be scanned: ");
    fgets(fileName, 100, stdin);
    
    char virusStrings[4][20] = {"malware", "trojan", "worm", "virus"};
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("\nSorry, the file \"%s\" does not exist.\n", fileName);
    } else {
        printf("\nScanning file for viruses...\n");
        char fileLine[200];
        int virusFound = 0;
        while (fgets(fileLine, 200, fptr)) {
            for (int i = 0; i < 4; i++) {
                if (strstr(fileLine, virusStrings[i])) {
                    virusFound = 1;
                    printf("\nWARNING: Virus detected! \"%s\" found in file.\n", virusStrings[i]);
                    break;
                }
            }
        }
        if (!virusFound) {
            printf("\nThe file \"%s\" has no viruses.\n", fileName);
        }
        fclose(fptr);
    }
    printf("\nThank you for using C Antivirus Scanner!\n");
    
    return 0;
}