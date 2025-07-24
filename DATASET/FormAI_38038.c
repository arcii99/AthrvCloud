//FormAI DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_file(char *filename);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    backup_file(argv[1]);
    
    printf("File backed up successfully!\n");
    
    return 0;
}

void backup_file(char *filename) {
    char backup_file[100];
    char command[200];
    
    sprintf(backup_file,"%s.bak", filename);
    sprintf(command,"cp %s %s", filename, backup_file);
    
    system(command);
}