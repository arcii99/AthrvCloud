//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 1048576 // 1 MB

struct file {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
};

void backup(struct file file_data) {
    FILE *fptr;
    char new_filename[MAX_FILENAME_LENGTH + 10]; // add 10 to account for backup suffix
    
    sprintf(new_filename, "%s_BACKUP", file_data.filename);
    
    fptr = fopen(new_filename, "w");
    
    if (fptr != NULL) {
        size_t num_bytes_written = fwrite(file_data.data, 1, strlen(file_data.data), fptr);
        
        if (num_bytes_written == strlen(file_data.data)) {
            printf("Backup of %s successful.\n", file_data.filename);
        } else {
            printf("Backup of %s failed.\n", file_data.filename);
        }
        
        fclose(fptr);
    } else {
        printf("Error opening backup file.\n");
    }
}

int main() {
    struct file my_file;
    
    strcpy(my_file.filename, "my_file.txt");
    strcpy(my_file.data, "Hello, world!");
    
    backup(my_file);
    
    return 0;
}