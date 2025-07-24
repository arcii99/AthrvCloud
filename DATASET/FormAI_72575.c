//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char virus_database[10][10] = {"virus1", "virus2", "virus3", "virus4", "virus5", "virus6", "virus7", "virus8", "virus9", "virus10"};

void scan_file(char* filename) {
    
    FILE* fileptr;
    char buffer[100];
    int i, j, found;
    
    fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    
    while(fgets(buffer, 100, fileptr) != NULL) {
        for (i=0; i<10; i++) {
            found = 1;
            for (j=0; j<strlen(virus_database[i]); j++) {
                if (buffer[j] != virus_database[i][j]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                printf("Virus found in file: %s\n", filename);
                return;
            }
        }
    }
    
    printf("No virus found in file: %s\n", filename);
    
    fclose(fileptr);
}

int main() {
    
    char filename[30];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);
    
    scan_file(filename);
    
    return 0;
}