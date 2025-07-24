//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Function to calculate directory size
long int calculate_directory_size(char *path){
    long int total_size = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char *file_path = malloc(256 * sizeof(char));
                sprintf(file_path, "%s/%s", path, ent->d_name);
                if (ent->d_type == DT_DIR) {
                    total_size += calculate_directory_size(file_path);
                } else {
                    FILE *file = fopen(file_path, "rb");
                    if (file) {
                        fseek(file, 0, SEEK_END);
                        long int size = ftell(file);
                        fclose(file);
                        total_size += size;
                    }
                }
                free(file_path);
            }
        }
        closedir(dir);
    }
    return total_size;
}

int main(){
    char path[256];
    printf("Enter the directory path: ");
    scanf("%s", path);
    long int size_in_bytes = calculate_directory_size(path);
    float size_in_megabytes = ((float)size_in_bytes) / (1024 * 1024);
    printf("Directory size: %.2f MB\n", size_in_megabytes);
    return 0;
}