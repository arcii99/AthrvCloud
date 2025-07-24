//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

/*
 * A simple CPU usage monitor example program
 * that displays CPU usage every second
 */

int main()
{
    long double a[4], b[4];
    FILE *fp;
    char dump[50];
    const char* cmd = "cat /proc/stat | grep 'cpu '";
    unsigned int cpu_usage;

    while(1){
        fp = popen(cmd,"r");
        fgets(dump, sizeof(dump), fp);
        sscanf(dump,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        pclose(fp);
        sleep(1);
        fp = popen(cmd,"r");
        fgets(dump, sizeof(dump), fp);
        sscanf(dump,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        pclose(fp);

        cpu_usage = (unsigned int)((b[0]+b[1]+b[2]-a[0]-a[1]-a[2])/(b[0]+b[1]+b[2]+b[3]-a[0]-a[1]-a[2]-a[3]) * 100);

        printf("CPU Usage: %d%%\n",cpu_usage);
    }

    return 0;
}