//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

#define MAX_FILES 1000
#define MAX_PATH 600
#define MAX_VIRUS_NAME 30

char *viruses[] = {"trojan.exe", "worm.exe", "virus.exe"};

typedef struct file_data {
    char path[MAX_PATH];
    char filename[30];
} FileData;

int num_files = 0;
FileData files[MAX_FILES];

void *scan_file(void *file) {
    FILE *fp;
    char filepath[MAX_PATH], line[80], virusname[MAX_VIRUS_NAME];
    int is_virus = 0;

    FileData *f = (FileData *) file;
    sprintf(filepath, "%s/%s", f->path, f->filename);

    if ((fp = fopen(filepath, "r")) == NULL) {
        perror("Error opening file.\n");
        pthread_exit(NULL);
    }
    while (fgets(line, 80, fp) != NULL) {
        for (int i = 0; i < sizeof(viruses) / sizeof(char *); i++) {
            if (strstr(line, viruses[i]) != NULL) {
                is_virus = 1;
                strcpy(virusname, viruses[i]);
                break;
            }
        }
    }
    fclose(fp);

    if (is_virus) {
        printf("File %s infected with %s.\n", filepath, virusname);
    }

    pthread_exit(NULL);
}

void *scan_directory(void *arg) {
    char *path = (char *) arg;
    DIR *dir;
    struct dirent *entry;
    pthread_t tid[num_files];
    int i = 0, num_threads = 0;

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory.\n");
        pthread_exit(NULL);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0) {
            continue;
        }
        sprintf(files[num_files].path, "%s", path);
        sprintf(files[num_files].filename, "%s", entry->d_name);
        num_files++;
    }
    closedir(dir);

    while (i < num_files && num_threads < 10) {
        pthread_create(&tid[i], NULL, scan_file, &files[i]);
        i++;
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./antivirus [directory path]\n");
        exit(1);
    }

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if (pthread_create(&tid, &attr, scan_directory, argv[1]) != 0) {
        perror("Error creating thread.\n");
        exit(1);
    }

    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
}