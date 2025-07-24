//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void listFiles(char *path, int level) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (!dir) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            printf("%*s%s/\n", level*2, "", entry->d_name);
            char newPath[1024];
            snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);
            listFiles(newPath, level + 1);
        } else {
            printf("%*s%s\n", level*2, "", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    listFiles(argv[1], 0);

    return 0;
}