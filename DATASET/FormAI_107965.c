//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int printTree(char *name, int depth) {
    DIR *dir = opendir(name);
    struct dirent *entry;
    struct stat info;
    int totalSize = 0;

    if (!dir) {
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", depth * 2, "", entry->d_name);
            totalSize += printTree(path, depth + 1);
        } else {
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            stat(path, &info);
            printf("%*s- %s (%ld bytes)\n", depth * 2, "", entry->d_name, info.st_size);
            totalSize += info.st_size;
        }
    }

    closedir(dir);

    return totalSize;
}

int main(int argc, char **argv) {
    char *root = argv[1];
    printf("Scanning %s...\n", root);
    int totalSize = printTree(root, 0);
    printf("Done. Total size of %s is %d bytes.\n", root, totalSize);
    return 0;
}