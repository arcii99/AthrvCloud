//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

struct file_data {
    char name[MAX_PATH];
    struct stat st;
};

int compare_files(struct file_data* f1, struct file_data* f2) {
    if (strcmp(f1->name, f2->name) != 0) {
        return 0;
    }
    if (f1->st.st_size != f2->st.st_size) {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    DIR* dir1 = opendir(argv[1]);
    DIR* dir2 = opendir(argv[2]);

    struct file_data files1[MAX_FILES];
    struct file_data files2[MAX_FILES];
    int file_count1 = 0;
    int file_count2 = 0;

    if (dir1 == NULL) {
        printf("Unable to open directory %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    if (dir2 == NULL) {
        printf("Unable to open directory %s: %s\n", argv[2], strerror(errno));
        return 1;
    }

    struct dirent* ent;
    while ((ent = readdir(dir1)) != NULL && file_count1 < MAX_FILES) {
        if (ent->d_name[0] == '.') {
            continue;
        }
        char path[MAX_PATH];
        snprintf(path, MAX_PATH, "%s/%s", argv[1], ent->d_name);
        if (stat(path, &files1[file_count1].st) == 0) {
            strncpy(files1[file_count1].name, ent->d_name, MAX_PATH);
            file_count1++;
        }
    }

    while ((ent = readdir(dir2)) != NULL && file_count2 < MAX_FILES) {
        if (ent->d_name[0] == '.') {
            continue;
        }
        char path[MAX_PATH];
        snprintf(path, MAX_PATH, "%s/%s", argv[2], ent->d_name);
        if (stat(path, &files2[file_count2].st) == 0) {
            strncpy(files2[file_count2].name, ent->d_name, MAX_PATH);
            file_count2++;
        }
    }

    printf("Found %d files in directory %s\n", file_count1, argv[1]);
    printf("Found %d files in directory %s\n", file_count2, argv[2]);

    // Find files that are in dir1 but not in dir2
    for (int i = 0; i < file_count1; i++) {
        int found = 0;
        for (int j = 0; j < file_count2; j++) {
            if (compare_files(&files1[i], &files2[j])) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s only exists in %s\n", files1[i].name, argv[1]);
        }
    }

    // Find files that are in dir2 but not in dir1
    for (int i = 0; i < file_count2; i++) {
        int found = 0;
        for (int j = 0; j < file_count1; j++) {
            if (compare_files(&files2[i], &files1[j])) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s only exists in %s\n", files2[i].name, argv[2]);
        }
    }

    // Find files that are in both dirs but are different
    for (int i = 0; i < file_count1; i++) {
        for (int j = 0; j < file_count2; j++) {
            if (compare_files(&files1[i], &files2[j])) {
                if (files1[i].st.st_mtime > files2[j].st.st_mtime) {
                    printf("%s is newer in %s\n", files1[i].name, argv[1]);
                } else if (files1[i].st.st_mtime < files2[j].st.st_mtime) {
                    printf("%s is newer in %s\n", files1[i].name, argv[2]);
                } else {
                    printf("%s is the same in both directories\n", files1[i].name);
                }
            }
        }
    }

    closedir(dir1);
    closedir(dir2);

    return 0;
}