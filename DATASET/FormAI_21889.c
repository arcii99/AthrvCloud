//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char command[50];
    while(1) {
        printf("Command: ");
        scanf("%s", command);
        if(strcmp(command, "exit") == 0)
            exit(0);
        if(strcmp(command, "cpu")) {
            FILE* file = fopen("/proc/stat", "r");
            long long int user, nice, system, idle, iowait, irq, softirq, steal, quest, guest_nice;
            fscanf(file, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &quest, &guest_nice);
            fclose(file);
            double total1 = user + nice + system + idle + iowait + irq + softirq + steal;
            double non_idle1 = user + nice + system + irq + softirq + steal;
            printf("Calculating...\n");
            sleep(1);
            file = fopen("/proc/stat", "r");
            fscanf(file, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &quest, &guest_nice);
            fclose(file);
            double total2 = user + nice + system + idle + iowait + irq + softirq + steal;
            double non_idle2 = user + nice + system + irq + softirq + steal;
            double total_diff = total2 - total1;
            double non_idle_diff = non_idle2 - non_idle1;
            double usage = (non_idle_diff / total_diff) * 100.0;
            printf("CPU Usage: %.2f%\n", usage);
        }
        else {
            printf("Invalid Command\n");
        }
    }

    return 0;
}