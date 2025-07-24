//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX_BUF_SIZE 4096

int copy_file(char* src_file, char* dst_file);
int delete_folder(char* folder_name);
int delete_file(char* file_name);
int sync_files(char* src_folder, char* dst_folder);

int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s [source_folder] [destination_folder]\n", argv[0]);
        return -1;
    }
    int status = sync_files(argv[1], argv[2]);
    if(status == 0)
        printf("Files synchronized successfully!\n");
    else
        printf("Error occurred during synchronization!\n");
    return status;
}

int sync_files(char* src_folder, char* dst_folder){
    DIR* src_dir;
    DIR* dst_dir;
    int status = 0;

    if((src_dir = opendir(src_folder)) == NULL){
        printf("Error opening source folder!\n");
        return -1;
    }
    if((dst_dir = opendir(dst_folder)) == NULL){
        if(mkdir(dst_folder, 0777) == -1){
            printf("Error creating destination folder!\n");
            return -1;
        }
        else{
            printf("Destination folder created successfully!\n");
            dst_dir = opendir(dst_folder);
        }
    }
    struct dirent* src_entry;
    struct stat src_stat;
    char src_path[PATH_MAX + 1], dst_path[PATH_MAX + 1];

    while((src_entry = readdir(src_dir)) != NULL){
        if(strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0)
            continue;
        snprintf(src_path, PATH_MAX, "%s/%s", src_folder, src_entry->d_name);
        snprintf(dst_path, PATH_MAX, "%s/%s", dst_folder, src_entry->d_name);

        if(stat(src_path, &src_stat) == 0){
            if(S_ISREG(src_stat.st_mode)){
                struct stat dst_stat;
                if(stat(dst_path, &dst_stat) != 0 || (src_stat.st_mtime > dst_stat.st_mtime)){
                    printf("Copying file: %s -> %s\n", src_path, dst_path);
                    if(copy_file(src_path, dst_path) != 0){
                        printf("Error copying file: %s -> %s\n", src_path, dst_path);
                        status = -1;
                    }
                }
            }
            else if(S_ISDIR(src_stat.st_mode)){
                if(sync_files(src_path, dst_path) != 0){
                    printf("Error synchronizing directory: %s -> %s\n", src_path, dst_path);
                    status = -1;
                }
            }
        }
        else{
            printf("Error getting stat info: %s\n", src_path);
            status = -1;
        }
    }

    struct dirent* dst_entry;
    while((dst_entry = readdir(dst_dir)) != NULL){
        if(strcmp(dst_entry->d_name, ".") == 0 || strcmp(dst_entry->d_name, "..") == 0)
            continue;
        snprintf(dst_path, PATH_MAX, "%s/%s", dst_folder, dst_entry->d_name);
        if(stat(dst_path, &src_stat) == 0){
            if(S_ISREG(src_stat.st_mode)){
                if(access(src_path, F_OK) == -1){
                    printf("Deleting file: %s\n", dst_path);
                    if(delete_file(dst_path) != 0){
                        printf("Error deleting file: %s\n", dst_path);
                        status = -1;
                    }
                }
            }
            else if(S_ISDIR(src_stat.st_mode)){
                if(access(src_path, F_OK) == -1){
                    printf("Deleting folder: %s\n", dst_path);
                    if(delete_folder(dst_path) != 0){
                        printf("Error deleting folder: %s\n", dst_path);
                        status = -1;
                    }
                }
            }
        }
    }

    closedir(src_dir);
    closedir(dst_dir);
    return status;
}

int copy_file(char* src_file, char* dst_file){
    int src_fd, dst_fd, read_bytes, write_bytes;
    char buffer[MAX_BUF_SIZE];

    if((src_fd = open(src_file, O_RDONLY)) == -1)
        return -1;
    if((dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
        return -1;

    while((read_bytes = read(src_fd, buffer, MAX_BUF_SIZE)) > 0){
        write_bytes = write(dst_fd, buffer, read_bytes);
        if(write_bytes != read_bytes){
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }
    close(src_fd);
    close(dst_fd);
    return 0;
}

int delete_folder(char* folder_name){
    DIR* dir;
    struct dirent* entry;
    char path[PATH_MAX];

    if((dir = opendir(folder_name)) == NULL)
        return -1;

    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(path, PATH_MAX, "%s/%s", folder_name, entry->d_name);
        if(S_ISDIR(entry->d_type)){
            if(delete_folder(path) != 0){
                printf("Error deleting folder: %s\n", path);
                closedir(dir);
                return -1;
            }
        }
        else{
            if(delete_file(path) != 0){
                printf("Error deleting file: %s\n", path);
                closedir(dir);
                return -1;
            }
        }
    }
    closedir(dir);
    if(rmdir(folder_name) == -1)
        return -1;
    return 0;
}

int delete_file(char* file_name){
    if(remove(file_name) == -1)
        return -1;
    return 0;
}