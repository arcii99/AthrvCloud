//FormAI DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof (struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s DIR1 DIR2\n", argv[0]);
        exit(1);
    }

    char* dir1 = argv[1];
    char* dir2 = argv[2];

    int fd1 = inotify_init();
    if (fd1 < 0) {
        perror("inotify_init()");
        exit(1);
    }

    int fd2 = inotify_init();
    if (fd2 < 0) {
        perror("inotify_init()");
        exit(1);
    }

    int wd1 = inotify_add_watch(fd1, dir1, IN_ALL_EVENTS);
    if (wd1 < 0) {
        perror("inotify_add_watch()");
        exit(1);
    }

    int wd2 = inotify_add_watch(fd2, dir2, IN_ALL_EVENTS);
    if (wd2 < 0) {
        perror("inotify_add_watch()");
        exit(1);
    }

    printf("Monitoring directories %s and %s...\n", dir1, dir2);

    char buf[BUF_LEN];
    while (1) {
        ssize_t length = read(fd1, buf, BUF_LEN);
        if (length < 0) {
            perror("read()");
            exit(1);
        }

        size_t i = 0;
        while (i < length) {
            struct inotify_event* event = (struct inotify_event*) &buf[i];

            if (event->len) {
                if (event->mask & IN_CREATE || event->mask & IN_MODIFY) {
                    char* filename = event->name;

                    char path1[strlen(dir1) + strlen(filename) + 2];
                    sprintf(path1, "%s/%s", dir1, filename);

                    char path2[strlen(dir2) + strlen(filename) + 2];
                    sprintf(path2, "%s/%s", dir2, filename);

                    int fd1 = open(path1, O_RDONLY);
                    if (fd1 < 0) {
                        perror("open()");
                        break;
                    }

                    int fd2 = creat(path2, O_RDWR);
                    if (fd2 < 0) {
                        perror("creat()");
                        break;
                    }

                    char buf[1024];
                    ssize_t len;
                    while ((len = read(fd1, buf, sizeof(buf))) > 0) {
                        write(fd2, buf, len);
                    }

                    close(fd1);
                    close(fd2);

                    printf("Synchronized file %s from %s to %s\n", filename, dir1, dir2);
                }
            }

            i += EVENT_SIZE + event->len;
        }
    }

    return 0;
}