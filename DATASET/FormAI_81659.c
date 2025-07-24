//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <dir>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *d;
    while ((d = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, 1023, "%s/%s", argv[1], d->d_name);

        struct stat info;
        if (stat(path, &info) == -1) {
            perror("stat");
            continue;
        }

        if (d->d_type == DT_DIR) {
            if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0) {
                continue;
            }
            printf("%s/\n", path);
            main(2, (char*[]) {"", path});
        } else {
            printf("%s - %ld bytes\n", path, info.st_size);
        }
    }

    closedir(dir);

    return 0;
}