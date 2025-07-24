//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysinfo.h>

#define PROC_STAT "/proc/stat"

int main() {

    long double a_load[3];
    long double b_load[3];
    long double load_avg;
    bool is_first_run = true;

    while (true) {
        int fd = open(PROC_STAT, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        
        char buf[1024];
        size_t num_read = read(fd, buf, sizeof(buf) - 1);
        if (num_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buf[num_read] = '\0';

        // Find the line that starts with "cpu ".
        char* line = buf;
        char* cpu_line = NULL;
        while (*line) {
            if (strncmp(line, "cpu ", 4) == 0) {
                cpu_line = line;
                break;
            }
            line = strchr(line, '\n');
            if (line)
                ++line;
        }

        if (cpu_line == NULL) {
            fprintf(stderr, "Failed to find cpu line\n");
            exit(EXIT_FAILURE);
        }

        // Parse the cpu line
        unsigned long long user_jiffies =
            strtoull(cpu_line + 5, NULL, 10);
        unsigned long long nice_jiffies =
            strtoull(strchr(cpu_line + 5, ' ') + 1, NULL, 10);
        unsigned long long sys_jiffies =
            strtoull(strchr(cpu_line + 5, ' ') + 1, NULL, 10);

        // Calculate the total jiffies for a and b.
        unsigned long long a_total_jiffies =
            user_jiffies + nice_jiffies + sys_jiffies;
        unsigned long long b_total_jiffies = 0;
        for (int i = 0; i < 3; ++i) {
            a_load[i] = a_total_jiffies - user_jiffies;
            b_load[i] = b_total_jiffies - user_jiffies;
            a_total_jiffies += sys_jiffies;
            b_total_jiffies += sys_jiffies;
            if (i == 1)
                sys_jiffies += nice_jiffies;
        }

        if (!is_first_run) {
            load_avg = (b_load[0] - a_load[0]) +
                (b_load[1] - a_load[1]) +
                (b_load[2] - a_load[2]);
            load_avg /= sysconf(_SC_NPROCESSORS_ONLN) *
                (b_total_jiffies - a_total_jiffies);

            printf("CPU usage: %.2Lf%%\n", 100 * load_avg);
        }
        else {
            is_first_run = false;
        }

        close(fd);
        sleep(1);
    }

    return 0;
}