//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_file(char* filename) {
    FILE* file = fopen(filename, "r");
    char c;
    while ((c = getc(file)) != EOF) {
        if (c == 'v' || c == 'i' || c == 'r' || c == 'u' || c == 's') {
            printf("Warning: %s has been infected with a virus!\n", filename);
            return;
        }
    }
    printf("File %s is clean!\n", filename);
}

void scan_directory(char* directory) {
    DIR* dir = opendir(directory);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // regular file
            char filename[1024];
            sprintf(filename, "%s/%s", directory, entry->d_name);
            scan_file(filename);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // directory
            char subdirectory[1024];
            sprintf(subdirectory, "%s/%s", directory, entry->d_name);
            scan_directory(subdirectory);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }
    scan_directory(argv[1]);
    printf("Scan complete!\n");
    return 0;
}