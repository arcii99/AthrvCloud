//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int cpu_usage = 0;

void handle_signal(int sig){
    if(sig == SIGINT){
       printf("\nCPU usage monitor stopped.\n");
       exit(0);
    }
}

int read_cpu_usage(){
    char cpu_info[100];
    int cpu_total, cpu_idle;
    int fd = open("/proc/stat", O_RDONLY);
    if(fd == -1){
        perror("Error opening /proc/stat");
        exit(1);
    }
    read(fd, cpu_info, sizeof(cpu_info));
    close(fd);
    sscanf(cpu_info, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %d %d", &cpu_idle, &cpu_total);
    return (100 - (cpu_idle*100/cpu_total));
}

int main(){
    printf("CPU usage monitor started.\n");
    printf("Press CTRL+C to stop.\n");
    signal(SIGINT, handle_signal);
    while(1){
        cpu_usage = read_cpu_usage();
        printf("CPU usage: %d%% \n", cpu_usage);
        sleep(1);
    }
    return 0;
}