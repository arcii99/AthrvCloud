//FormAI DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <sys/types.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUFF_SIZE (1024*(EVENT_SIZE + 16))

char* src_path;
char* dest_path;

void sync_files(char* file_path) {
    char* temp_dir;
    char* temp_file;
    char* temp_dest;
    int src_fd, dest_fd;
    struct stat src_stat, dest_stat;

    // Set the source path
    temp_dir = malloc(strlen(src_path) + strlen(file_path) + 2);
    sprintf(temp_dir, "%s/%s", src_path, file_path);

    // Set the destination path
    temp_file = malloc(strlen(dest_path) + strlen(file_path) + 2);
    sprintf(temp_file, "%s/%s", dest_path, file_path);

    // Get stat of the source file
    stat(temp_dir, &src_stat);

    // Check if the file exists in the destination
    if(stat(temp_file, &dest_stat) == 0) {

        // Check if the source file is newer than the destination file
        if(src_stat.st_mtime > dest_stat.st_mtime) {

            // Open the source file
            src_fd = open(temp_dir, O_RDONLY);
            if(src_fd == -1) {
                fprintf(stderr, "Error opening source file %s!\n", temp_dir);
                return;
            }

            // Open the destination file with write permissions
            dest_fd = open(temp_file, O_WRONLY | O_TRUNC);
            if(dest_fd == -1) {
                fprintf(stderr, "Error opening destination file %s!\n", temp_file);
                return;
            }

            // Copy file content from source to destination
            char buffer[1024];
            int n;
            while((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
                write(dest_fd, buffer, n);
            }

            // Close files
            close(src_fd);
            close(dest_fd);
        }
    } else {

        // Open the source file
        src_fd = open(temp_dir, O_RDONLY);
        if(src_fd == -1) {
            fprintf(stderr, "Error opening source file %s!\n", temp_dir);
            return;
        }

        // Create the directory path in the destination
        temp_dest = strdup(temp_file);
        char* dir_name = dirname(temp_dest);
        mkdir(dir_name, S_IRWXU | S_IRWXG | S_IRWXO);

        // Create the destination file with write permissions
        dest_fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC);
        if(dest_fd == -1) {
            fprintf(stderr, "Error creating destination file %s!\n", temp_file);
            return;
        }

        // Copy file content from source to destination
        char buffer[1024];
        int n;
        while((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
            write(dest_fd, buffer, n);
        }

        // Close files
        close(src_fd);
        close(dest_fd);

        // Free memory
        free(temp_dest);
    }

    // Free memory
    free(temp_dir);
    free(temp_file);
}

int main(int argc, char* argv[]) {

    // Check if the program was called with the correct arguments
    if(argc != 3) {
        printf("Usage: %s <src_path> <dest_path>\n", argv[0]);
        return -1;
    }

    // Set the source and destination paths
    src_path = argv[1];
    dest_path = argv[2];

    // Initialize inotify
    int fd, wd;
    char buffer[BUFF_SIZE];
    fd = inotify_init();
    if(fd == -1) {
        fprintf(stderr, "Error initializing inotify!\n");
        return -1;
    }

    // Add the source path to be watched
    wd = inotify_add_watch(fd, src_path, IN_CREATE | IN_DELETE | IN_MODIFY);
    if(wd == -1) {
        fprintf(stderr, "Error adding watch for %s!\n", src_path);
        return -1;
    }

    // Start the file syncing loop
    while(1) {

        // Wait for events
        int n, i = 0;
        n = read(fd, buffer, BUFF_SIZE);
        if(n == -1) {
            fprintf(stderr, "Error reading inotify events!\n");
            break;
        }

        // Process events
        while(i < n) {
            struct inotify_event* event = (struct inotify_event*)&buffer[i];

            // Check for file creation event
            if(event->mask & IN_CREATE) {
                if(event->mask & IN_ISDIR) {
                    char* temp_dir;
                    temp_dir = malloc(strlen(src_path) + strlen(event->name) + 2);
                    sprintf(temp_dir, "%s/%s", src_path, event->name);
                    inotify_add_watch(fd, temp_dir, IN_CREATE | IN_DELETE | IN_MODIFY);
                    free(temp_dir);
                } else {
                    sync_files(event->name);
                }
            }

            // Check for file deletion event
            if(event->mask & IN_DELETE) {
                if(event->mask & IN_ISDIR) {
                    char* temp_dir;
                    temp_dir = malloc(strlen(src_path) + strlen(event->name) + 2);
                    sprintf(temp_dir, "%s/%s", src_path, event->name);
                    inotify_rm_watch(fd, inotify_add_watch(fd, temp_dir, IN_CREATE | IN_DELETE | IN_MODIFY));
                    free(temp_dir);
                } else {
                    char* temp_file;
                    temp_file = malloc(strlen(dest_path) + strlen(event->name) + 2);
                    sprintf(temp_file, "%s/%s", dest_path, event->name);
                    remove(temp_file);
                    free(temp_file);
                }
            }

            // Check for file modification event
            if(event->mask & IN_MODIFY) {
                sync_files(event->name);
            }

            i += EVENT_SIZE + event->len;
        }
    }

    // Close inotify
    close(fd);

    return 0;
}