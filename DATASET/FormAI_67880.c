//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main() {

    printf("******* CPU USAGE MONITOR *******\n\n");

    time_t t;

    for(int i=1; i<=10; i++) {

        FILE* fp = fopen("/proc/stat","r");
        char buff[255];
        fgets(buff,sizeof(buff),fp);

        int user, nice, sys, idle, iowait, irq, sirq;
        sscanf(buff,"%*s %d %d %d %d %d %d %d", &user, &nice, &sys, &idle, &iowait, &irq, &sirq);

        unsigned long int total_cpu_t = user + nice + sys + idle + iowait + irq + sirq;
        unsigned long int idle_cpu_t = idle + iowait;

        float cpu_rate = (float) (total_cpu_t - idle_cpu_t)*100 / total_cpu_t;

        time(&t);
        printf("Time: %sCPU Usage: %.2f %%\n",ctime(&t),cpu_rate);

        fclose(fp);

        sleep(1);
    }

    printf("\n**********END OF THE PROGRAM**********\n");

    return 0;
}