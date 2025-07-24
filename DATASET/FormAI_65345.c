//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *directory;
    struct dirent *entry;
    char *task_dir = "/proc";
    char task_path[PATH_MAX];
    FILE *fp;
    
    directory = opendir(task_dir);
    if (directory == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            snprintf(task_path, PATH_MAX, "%s/%s/stat", task_dir, entry->d_name);
            fp = fopen(task_path, "r");
            if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            
            char name[20];
            int pid;
            
            fscanf(fp, "%d (%[^)])", &pid, name);
            printf("%d:%s\n", pid, name);
            
            fclose(fp);
        }
    }

    closedir(directory);
    return 0;
}