//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

void print_header() {
    printf("%10s %10s %10s %10s %10s %10s %10s %10s %10s %10s\n", "PID", "USER", "PR", "NI", "VIRT", "RES", "SHR", "S", "CPU%", "MEM%");
}

int main() {
    print_header();
    while(1) {
        char* command = "top -b -n 1 | tail -n +8 | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9,$10}'";
        FILE* temp_fd = popen(command, "r");
        char* line = NULL;
        ssize_t read;
        size_t  len = 0;
        float total_cpu = 0, total_mem = 0;
        while ((read = getline(&line, &len, temp_fd)) != -1) {
            int pid, res, shr, cpu;
            float virt, mem;
            char user[10], pri[4], ni[4], s[2];

            if (sscanf(line, "%d %s %s %f %d %f %d %d %s %f", &pid, user, pri, &virt, &res, &mem, &shr, &cpu, s, &mem) == 10) {
                if (strlen(user) > 8) {
                user[8] = '.';
                user[9] = '\0';
                }
            }

            printf("%10d %10s %10s %10s %10.2f %10d %10d %10s %10d%% %10.2f%%\n", pid, user, pri, ni, virt, res / 1024, shr / 1024, s, cpu, mem);
            total_cpu += cpu;
            total_mem += mem;
        }
        printf("--------------------------------------------------------------\n");
        printf("%10s %10s %10s %10s %10s %10s %10s %10s %10.2f%% %10.2f%%\n", "", "", "", "", "", "", "", "", total_cpu, total_mem);
        printf("--------------------------------------------------------------\n");
        sleep(1);
    }
    return 0;
}