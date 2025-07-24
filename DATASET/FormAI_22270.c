//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

void* sync_file(void* arg);
char* trim_path(char* path);
int is_dir(char* path);

int main(int argc, char* argv[]) {
    char* dir1 = argv[1];
    char* dir2 = argv[2];

    pthread_t thread1, thread2;
    
    if(pthread_create(&thread1, NULL, sync_file, dir1) != 0) {
        printf("Error creating thread 1\n");
        exit(1);
    }
    
    if(pthread_create(&thread2, NULL, sync_file, dir2) != 0) {
        printf("Error creating thread 2\n");
        exit(1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("File synchronization complete\n");
    return 0;
}

void* sync_file(void* arg) {
    char* path = (char*) arg;
    DIR* dir = opendir(path);

    if(dir == NULL) {
        printf("Error opening directory %s\n", path);
        return NULL;
    }

    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        char* filename = entry->d_name;
        if(strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
            continue;
        }
        char file1_path[1000];
        char file2_path[1000];
        sprintf(file1_path, "%s/%s", path, filename);
        sprintf(file2_path, "%s/../%s/%s", path, trim_path(path), filename);

        if(is_dir(file1_path)) {
            pthread_t thread;
            pthread_create(&thread, NULL, sync_file, file1_path);
            pthread_join(thread, NULL);
        } else {
            FILE* file1 = fopen(file1_path, "r");
            FILE* file2 = fopen(file2_path, "r");

            if(file1 == NULL) {
                printf("Error opening file %s\n", file1_path);
            } else if(file2 == NULL) {
                printf("Creating file %s in %s\n", filename, trim_path(path));
                FILE* new_file = fopen(file2_path, "w");
                fclose(new_file);
            } else {
                fclose(file2);

                char buffer1[1000];
                char buffer2[1000];

                size_t n1, n2;
                while((n1 = fread(buffer1, 1, sizeof(buffer1), file1)) > 0 
                      && (n2 = fread(buffer2, 1, sizeof(buffer2), file2)) > 0) {
                    if(n1 != n2 || memcmp(buffer1, buffer2, n1) != 0) {
                        printf("Updating file %s in %s\n", filename, trim_path(path));
                        FILE* updated_file = fopen(file2_path, "w");
                        fwrite(buffer1, 1, n1, updated_file);
                        fclose(updated_file);
                        break;
                    }
                }

                fclose(file1);
            }
        }
    }

    closedir(dir);

    return NULL;
}

char* trim_path(char* path) {
    char* pointer = strrchr(path, '/');
    return pointer == NULL ? path : pointer + 1;
}

int is_dir(char* path) {
    DIR* dir = opendir(path);
    if(dir == NULL) {
        return 0;
    }
    closedir(dir);
    return 1;
}