//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

void listdir(char *path, int depth)
{
    struct dirent *ent;
    DIR *dir;

    if ((dir = opendir(path)) != NULL) {
        printf("%*s[%s]\n", depth*2, "", path);
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                    continue;
                }
                char newPath[MAX_PATH];
                snprintf(newPath, sizeof(newPath), "%s/%s", path, ent->d_name);
                listdir(newPath, depth+1);
            } else {
                printf("%*s- %s\n", depth*2, "", ent->d_name);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv)
{
    char *path;

    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    path = argv[1];

    printf("System Process Viewer\n");
    listdir(path, 0);
    printf("Done.\n");

    return 0;
}