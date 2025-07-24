//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/sysinfo.h>
#include <pthread.h>

//global variables
int running = 1; 
int interval = 1; // default interval for updates in seconds
int max_cpu; // maximum cpu usage allowed in percentage

// Function that runs in a separate thread to monitor CPU usage
void *cpu_monitor(void *arg) {
    while (running) {
        FILE *fp;
        char path[1024];

        long double a[4], b[4], loadavg;
        fp = fopen("/proc/stat","r");

        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        fclose(fp);
        sleep(interval);

        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3])) * 100;
        
        if (loadavg > max_cpu) {
            printf("CPU usage exceeded %d%%. Terminating.\n", max_cpu);
            exit(1);
        }
    }
    return NULL;
}

// Function that runs in a separate thread to monitor RAM usage
void *ram_monitor(void *arg) {
    while (running) {
        struct sysinfo info;
        sysinfo(&info);

        long total_mem = info.totalram * info.mem_unit / 1024;
        long free_mem = info.freeram * info.mem_unit / 1024;

        int ram_usage = (total_mem - free_mem) * 100 / total_mem;

        printf("RAM usage is %d%%\n", ram_usage);

        sleep(interval);
    }
    return NULL;
}

// Function to handle termination signals
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nReceived SIGINT. Terminating.\n");
        running = 0;
    }
}

int main(int argc, char *argv[]) {
    // set default maximum CPU usage to 80%
    max_cpu = 80;
  
    // parse command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "hi:m:")) != -1) {
        switch(opt) {
            case 'h':
                printf("Usage: %s [-h] [-i <interval>] [-m <max_cpu>]\n", argv[0]);
                printf("-h: display this help message\n");
                printf("-i <interval>: set update interval in seconds (default: 1)\n");
                printf("-m <max_cpu>: set maximum allowed CPU usage in percentage (default: 80)\n");
                exit(0);
                break;
            case 'i':
                interval = atoi(optarg);
                break;
            case 'm':
                max_cpu = atoi(optarg);
                break;
            default:
                printf("Usage: %s [-h] [-i <interval>] [-m <max_cpu>]\n", argv[0]);
                exit(1);
                break;
        }
    }

    // register signal handler for termination signals
    signal(SIGINT, sig_handler);

    // create threads to monitor CPU and RAM usage
    pthread_t cpu_thread, ram_thread;
    pthread_create(&cpu_thread, NULL, cpu_monitor, NULL);
    pthread_create(&ram_thread, NULL, ram_monitor, NULL);

    // wait for threads to finish
    pthread_join(cpu_thread, NULL);
    pthread_join(ram_thread, NULL);

    return 0;
}