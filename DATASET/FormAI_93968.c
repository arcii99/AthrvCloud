//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    char command[1024];
    char time_str[128];
    time_t rawtime;
    struct tm * timeinfo;

    /* Set the system time */
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);
    sprintf(command, "date --set='%s'", time_str);
    system(command);
    printf("System time set to: %s\n", time_str);

    /* Display system uptime */
    sprintf(command, "uptime");
    printf("System uptime: ");
    system(command);

    /* Display system load average */
    sprintf(command, "cat /proc/loadavg");
    printf("System load average: ");
    system(command);

    /* List all running processes */
    sprintf(command, "ps -ef");
    printf("Running processes: ");
    system(command);

    /* Display system disk space usage */
    sprintf(command, "df -h");
    printf("Disk space usage: ");
    system(command);

    /* Display system memory usage */
    sprintf(command, "free -m");
    printf("Memory usage: ");
    system(command);

    /* Display system network interface information */
    sprintf(command, "ifconfig -a");
    printf("Network interface information: ");
    system(command);

    /* Set the hostname */
    sprintf(command, "hostname");
    printf("Current hostname: ");
    system(command);
    sprintf(command, "echo 'NewHostname' > /etc/hostname");
    system(command);
    sprintf(command, "hostname -F /etc/hostname");
    system(command);
    sprintf(command, "hostname");
    printf("New hostname: ");
    system(command);

    return 0;
}