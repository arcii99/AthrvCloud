//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024 // buffer size for reading /proc/stat file
#define NUM_CORES 4   // number of cores in the cpu

int main()
{
    int fd;  // file descriptor for opening /proc/stat file
    char buf[BUF_SIZE];  // buffer for reading from /proc/stat
    long double a[NUM_CORES][10], b[NUM_CORES][10], loadavg;  // arrays to store cpu usage and load average data
    char cpu_name[5] = "cpu" ; // cpu name identifier in /proc/stat
    char *cpu;  // pointer to identify cpu name in /proc/stat file
    char *tok;  // pointer to identify individual tokens in /proc/stat file
    int i, j, k;
    int count = 0; // number of times cpu usage data is measured

    // Print header
    printf("CPU MONITOR - Press CTRL+C to Stop\n");
    printf("%-10s%-10s%-10s%-10s\n","CORE","USER(%)","NICE(%)","SYS(%)","IDLE(%)");

    // Open /proc/stat file
    fd = open("/proc/stat", O_RDONLY);
    if(fd == -1)
    {
        perror("Cannot open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read /proc/stat file and store the data in arrays a and b
    lseek(fd, 0, SEEK_SET);
    while(1)
    {
        read(fd, buf, BUF_SIZE);
        cpu = strtok(buf, "\n");
        while(cpu != NULL)
        {
            if(strncmp(cpu, cpu_name, 3) == 0)
            {
                tok = strtok(cpu, " ");
                j = 0;
                while(tok != NULL && j < 10)
                {
                    tok = strtok(NULL, " ");
                    a[count][j++] = atoi(tok);
                }
            }
            cpu = strtok(NULL, "\n");
        }
        count++;
        if(count == 2)  // read the cpu usage data twice to calculate the usage
            break;
    }

    // Close /proc/stat file
    close(fd);

    // Calculate the cpu usage for each core
    for(i=0; i<NUM_CORES; i++)
    {
        for(j=0; j<10; j++)
            b[i][j] = a[i][j];
    }
    sleep(1);  // sleep for 1 second to get new cpu usage data
    count = 0;
    fd = open("/proc/stat", O_RDONLY);
    if(fd == -1)
    {
        perror("Cannot open /proc/stat");
        exit(EXIT_FAILURE);
    }
    lseek(fd, 0, SEEK_SET);
    while(1)
    {
        read(fd, buf, BUF_SIZE);
        cpu = strtok(buf, "\n");
        while(cpu != NULL)
        {
            if(strncmp(cpu, cpu_name, 3) == 0)
            {
                tok = strtok(cpu, " ");
                j = 0;
                while(tok != NULL && j < 10)
                {
                    tok = strtok(NULL, " ");
                    b[count][j++] = atoi(tok);
                }
            }
            cpu = strtok(NULL, "\n");
        }
        count++;
        if(count == 2)
            break;
    }
    close(fd);

    // Print the cpu usage for each core
    for(i=0; i<NUM_CORES; i++)
    {
        long double user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
        user = b[i][0]-a[i][0];
        nice = b[i][1]-a[i][1];
        sys = b[i][2]-a[i][2];
        idle = b[i][3]-a[i][3];
        iowait = b[i][4]-a[i][4];
        irq = b[i][5]-a[i][5];
        softirq = b[i][6]-a[i][6];
        steal = b[i][7]-a[i][7];
        guest = b[i][8]-a[i][8];
        guest_nice = b[i][9]-a[i][9];
        loadavg = (user + nice + sys + idle + iowait + irq + softirq + steal + guest + guest_nice); // total cpu usage time
        user = (user/loadavg)*100; // percentage of time spent in user mode
        nice = (nice/loadavg)*100; // percentage of time spent in user mode with priority
        sys = (sys/loadavg)*100; // percentage of time spent in system mode
        idle = (idle/loadavg)*100; // percentage of idle time
        printf("%-10d%-10Lf%-10Lf%-10Lf%-10Lf\n", i, user, nice, sys, idle);
    }

    // Calculate and print overall load average
    loadavg = (b[0][0]+b[0][1]+b[0][2]+b[0][3]+b[0][4]+b[0][5]+b[0][6]+b[0][7]+b[0][8]+b[0][9]) - (a[0][0]+a[0][1]+a[0][2]+a[0][3]+a[0][4]+a[0][5]+a[0][6]+a[0][7]+a[0][8]+a[0][9]);
    loadavg = loadavg/10;
    printf("\nLoad Average: %Lf\n", loadavg);
    return 0;
}