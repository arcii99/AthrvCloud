//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 260

void synchronize(char* source_folder, char* destination_folder);
void synchronize_folder(char* source_folder, char* destination_folder);
void synchronize_file(char* source_file, char* destination_file);

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: %s source_folder destination_folder\n", argv[0]);
        return 1;
    }

    synchronize(argv[1], argv[2]);
    return 0;
}

void synchronize(char* source_folder, char* destination_folder) {
    synchronize_folder(source_folder, destination_folder);
}

void synchronize_folder(char* source_folder, char* destination_folder) {
    DIR* source_dir = opendir(source_folder);
    if(source_dir == NULL) {
        return;
    }

    DIR* destination_dir = opendir(destination_folder);
    if(destination_dir == NULL) {
        mkdir(destination_folder, S_IRWXU);
        destination_dir = opendir(destination_folder);
    }

    struct dirent* dirent;
    while((dirent = readdir(source_dir)) != NULL) {
        char source_path[MAX_PATH];
        sprintf(source_path, "%s/%s", source_folder, dirent->d_name);

        char destination_path[MAX_PATH];
        sprintf(destination_path, "%s/%s", destination_folder, dirent->d_name);

        if(strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        struct stat source_stat;
        stat(source_path, &source_stat);

        if(dirent->d_type == DT_DIR) {
            synchronize_folder(source_path, destination_path);
        }
        else if(dirent->d_type == DT_REG) {
            synchronize_file(source_path, destination_path);
        }
    }

    closedir(source_dir);
    closedir(destination_dir);
}

void synchronize_file(char* source_file, char* destination_file) {
    struct stat source_stat;
    stat(source_file, &source_stat);

    struct stat destination_stat;
    if(stat(destination_file, &destination_stat) == 0) {
        if(source_stat.st_mtime > destination_stat.st_mtime) {
            copy_file(source_file, destination_file);
        }
    }
    else {
        copy_file(source_file, destination_file);
    }
}

void copy_file(char* source_file, char* destination_file) {
    FILE* source = fopen(source_file, "rb");
    FILE* destination = fopen(destination_file, "wb");

    char buffer[1024];
    size_t size;

    while((size = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, size, destination);
    }

    fclose(source);
    fclose(destination);
}