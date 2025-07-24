//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int isVirus(char *filename) {
    /* Here you can implement virus detection logic using various techniques */
    return 0;
}

void scanDirectory(char *filename) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(filename); /* open directory */
    if (dir == NULL) { /* open failed */
        perror("opendir");
        return;
    }
    while ((entry = readdir(dir)) != NULL) { /* read all files in directory */
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", filename, entry->d_name);
        if (entry->d_type == DT_DIR) { /* if it is a directory */
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            scanDirectory(path); /* scan directory recursively */
        } else { /* if it is a file */
            if (isVirus(path)) { /* check if it is a virus */
                printf("%s is a virus\n", path);
            }
        }
    }
    closedir(dir); /* close directory */
}

int main(int argc, char *argv[]) {
    if (argc < 2) { /* check if directory to scan is provided */
        printf("Usage: %s <directory-to-scan>\n", argv[0]);
        return -1;
    }
    scanDirectory(argv[1]); /* scan directory */
    printf("Scan complete!\n");
    return 0;
}