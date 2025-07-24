//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>

#define BUF_SIZE 1024

volatile sig_atomic_t usr1_flag = 0;

void sig_handler(int sig) {
    if (sig == SIGUSR1) {
        usr1_flag = 1;
    }
}

void async_task() {
    pid_t pid = getpid();
    while (1) {
        if (usr1_flag == 1) {
            time_t now = time(NULL);
            printf("Process: %d Current time: %s", pid, ctime(&now));
            usr1_flag = 0;
        }
        usleep(1000);
    }
}

int main() {
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = sig_handler;
    if (sigaction(SIGUSR1, &act, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        async_task();
        exit(EXIT_SUCCESS);
    } else {
        // parent process
        char buf[BUF_SIZE];
        int fd = open("/dev/null", O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        srand(time(NULL));
        int sleep_time = rand() % 10 + 1;
        sprintf(buf, "Child process started with PID: %d. Sleeping for %d seconds.", pid, sleep_time);
        write(fd, buf, strlen(buf));
        sleep(sleep_time);
        kill(pid, SIGUSR1);
        close(fd);
        exit(EXIT_SUCCESS);
    }
}