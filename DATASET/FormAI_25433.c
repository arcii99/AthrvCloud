//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void analyze_disk_space(char* path, int level, int* total_size) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        char new_path[1024];
        snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) { // Recursive call for subdirectories
            printf("%*s%s/\n", level*4, "", entry->d_name);
            analyze_disk_space(new_path, level + 1, total_size);
        } else { // Print file size and add to total
            FILE* file = fopen(new_path, "rb");
            if (file) {
                fseek(file, 0L, SEEK_END);
                int file_size = ftell(file);
                printf("%*s%s (%d bytes)\n", level*4, "", entry->d_name, file_size);
                *total_size += file_size;
                fclose(file);
            }
        }
    }
    closedir(dir);
}

int main() {
    int total_size = 0;
    printf("Analyzing disk space...\n");
    analyze_disk_space(".", 0, &total_size);
    printf("Total disk space used: %d bytes\n", total_size);
    return 0;
}