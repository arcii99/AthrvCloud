//FormAI DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#define MAX_EVENTS 1024 /* Maximum number of events to process at one go */
#define NAME_LEN 16 /* Assuming that all filenames will not exceed 16 characters */
#define BUF_LEN (MAX_EVENTS * (sizeof(struct inotify_event) + NAME_LEN))

static char* source_dir;
static char* dest_dir;
static int inotify_fd, wd;
static bool is_running;

/* Function to synchronize files from source directory to destination directory */
void sync_files(char* filename) {
    char src_file[256], dst_file[256];
    sprintf(src_file, "%s/%s", source_dir, filename);
    sprintf(dst_file, "%s/%s", dest_dir, filename);

    struct stat stat_buf;
    if (stat(src_file, &stat_buf) == -1) {
        perror("Error in getting file status");
        return;
    }

    if (access(dst_file, F_OK) != -1) { // File exists in destination directory
        struct stat dst_stat_buf;
        if (stat(dst_file, &dst_stat_buf) == -1) {
            perror("Error in getting file status");
            return;
        }

        if (!S_ISREG(dst_stat_buf.st_mode)) { // Check if destination file is regular file
            fprintf(stderr, "%s is not a regular file. Skipping sync...\n", dst_file);
            return;
        }

        if (stat_buf.st_mtime <= dst_stat_buf.st_mtime) { // Check if source file is newer than destination file
            printf("%s is already synchronized!\n", filename);
            return;
        }
    }

    printf("Syncing %s to %s...\n", src_file, dst_file);

    int fd1 = open(src_file, O_RDONLY);
    if (fd1 == -1) {
        perror("Error in opening source file");
        return;
    }

    int fd2 = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1) {
        perror("Error in opening destination file");
        close(fd1);
        return;
    }

    char buf[4096];
    ssize_t n;
    while ((n = read(fd1, buf, sizeof(buf))) > 0) {
        if (write(fd2, buf, n) != n) {
            perror("Error in writing to destination file");
            close(fd1);
            close(fd2);
            return;
        }
    }

    close(fd1);
    close(fd2);

    /* Set the modification time of destination file same as source file */
    struct timespec times[2];
    times[0] = stat_buf.st_atim;
    times[1] = stat_buf.st_mtim;
    if (utimensat(AT_FDCWD, dst_file, times, AT_SYMLINK_NOFOLLOW) == -1) {
        perror("Error in setting modification time");
        return;
    }

    printf("%s has been synchronized!\n", filename);
}

/* Function to handle inotify events */
void handle_events(char* buffer) {
    struct inotify_event* event;
    int pos = 0;

    while (pos < BUF_LEN) {
        event = (struct inotify_event*) &buffer[pos];
        if (event->len) {
            if (event->mask & IN_CREATE) {
                printf("New file created: %s\n", event->name);
                sync_files(event->name);
            }
            else if (event->mask & IN_MODIFY) {
                printf("File modified: %s\n", event->name);
                sync_files(event->name);
            }
            else if (event->mask & IN_DELETE) {
                printf("File deleted: %s\n", event->name);
            }
        }
        pos += sizeof(struct inotify_event) + event->len;
    }
}

/* Function to handle signals */
void handle_signal(int sig) {
    printf("\nReceived signal %d. Terminating...\n", sig);
    is_running = false;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Invalid number of arguments!\n");
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_dir = argv[1];
    dest_dir = argv[2];

    printf("Source directory: %s\n", source_dir);
    printf("Destination directory: %s\n", dest_dir);

    /* Initialize inotify */
    inotify_fd = inotify_init();
    if (inotify_fd == -1) {
        perror("Error in inotify_init");
        exit(EXIT_FAILURE);
    }

    /* Watch source directory for new files, modifications and deletions */
    wd = inotify_add_watch(inotify_fd, source_dir, IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd == -1) {
        perror("Error in inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    printf("Watching %s for new files, modifications and deletions...\n", source_dir);

    /* Register signal handlers */
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error in sigaction");
        exit(EXIT_FAILURE);
    }

    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error in sigaction");
        exit(EXIT_FAILURE);
    }

    /* Loop infinitely to handle inotify events */
    is_running = true;
    char buffer[BUF_LEN];
    while (is_running) {
        ssize_t num_read = read(inotify_fd, buffer, BUF_LEN);
        if (num_read == 0) {
            fprintf(stderr, "Error in reading from inotify fd: end-of-file reached\n");
            break;
        }
        else if (num_read == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("Error in reading from inotify fd");
            break;
        }

        handle_events(buffer);
    }

    /* Clean up */
    if (inotify_rm_watch(inotify_fd, wd) == -1) {
        perror("Error in inotify_rm_watch");
    }

    if (close(inotify_fd) == -1) {
        perror("Error in closing inotify fd");
    }

    printf("Terminated successfully!\n");

    return 0;
}