//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){

    FILE *fptr;
    char buf[128], *tok;
    long double user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice, cpu_total1, cpu_total2, cpu_used;
    time_t t;

    fptr = fopen("/proc/stat","r");

    while(1){
        // clear screen
        system("clear");

        // get current time
        t = time(NULL);
        printf("Time: %s", ctime(&t));

        // read from /proc/stat file
        if(fscanf(fptr,"%s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           buf, &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice ) == EOF){
            printf("Error while reading /proc/stat file");
            exit(EXIT_FAILURE);
        }

        // calculate total CPU usage
        cpu_total1 = user+nice+sys+idle+iowait+irq+softirq+steal+guest+guest_nice;
        usleep(100000); // sleep for 100ms
        fseek(fptr, 0, SEEK_SET); // go to start of file
        if(fscanf(fptr,"%s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",
           buf, &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice ) == EOF){
            printf("Error while reading /proc/stat file");
            exit(EXIT_FAILURE);
        }
        cpu_total2 = user+nice+sys+idle+iowait+irq+softirq+steal+guest+guest_nice;
        cpu_used = 100*(cpu_total2-cpu_total1)/(cpu_total2);

        printf("CPU Usage: %Lf%%\n", cpu_used);
    }

    fclose(fptr);
    return 0;
}