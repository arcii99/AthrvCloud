//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[]) {
    long interval = 1; // default check interval in seconds
    int pid = -1; // default PID to monitor all processes
    int opt;

    // read command-line options
    while ((opt = getopt(argc, argv, "i:p:")) != -1) {
        switch (opt) {
        case 'i':
            interval = atoi(optarg);
            break;
        case 'p':
            pid = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s [-i interval] [-p pid]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    // print header
    printf("%5s %9s %6s %10s %10s %s\n", "PID", "COMMAND", "RSS", "SWAP", "CPU", "TIME");

    // main loop
    for (;;) {
        // get system info
        struct sysinfo si;
        if (sysinfo(&si) < 0) {
            fprintf(stderr, "Failed to get system info\n");
            exit(EXIT_FAILURE);
        }

        // get process info
        char pid_path[256];
        char cmd_path[256];
        char line[1024];
        FILE *fp;

        if (pid == -1) {
            // monitor all processes
            fp = fopen("/proc/meminfo", "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open /proc/meminfo\n");
                exit(EXIT_FAILURE);
            }

            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "Pid:", 4) == 0) {
                    pid = atoi(line+4);
                    break;
                }
            }

            fclose(fp);
        }

        snprintf(pid_path, sizeof(pid_path), "/proc/%d/status", pid);
        snprintf(cmd_path, sizeof(cmd_path), "/proc/%d/cmdline", pid);

        fp = fopen(cmd_path, "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open %s\n", cmd_path);
            exit(EXIT_FAILURE);
        }
        fgets(line, sizeof(line), fp);
        fclose(fp);

        fp = fopen(pid_path, "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open %s\n", pid_path);
            exit(EXIT_FAILURE);
        }

        char command[256];
        int rss = 0;
        int swap = 0;
        int cpu = 0;
        int utime = 0;
        int stime = 0;
        int cutime = 0;
        int cstime = 0;

        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "Name:", 5) == 0) {
                strncpy(command, line+6, sizeof(command)-1);
                command[sizeof(command)-1] = '\0';
            } else if (strncmp(line, "VmRSS:", 6) == 0) {
                rss = atoi(line+6);
            } else if (strncmp(line, "VmSwap:", 7) == 0) {
                swap = atoi(line+7);
            } else if (strncmp(line, "utime:", 6) == 0) {
                utime = atoi(line+6);
            } else if (strncmp(line, "stime:", 6) == 0) {
                stime = atoi(line+6);
            } else if (strncmp(line, "cutime:", 7) == 0) {
                cutime = atoi(line+7);
            } else if (strncmp(line, "cstime:", 7) == 0) {
                cstime = atoi(line+7);
            }
        }

        fclose(fp);

        // compute CPU usage
        static int last_utime = -1;
        static int last_stime = -1;
        static int last_cutime = -1;
        static int last_cstime = -1;

        int total_time = utime + stime + cutime + cstime;
        int elapsed_time = sysconf(_SC_CLK_TCK) * (si.uptime - last_utime);

        int cpu_usage = (total_time - last_utime - last_stime - last_cutime - last_cstime) * 100 / elapsed_time;

        last_utime = utime;
        last_stime = stime;
        last_cutime = cutime;
        last_cstime = cstime;

        // print info
        printf("%5d %9s %6d %10d %10d %d:%02d:%02d\n", pid, command, rss, swap, cpu_usage, si.uptime/3600, (si.uptime/60)%60, si.uptime%60);

        // wait for the specified interval
        sleep(interval);
    }

    return 0;
}