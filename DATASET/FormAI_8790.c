//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    int no_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
    while (1) {
        if (sysinfo(&si) == -1) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }
        unsigned long long total_ram = si.totalram * si.mem_unit;
        unsigned long long used_ram = (si.totalram - si.freeram) * si.mem_unit;
        double cpu_usage = 0;
        for (int i = 0; i < no_of_processors; i++){
            cpu_usage += si.loads[i];
        }
        printf("CPU Usage: %.2f%%\n", cpu_usage * 100.0 / (no_of_processors * 65536.0));
        printf("Total RAM: %llu MB\n", total_ram/1024/1024);
        printf("Used RAM: %llu MB\n", used_ram/1024/1024);
        sleep(1);
        printf("\033[A\033[A\033[A"); // to move cursor up to overwrite the previous output
    }
    return 0;
}