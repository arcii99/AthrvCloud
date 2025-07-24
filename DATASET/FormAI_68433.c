//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void list_dir(const char *path, int indent)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        struct stat statbuf;
        if (stat(entry->d_name, &statbuf) == -1) {
            printf("Error statting file %s\n", entry->d_name);
            continue;
        }
        int j;
        for (j = 0; j < indent; j++) {
            printf(" ");
        }
        printf("%d %s\n", statbuf.st_size, entry->d_name);
        if (S_ISDIR(statbuf.st_mode)) {
            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
            list_dir(new_path, indent + 4);
        }
    }
    closedir(dir);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    list_dir(argv[1], 0);
    return 0;
}