//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>

#define EVENT_SIZE  (sizeof (struct inotify_event))
#define EVENT_BUF_LEN     (1024 * (EVENT_SIZE + 16))

int main(int argc, char *argv[]) {
    
    int fd, wd, length, i = 0;
    char buffer[EVENT_BUF_LEN];
    
    // create a new inotify instance
    fd = inotify_init();
    
    // add the first file descriptor in the watch list
    wd = inotify_add_watch(fd, argv[1], IN_MODIFY | IN_CREATE | IN_MOVE | IN_DELETE);
    
    while (1) {
        length = read(fd, buffer, EVENT_BUF_LEN);
        
        // Handle the events that occurred
        while (i < length) {
            struct inotify_event *event = (struct inotify_event *) &buffer[i];
            if (event->mask & IN_CREATE) {
                printf("File %s was created.\n", event->name);
            } else if (event->mask & IN_DELETE) {
                printf("File %s was deleted.\n", event->name);
            } else if (event->mask & IN_MOVE) {
                printf("File %s was moved.\n", event->name);
            } else if (event->mask & IN_MODIFY) {
                printf("File %s was modified.\n", event->name);
            }
            i += EVENT_SIZE + event->len;
        }
        
        i = 0;
        memset(buffer, 0, EVENT_BUF_LEN);
    }
    
    // Cleanup
    inotify_rm_watch(fd, wd);
    close(fd);
    
    return 0;
}