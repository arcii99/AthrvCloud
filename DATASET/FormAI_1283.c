//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

#define THREAD_MAX 50
#define PATH_MAX 100

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int num_threads = 0;

typedef struct {
    char file_name[PATH_MAX];
    unsigned long long file_size;
} file_info;

void *analyze_directory(void *dir_path);
void *analyze_file(void *file);
void print_result(file_info *result);

int main(int argc, char *argv[]) {
    pthread_t threads[THREAD_MAX];

    if(argc != 2) {
        printf("Usage: ./disk_analyzer <directory_path>\n");
        return 1;
    }

    char *dir_path = argv[1];

    // Create a new thread for each subdirectory
    pthread_create(&threads[num_threads++], NULL, analyze_directory, dir_path);
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *analyze_directory(void *dir_path) {
    char *path = (char *)dir_path;
    DIR *dir;
    struct dirent *entry;
    pthread_t threads[THREAD_MAX];
    int num_files = 0;
    file_info results[PATH_MAX];

    if((dir = opendir(path)) == NULL) {
        printf("Error: cannot open directory \"%s\"\n", path);
        pthread_exit(NULL);
    }

    // Analyze each file in the directory
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_REG) {
            char file_path[PATH_MAX];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            pthread_create(&threads[num_files++], NULL, analyze_file, file_path);
            if(num_files >= THREAD_MAX) {
                // Wait for the threads to finish before creating more
                for(int i = 0; i < num_files; i++) {
                    file_info *result;
                    pthread_join(threads[i], (void **)&result);
                    results[i] = *result;
                }
                pthread_mutex_lock(&lock);
                print_result(results);
                num_files = 0;
                pthread_mutex_unlock(&lock);
            }
        } else if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Recursively analyze subdirectories
            char dir_path[PATH_MAX];
            sprintf(dir_path, "%s/%s", path, entry->d_name);
            pthread_create(&threads[num_threads++], NULL, analyze_directory, dir_path);
        }
    }

    // Wait for the remaining threads to finish
    for(int i = 0; i < num_files; i++) {
        file_info *result;
        pthread_join(threads[i], (void **)&result);
        results[i] = *result;
    }
    pthread_mutex_lock(&lock);
    print_result(results);
    pthread_mutex_unlock(&lock);

    closedir(dir);
    pthread_exit(NULL);
}

void *analyze_file(void *file_path) {
    char *path = (char *)file_path;
    FILE *file;
    unsigned long long size = 0;
    file_info *result = (file_info *)malloc(sizeof(file_info));

    if((file = fopen(path, "rb")) == NULL) {
        printf("Error: cannot open file \"%s\"\n", path);
        pthread_exit(NULL);
    }

    // Calculate the size of the file
    fseeko(file, 0, SEEK_END);
    size = ftell(file);
    fseeko(file, 0, SEEK_SET);

    fclose(file);

    strcpy(result->file_name, path);
    result->file_size = size;
    pthread_exit(result);
}

void print_result(file_info *result) {
    printf("File Name\t\t\tFile Size\n");
    for(int i = 0; i < PATH_MAX && result[i].file_size > 0; i++) {
        printf("%-30s\t%llu bytes\n", result[i].file_name, result[i].file_size);
    }
}