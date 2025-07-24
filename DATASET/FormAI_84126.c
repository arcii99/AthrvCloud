//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void analyze_directory(char *path, int tab_count);
int print_tabs(int tab_count);

int main(int argc, char *argv[])
{
    char path[1024];
    if (argc == 2) {
        strncpy(path, argv[1], sizeof(path) - 1);
        path[sizeof(path) - 1] = '\0';
    } else {
        strncpy(path, ".", sizeof(path) - 1);
        path[sizeof(path) - 1] = '\0';
    }
    printf("%s\n", path);
    analyze_directory(path, 1);
    return 0;
}

void analyze_directory(char *path, int tab_count)
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    if (!(dir = opendir(path)))
        return;

    print_tabs(tab_count);
    printf("{\n");

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.')
            continue;

        char new_path[1024];
        snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

        if (lstat(new_path, &st) == -1)
            continue;

        if (S_ISDIR(st.st_mode)) {
            print_tabs(tab_count);
            printf("%s/\n", entry->d_name);
            analyze_directory(new_path, tab_count + 1);
        } else if (S_ISREG(st.st_mode)) {
            print_tabs(tab_count);
            printf("%s (%d bytes)\n", entry->d_name, (int)st.st_size);
        } else {
            print_tabs(tab_count);
            printf("%s (unknown file type)\n", entry->d_name);
        }
    }

    print_tabs(tab_count);
    printf("}\n");

    closedir(dir);
}

int print_tabs(int tab_count)
{
    int i;
    for (i = 0; i < tab_count; i++)
        putchar('\t');
    return i;
}