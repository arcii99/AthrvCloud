//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct file_data {
    char file_name[100];
    char file_path[200];
    int file_size;
    time_t last_modified;
} FileData;

int main() {
    // Create arrays to hold file names, paths, and sizes
    char file_names[10][100] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};
    char file_paths[10][200] = {"C:\\Files\\file1.txt", "C:\\Files\\file2.txt", "C:\\Files\\file3.txt", "C:\\Files\\file4.txt", "C:\\Files\\file5.txt", "C:\\Files\\file6.txt", "C:\\Files\\file7.txt", "C:\\Files\\file8.txt", "C:\\Files\\file9.txt", "C:\\Files\\file10.txt"};
    int file_sizes[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    // Create an array of FileData structs to hold file information
    FileData files[10];

    // Fill in the file information for each file
    for (int i = 0; i < 10; i++) {
        strcpy(files[i].file_name, file_names[i]);
        strcpy(files[i].file_path, file_paths[i]);
        files[i].file_size = file_sizes[i];
        files[i].last_modified = time(NULL);
    }

    // Open the backup file for writing
    FILE *backup_file;
    backup_file = fopen("C:\\Backups\\backup.txt", "w");

    // Write the file information to the backup file
    for (int i = 0; i < 10; i++) {
        fprintf(backup_file, "%s,%s,%d,%ld\n", files[i].file_name, files[i].file_path, files[i].file_size, files[i].last_modified);
    }

    // Close the backup file
    fclose(backup_file);

    return 0;
}