//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<errno.h>
#include<pthread.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_SIZE 1048576

#define THREAD_COUNT 10

typedef struct _FileInfo {
    char path[MAX_PATH_LENGTH];
    int is_dir;
} FileInfo;

typedef struct _DiffSet {
    FileInfo* files;
    int count;
} DiffSet;

typedef struct _ThreadArgs {
    DiffSet* diff;
    char* source;
    char* destination;
} ThreadArgs;

void log_error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

int is_directory(char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

int is_regular_file(char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return S_ISREG(statbuf.st_mode);
}

int create_directory(char* path, mode_t mode) {
    if (mkdir(path, mode) == -1) {
        if (errno != EEXIST) {
            return 0;
        }
    }
    return 1;
}

int remove_directory(char* path) {
    DIR* dir = opendir(path);
    if (dir != NULL) {
        struct dirent* entry;
        while ((entry = readdir(dir))) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char child_path[MAX_PATH_LENGTH];
            sprintf(child_path, "%s/%s", path, entry->d_name);
            if (is_directory(child_path)) {
                remove_directory(child_path);
            } else {
                if (remove(child_path) != 0) {
                    closedir(dir);
                    return 0;
                }
            }
        }
        closedir(dir);
    } else {
        return 0;
    }
    if (rmdir(path) != 0) {
        return 0;
    }
    return 1;
}

char** list_directory(char* path) {
    DIR* dir = opendir(path);
    if (dir != NULL) {
        int item_count = 0;
        char** items = malloc(sizeof(char*) * 1024);
        struct dirent* entry;
        while ((entry = readdir(dir))) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            items[item_count] = malloc(strlen(entry->d_name) + 1);
            strcpy(items[item_count], entry->d_name);
            item_count++;
        }
        closedir(dir);
        items[item_count] = NULL;
        return items;
    } else {
        return NULL;
    }
}

void free_list_directory(char** items) {
    if (items != NULL) {
        int i = 0;
        while (items[i] != NULL) {
            free(items[i]);
            i++;
        }
        free(items);
    }
}

FileInfo* list_directory_info(char* path, int* count) {
    DIR* dir = opendir(path);
    if (dir != NULL) {
        int item_count = 0;
        FileInfo* file_infos = malloc(sizeof(FileInfo) * 1024);
        struct dirent* entry;
        while ((entry = readdir(dir))) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char child_path[MAX_PATH_LENGTH];
            sprintf(child_path, "%s/%s", path, entry->d_name);
            FileInfo file_info = {0};
            strcpy(file_info.path, child_path);
            file_info.is_dir = is_directory(child_path);
            file_infos[item_count] = file_info;
            item_count++;
        }
        closedir(dir);
        *count = item_count;
        return file_infos;
    } else {
        return NULL;
    }
}

void free_list_directory_info(FileInfo* items) {
    if (items != NULL) {
        free(items);
    }
}

void add_file_to_diff(DiffSet* diff, FileInfo file) {
    diff->files[diff->count] = file;
    diff->count++;
}

DiffSet* diff_directories(char* source_path, char* destination_path) {
    DiffSet* diff = malloc(sizeof(DiffSet));
    diff->files = malloc(sizeof(FileInfo) * 1024);
    diff->count = 0;
    int source_count;
    FileInfo* source_files = list_directory_info(source_path, &source_count);
    int destination_count;
    FileInfo* destination_files = list_directory_info(destination_path, &destination_count);
    for (int i = 0; i < source_count; i++) {
        char* source_filename = strrchr(source_files[i].path, '/') + 1;
        int matched = 0;
        int j;
        for (j = 0; j < destination_count; j++) {
            char* destination_filename = strrchr(destination_files[j].path, '/') + 1;
            if (strcmp(source_filename, destination_filename) == 0) {
                matched = 1;
                break;
            }
        }
        if (matched) {
            if (source_files[i].is_dir) {
                if (destination_files[j].is_dir) {
                    DiffSet* subdiff = diff_directories(source_files[i].path, destination_files[j].path);
                    for (int k = 0; k < subdiff->count; k++) {
                        add_file_to_diff(diff, subdiff->files[k]);
                    }
                    free(subdiff->files);
                    free(subdiff);
                } else {
                    add_file_to_diff(diff, source_files[i]);
                }
            } else {
                if (!destination_files[j].is_dir) {
                    FILE* source_file = fopen(source_files[i].path, "rb");
                    FILE* destination_file = fopen(destination_files[j].path, "rb");
                    if (source_file == NULL || destination_file == NULL) {
                        log_error("Failed to open file for diffing");
                        continue;
                    }
                    char source_buffer[MAX_FILE_SIZE];
                    char destination_buffer[MAX_FILE_SIZE];
                    size_t source_read = 0;
                    size_t destination_read = 0;
                    int different = 0;
                    do {
                        source_read = fread(source_buffer, sizeof(char), MAX_FILE_SIZE, source_file);
                        destination_read = fread(destination_buffer, sizeof(char), MAX_FILE_SIZE, destination_file);
                        if (source_read != destination_read || memcmp(source_buffer, destination_buffer, source_read) != 0) {
                            different = 1;
                            break;
                        }
                    } while (source_read > 0 && destination_read >0);
                    fclose(destination_file);
                    fclose(source_file);
                    if (different) {
                        add_file_to_diff(diff, source_files[i]);
                    }
                } else {
                    add_file_to_diff(diff, source_files[i]);
                }
            }
        } else {
            add_file_to_diff(diff, source_files[i]);
        }
    }
    free_list_directory_info(source_files);
    free_list_directory_info(destination_files);
    return diff;
}

void* sync_files(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;
    for (int i = 0; i < thread_args->diff->count; i++) {
        char* filename = strrchr(thread_args->diff->files[i].path, '/') + 1;
        char source_path[MAX_PATH_LENGTH];
        char destination_path[MAX_PATH_LENGTH];
        sprintf(source_path, "%s/%s", thread_args->source, thread_args->diff->files[i].path + strlen(thread_args->source) + 1);
        sprintf(destination_path, "%s/%s", thread_args->destination, thread_args->diff->files[i].path + strlen(thread_args->source) + 1);
        if (thread_args->diff->files[i].is_dir) {
            create_directory(destination_path, 0777);
        } else {
            create_directory(destination_path, 0777);
            FILE* source_file = fopen(source_path, "rb");
            FILE* destination_file = fopen(destination_path, "wb");
            if (source_file == NULL || destination_file == NULL) {
                log_error("Failed to open file for syncing");
                continue;
            }
            char buffer[MAX_FILE_SIZE];
            size_t read = 0;
            do {
                read = fread(buffer, sizeof(char), MAX_FILE_SIZE, source_file);
                fwrite(buffer, sizeof(char), read, destination_file);
            } while (read > 0);
            fclose(destination_file);
            fclose(source_file);
        }
    }
    return NULL;
}

char* get_relative_path(char* path, int path_length, char* root) {
    if (strncmp(path, root, strlen(root)) != 0) {
        return NULL;
    }
    char* relative_path = malloc(path_length - strlen(root));
    strcpy(relative_path, path + strlen(root) + 1);
    return relative_path;
}

void wait_for_termination(pthread_t threads[]) {
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
}

void start_file_sync(char* source_path, char* destination_path) {
    DiffSet* diff = diff_directories(source_path, destination_path);
    pthread_t threads[THREAD_COUNT];
    ThreadArgs thread_args[THREAD_COUNT];
    int thread_id = 0;
    for (int i = 0; i < diff->count; i++) {
        thread_args[thread_id].diff = diff;
        thread_args[thread_id].source = source_path;
        thread_args[thread_id].destination = destination_path;
        int rc = pthread_create(&threads[thread_id], NULL, sync_files, (void*) &thread_args[thread_id]);
        if (rc != 0) {
            log_error("Failed to create thread");
            continue;
        }
        thread_id++;
        if (thread_id == THREAD_COUNT) {
            wait_for_termination(threads);
            thread_id = 0;
        }
    }
    wait_for_termination(threads);
    free(diff->files);
    free(diff);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_path> <destination_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    start_file_sync(argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}