//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESS_NAME_LENGTH 32
#define MAX_PROCESS_LIST_SIZE 1024

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    double cpu_usage;
} ProcessInfo;

int compare_process_info(const void* a, const void* b) {
    double diff = ((ProcessInfo*)b)->cpu_usage - ((ProcessInfo*)a)->cpu_usage;
    return diff == 0 ? 0 : (diff > 0 ? 1 : -1);
}

int main() {
    int num_processes = 0;
    ProcessInfo process_list[MAX_PROCESS_LIST_SIZE];
    FILE* fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        return EXIT_FAILURE;
    }

    fseek(fp, 0L, SEEK_SET); // Rewind the file pointer to the beginning

    while(1) {
        char line[256];
        if (fgets(line, 256, fp) == NULL) {
            break;
        }

        if (strncmp(line, "cpu ", 4) == 0) {
            // This is the line that contains the CPU usage information
            char* tok = strtok(line, " ");
            double total_cpu_time = 0;

            for (int i = 0; i < 10; i++) {
                tok = strtok(NULL, " ");
                total_cpu_time += atof(tok);
            }

            usleep(500000); // Wait for 500ms to measure the CPU usage over a period of time

            fseek(fp, 0L, SEEK_SET); // Rewind the file pointer to the beginning

            double new_cpu_time = 0;
            double user_time, syst_time;

            while(1) {
                if (fgets(line, 256, fp) == NULL) {
                    break;
                }

                if (strncmp(line, "cpu ", 4) == 0) {
                    char* tok = strtok(line, " ");

                    for (int i = 0; i < 10; i++) {
                        tok = strtok(NULL, " ");
                        new_cpu_time += atof(tok);
                    }

                    user_time = atof(strtok(NULL, " "));
                    syst_time = atof(strtok(NULL, " "));
                    break;
                }
            }

            double cpu_usage = (new_cpu_time - total_cpu_time) / ((user_time + syst_time + new_cpu_time - total_cpu_time) * 1.0);

            printf("CPU Usage: %.2lf%%\n", cpu_usage * 100.0);
        }
        else if (strncmp(line, "processes ", 10) == 0) {
            // This is the line that contains the number of currently running processes
            num_processes = atoi(strtok(line, " "));

            break;
        }
    }

    fclose(fp);

    // Iterate through all the running processes and get their CPU usage
    for (int pid = 1; pid <= num_processes; pid++) {
        char filename[32];
        sprintf(filename, "/proc/%d/stat", pid);
        fp = fopen(filename, "r");

        if (fp == NULL) {
            continue;
        }

        char cmdline_filename[32];
        sprintf(cmdline_filename, "/proc/%d/cmdline", pid);
        FILE* cmdline_fp = fopen(cmdline_filename, "r");
        char process_name[MAX_PROCESS_NAME_LENGTH] = "UNKNOWN";

        if (cmdline_fp != NULL) {
            fgets(process_name, MAX_PROCESS_NAME_LENGTH, cmdline_fp);
            fclose(cmdline_fp);
        }

        ProcessInfo* process_info = &process_list[pid - 1];
        process_info->pid = pid;
        strncpy(process_info->name, process_name, MAX_PROCESS_NAME_LENGTH);

        char line[256];
        if (fgets(line, 256, fp) != NULL) {
            char* tok = strtok(line, " ");
            for (int i = 0; i < 13; i++) {
                tok = strtok(NULL, " ");
            }

            double utime = atof(tok);

            for (int i = 0; i < 4; i++) {
                tok = strtok(NULL, " ");
            }

            double stime = atof(tok);

            double cpu_time = utime + stime;
            double elapsed_time = sysconf(_SC_CLK_TCK) * 1.0;

            usleep(100000); // Wait for 100ms to measure the CPU usage over a period of time

            fseek(fp, 0L, SEEK_SET); // Rewind the file pointer to the beginning

            if (fgets(line, 256, fp) != NULL) {
                tok = strtok(line, " ");
                for (int i = 0; i < 13; i++) {
                    tok = strtok(NULL, " ");
                }

                double new_utime = atof(tok);

                for (int i = 0; i < 4; i++) {
                    tok = strtok(NULL, " ");
                }

                double new_stime = atof(tok);

                double new_cpu_time = new_utime + new_stime;
                double new_elapsed_time = sysconf(_SC_CLK_TCK) * 1.0;

                process_info->cpu_usage = (new_cpu_time - cpu_time) / (new_elapsed_time - elapsed_time);
            }
        }

        fclose(fp);
    }

    qsort(process_list, num_processes, sizeof(ProcessInfo), compare_process_info);

    printf(" PID\t    PROCESS NAME\t\tCPU USAGE\n");

    for (int i = 0; i < num_processes; i++) {
        ProcessInfo* process_info = &process_list[i];

        printf("%5d\t%17s\t\t%.2lf%%\n", process_info->pid, process_info->name, process_info->cpu_usage * 100.0);
    }

    return EXIT_SUCCESS;
}