//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int count = 0;
    while (1) {
        FILE* fp = fopen("/proc/stat", "r");
        char buf[1024];
        fgets(buf, 1024, fp);

        int user, nice, system, idle, iowait, irq, softirq;
        sscanf(buf, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

        int total = user + nice + system + idle + iowait + irq + softirq;
        int usage = (100 * (total - idle)) / total;
        printf("CPU Usage: %d%%\n", usage);

        fclose(fp);
        sleep(1);
        count++;
        if (count == 10) {
            printf("Exiting CPU Usage Monitor\n");
            break;
        }
    }

    return 0;
}