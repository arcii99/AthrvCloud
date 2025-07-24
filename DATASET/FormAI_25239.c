//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to recursively traverse directories
void traverse(char *path) {
    struct dirent *file;
    DIR *directory = opendir(path);
    if (directory == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }
    while ((file = readdir(directory)) != NULL) {
        if (file->d_type == DT_DIR) {
            char newPath[1024];
            if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {
                continue;
            }
            snprintf(newPath, sizeof(newPath), "%s/%s", path, file->d_name);
            traverse(newPath);  // Recursively traverse directory
        } else {
            char filePath[1024];
            snprintf(filePath, sizeof(filePath), "%s/%s", path, file->d_name);
            struct stat st;
            stat(filePath, &st);
            printf("%ld files\t%ld bytes\t%s\n", st.st_blocks, st.st_size, filePath);
        }
    }
    closedir(directory);
}

// Main function
int main() {
    char path[1024];
    printf("Enter path to analyze: ");
    scanf("%s", path);
    traverse(path);
    return 0;
}