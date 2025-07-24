//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

#define MAX_BUF 1024

int fd;

void signal_handler(int sig) {
    printf("Caught signal %d\n", sig);
    close(fd);
    exit(sig);
}

int main() {
    mkfifo("/tmp/asynch_fifo", 0666);
    
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    fd = open("/tmp/asynch_fifo", O_RDWR);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(EXIT_FAILURE);
    }
    
    ssize_t num_bytes;
    char buf[MAX_BUF];
    
    while(1) {
        num_bytes = read(fd, buf, MAX_BUF);
        if (num_bytes == -1) {
            if (errno == EINTR) continue;
            else {
                perror("Error reading from FIFO");
                break;
            }
        }
        printf("Received message: %.*s", num_bytes, buf);
    }
    
    close(fd);
    unlink("/tmp/asynch_fifo");
    exit(EXIT_SUCCESS);
}