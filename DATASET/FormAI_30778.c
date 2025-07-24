//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_CPU 8
#define BUF_SIZE 128

int get_cpu_usage(int cpu_id);

int main() {
    int cpu_usage[MAX_CPU] = {0};

    while (1) {
        for (int i = 0; i < MAX_CPU; i++) {
            cpu_usage[i] = get_cpu_usage(i);
        }
        printf("CPU Usage:\n");
        for (int i = 0; i < MAX_CPU; i++) {
            printf("CPU %d: %d%%\n", i, cpu_usage[i]);
        }
        sleep(1);
    }

    return 0;
}

int get_cpu_usage(int cpu_id) {
    char buf[BUF_SIZE];
    char path[BUF_SIZE];
    int fd;

    snprintf(path, BUF_SIZE, "/proc/stat");

    fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    ssize_t n = read(fd, buf, BUF_SIZE);

    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buf[n] = '\0';

    char* save_ptr;
    char* token = strtok_r(buf, "\n", &save_ptr);

    while (token != NULL) {
        if (strncmp(token, "cpu", 3) == 0) {
            int id;
            int usage = 0;
            char* str = token + 3;
            sscanf(str, "%d", &id);

            if (id == cpu_id) {
                char* p = str;

                for (int i = 0; i < 10 && p != NULL; i++) {
                    usage += strtol(p, &p, 10);
                }

                return usage;
            }
        }

        token = strtok_r(NULL, "\n", &save_ptr);
    }

    return 0;
}