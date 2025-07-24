//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h> 

int main() { 

printf("Welcome to the C File Backup System!\n\n"); 

// Open the original file for reading 
FILE* orig = fopen("original.txt", "r"); 

// Open the backup file for writing 
FILE* backup = fopen("backup.txt", "w"); 

if (orig == NULL || backup == NULL) { 
    printf("Error: Cannot open file(s)!\n"); 
    return 1; 
} 

char c; 

// Copy characters from original file to backup file one by one 
while ((c = fgetc(orig)) != EOF) { 
    fputc(c, backup); 
} 

// Close both files 
fclose(orig); 
fclose(backup); 

printf("File backup completed successfully!\n"); 

return 0; 
}