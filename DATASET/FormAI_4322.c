//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <openssl/md5.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_SYNC_FILES 50

typedef struct {
    char file_path[BUFFER_SIZE];
    char file_md5[BUFFER_SIZE];
} sync_file;

typedef struct {
    sync_file files[MAX_SYNC_FILES];
    int num_files;
} sync_files_list;

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void print_success(const char *msg) {
    fprintf(stdout, "%s\n", msg);
}

void hash_file_md5(const char *file_path, char *file_md5) {
    FILE *fp = fopen(file_path, "rb");
    MD5_CTX mdContext;
    unsigned char data[1024];

    if (fp == NULL) {
        print_error("Failed to open the file!");
    }

    MD5_Init(&mdContext);
    int bytes;
    while ((bytes = fread(data, 1, BUFFER_SIZE, fp)) != 0) {
        MD5_Update(&mdContext, data, bytes);
    }
    MD5_Final((unsigned char *) file_md5, &mdContext);

    fclose(fp);
}

int file_exists(const char *file_path) {
    return access(file_path, F_OK) == 0;
}

void sync_files(const char *source_dir_path, const char *target_dir_path) {
    DIR *source_dir = opendir(source_dir_path);
    DIR *target_dir = opendir(target_dir_path);

    if (!source_dir || !target_dir) {
        print_error("Failed to open directories!");
    }

    sync_files_list sync_list;
    sync_list.num_files = 0;

    struct dirent *source_file;
    while ((source_file = readdir(source_dir))) {
        if (source_file->d_type == DT_REG) {
            char source_file_path[BUFFER_SIZE];
            snprintf(source_file_path, sizeof(source_file_path), "%s/%s", source_dir_path, source_file->d_name);

            char source_file_md5[BUFFER_SIZE];
            hash_file_md5(source_file_path, source_file_md5);

            int i;
            for (i = 0; i < sync_list.num_files; i++) {
                if (strcmp(sync_list.files[i].file_path, source_file_path) == 0 &&
                    strcmp(sync_list.files[i].file_md5, source_file_md5) != 0) {
                    print_error("File already exists, but MD5 mismatch!");
                }
            }

            sync_file *new_file = &sync_list.files[sync_list.num_files];
            strncpy(new_file->file_path, source_file_path, BUFFER_SIZE);
            strncpy(new_file->file_md5, source_file_md5, BUFFER_SIZE);
            sync_list.num_files++;
        }
    }

    struct dirent *target_file;
    while ((target_file = readdir(target_dir))) {
        if (target_file->d_type == DT_REG) {
            char target_file_path[BUFFER_SIZE];
            snprintf(target_file_path, sizeof(target_file_path), "%s/%s", target_dir_path, target_file->d_name);

            char target_file_md5[BUFFER_SIZE];
            hash_file_md5(target_file_path, target_file_md5);

            int i;
            int found = 0;
            for (i = 0; i < sync_list.num_files; i++) {
                if (strcmp(sync_list.files[i].file_path, target_file_path) == 0) {
                    found = 1;
                    if (strcmp(sync_list.files[i].file_md5, target_file_md5) == 0) {
                        break;
                    } else {
                        print_error("File already exists, but MD5 mismatch!");
                    }
                }
            }

            if (!found) {
                char cmd[BUFFER_SIZE * 2];
                snprintf(cmd, sizeof(cmd), "cp %s %s", target_file_path, source_dir_path);
                system(cmd);
            }
        }
    }

    closedir(source_dir);
    closedir(target_dir);

    int i;
    for (i = 0; i < sync_list.num_files; i++) {
        if (!file_exists(sync_list.files[i].file_path)) {
            char cmd[BUFFER_SIZE * 2];
            snprintf(cmd, sizeof(cmd), "cp %s %s", sync_list.files[i].file_path, target_dir_path);
            system(cmd);
        }
    }

    print_success("Synchronization successful!");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_error("Usage: paranoid_sync <source directory> <target directory>");
    }

    char *source_dir_path = argv[1];
    char *target_dir_path = argv[2];

    sync_files(source_dir_path, target_dir_path);

    return 0;
}