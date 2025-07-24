//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC_NAME_LEN 255
#define MAX_PROC_PATH_LEN 1023

typedef struct proc_info {
    pid_t pid;
    char name[MAX_PROC_NAME_LEN];
    char path[MAX_PROC_PATH_LEN];
    float cpu_usage;
} proc_info;

int get_proc_names(int max_proc_num, proc_info* proc_names) {
    FILE* fp;
    char buf[256];
    int proc_count = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen failed");
        return -1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (strncmp(buf, "cpu ", 4) == 0) {
            float cpu_time[10];
            sscanf(buf, "%*s %f %f %f %f %f %f %f %f %f %f",
                   &cpu_time[0], &cpu_time[1], &cpu_time[2], &cpu_time[3], &cpu_time[4],
                   &cpu_time[5], &cpu_time[6], &cpu_time[7], &cpu_time[8], &cpu_time[9]);
            sleep(1);
            fseek(fp, 0L, SEEK_SET);
            fgets(buf, sizeof(buf), fp);
            sscanf(buf, "%*s %f %f %f %f %f %f %f %f %f %f",
                   &cpu_time[0], &cpu_time[1], &cpu_time[2], &cpu_time[3], &cpu_time[4],
                   &cpu_time[5], &cpu_time[6], &cpu_time[7], &cpu_time[8], &cpu_time[9]);
            fclose(fp);
            for (int i = 0; i < max_proc_num; i++) {
                proc_info* proc = &proc_names[i];
                if (proc->pid == 0) {
                    break;
                }
                fp = fopen(proc->path, "r");
                if (fp == NULL) {
                    continue;
                }
                unsigned long long user_time, sys_time, dummy;
                char proc_name[MAX_PROC_NAME_LEN];
                char state;
                int ret = fscanf(fp, "%d %s %c %d %d %d %d %d %llu %llu",
                                 &(proc->pid), proc_name, &state, &dummy, &dummy, &dummy,
                                 &dummy, &dummy, &user_time, &sys_time);
                fclose(fp);
                if (ret != 10) {
                    continue;
                }
                if (strlen(proc->name) < 1) {
                    strcpy(proc->name, proc_name);
                }
                float total_time = (float)(user_time + sys_time) / sysconf(_SC_CLK_TCK);
                proc->cpu_usage = 100 * ((total_time / 1) / (cpu_time[0] - cpu_time[3]));
                proc_count++;
            }
            break;
        }
    }
    return proc_count;
}

int main() {
    proc_info procs[100] = { 0 };
    int n_procs = get_proc_names(100, procs);
    for (int i = 0; i < n_procs; i++) {
        printf("%d %s %f\n", procs[i].pid, procs[i].name, procs[i].cpu_usage);
    }
    return 0;
}