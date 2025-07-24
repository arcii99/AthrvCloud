//FormAI DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

typedef struct {
    char path[PATH_MAX];
    int flag;
} FileInfo;

void* syncFiles(void* arg) {
    FileInfo* file = (FileInfo*)arg;
    
    // Check if file exists and is readable
    if (access(file->path, F_OK | R_OK) == -1) {
        perror("Failed to open file");
        pthread_exit(NULL);
    }

    // Initialize file descriptors for reading and writing
    int readFD = open(file->path, O_RDONLY);
    char outputPath[PATH_MAX];
    sprintf(outputPath, "%s%s", file->flag == 0 ? "./Copy/" : "./Backup/", file->path);

    int writeFD = open(outputPath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (writeFD == -1) {
        perror("Failed to open output file");
        close(readFD);
        pthread_exit(NULL);
    }

    // Allocate buffer for read and write operations
    char buffer[BUFSIZ];
    ssize_t bytesRead;
    while ((bytesRead = read(readFD, buffer, BUFSIZ)) > 0) {
        ssize_t bytesWritten = write(writeFD, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Failed to write to output file");
            close(readFD);
            close(writeFD);
            unlink(outputPath);
            pthread_exit(NULL);
        }
    }

    // Close file descriptors
    close(readFD);
    close(writeFD);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    DIR* dir = opendir(argv[1]);
    if (!dir) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    // Create directories for backup and copy
    mkdir("./Backup", 0777);
    mkdir("./Copy", 0777);

    // Traverse directory and copy files
    struct dirent* dirEntry;
    while ((dirEntry = readdir(dir)) != NULL) {
        // Skip files that are not regular files
        if (dirEntry->d_type != DT_REG) {
            continue;
        }

        FileInfo copyFile;
        FileInfo backupFile;
        sprintf(copyFile.path, "%s/%s", argv[1], dirEntry->d_name);
        sprintf(backupFile.path, "%s/%s", argv[1], dirEntry->d_name);
        copyFile.flag = 0;
        backupFile.flag = 1;

        pthread_t copyThread;
        if (pthread_create(&copyThread, NULL, syncFiles, &copyFile)) {
            perror("Failed to create thread for copying file");
            return EXIT_FAILURE;
        }

        pthread_t backupThread;
        if (pthread_create(&backupThread, NULL, syncFiles, &backupFile)) {
            perror("Failed to create thread for backing up file");
            return EXIT_FAILURE;
        }

        pthread_join(copyThread, NULL);
        pthread_join(backupThread, NULL);
    }

    closedir(dir);

    return EXIT_SUCCESS;
}