//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void copyFile(char *src, char *dest){
    FILE *fsrc, *fdest;
    char buffer[BUFFER_SIZE];

    fsrc = fopen(src, "rb");
    if(fsrc == NULL){
        perror(src);
        pthread_exit(NULL);
    }

    fdest = fopen(dest, "wb");
    if(fdest == NULL){
        perror(dest);
        pthread_exit(NULL);
    }

    while(!feof(fsrc)){
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, fsrc);
        fwrite(buffer, 1, bytesRead, fdest);
    }
    fclose(fsrc);
    fclose(fdest);
}

void *syncDirectory(void *arg){
    DIR *dir;
    struct dirent *entry;
    char *srcDir = (char *)arg;

    if((dir = opendir(srcDir)) == NULL){
        perror(srcDir);
        pthread_exit(NULL);
    }

    while((entry = readdir(dir)) != NULL){
        char srcFile[100], destFile[100];
        struct stat attr;

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        strcpy(srcFile, srcDir);
        strcat(srcFile, "/");
        strcat(srcFile, entry->d_name);

        if(stat(srcFile, &attr) == 0 && S_ISREG(attr.st_mode)){
            pthread_mutex_lock(&mutex); // Locks access to shared variable
            printf("Copying file %s\n", srcFile);
            strcpy(destFile, "/home/user/documents/backup/");
            strcat(destFile, entry->d_name);
            copyFile(srcFile, destFile);
            pthread_mutex_unlock(&mutex); // Unlocks access to shared variable
        } else if(stat(srcFile, &attr) == 0 && S_ISDIR(attr.st_mode)){
            pthread_t child;
            if(pthread_create(&child, NULL, syncDirectory, strdup(srcFile)) != 0)
                perror("pthread_create failed");
            if(pthread_join(child, NULL) != 0)
                perror("pthread_join failed");
        }
    }
    closedir(dir);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[MAX_THREADS];
    int total_threads = 0;

    if(pthread_create(&threads[0], NULL, syncDirectory, "/home/user/documents") != 0)
        perror("pthread_create failed");
    total_threads++;

    // Wait for all threads to complete
    for(int i = 0; i < total_threads; i++){
        if(pthread_join(threads[i], NULL) != 0)
            perror("pthread_join failed");
    }

    return 0;
}