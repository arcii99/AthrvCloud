//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void process_directory(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        sprintf(path, "%s/%s", dirname, entry->d_name);

        if (entry->d_type == DT_DIR) {
            process_directory(path);
        } else {
            // Do something with this file
            printf("%s\n", path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }

    process_directory(argv[1]);

    return 0;
}