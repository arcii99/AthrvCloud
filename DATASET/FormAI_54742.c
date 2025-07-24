//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define GIGABYTE (1024 * 1024 * 1024)

void analyze(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Cannot open directory.\n");
        return;
    }
    struct dirent *ptr;
    while ((ptr = readdir(dir)) != NULL) {
        if (ptr->d_type == DT_DIR && ptr->d_name[0] != '.') {
            char new_path[100];
            sprintf(new_path, "%s/%s", path, ptr->d_name);
            analyze(new_path);
        }
        else if (ptr->d_type == DT_REG) {
            char full_path[200];
            sprintf(full_path, "%s/%s", path, ptr->d_name);
            struct statvfs stat;
            if (statvfs(full_path, &stat) != -1) {
                double free_space = (double) (stat.f_bsize * stat.f_bfree) / GIGABYTE;
                printf("%s - %.2f GB free\n", full_path, free_space);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./disk_analyzer <path>\n");
        return 1;
    }
    char *path = argv[1];
    analyze(path);
    return 0;
}