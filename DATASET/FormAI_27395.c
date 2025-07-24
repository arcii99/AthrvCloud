//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

float cpu_usage(unsigned long long int idle_time, unsigned long long int total_time){
    static unsigned long long int prev_idle_time = 0;
    static unsigned long long int prev_total_time = 0;
    float usage_percent = 0;

    unsigned long long int diff_idle = idle_time - prev_idle_time;
    unsigned long long int diff_total = total_time - prev_total_time;

    usage_percent = (float)(100*(diff_total - diff_idle)) / diff_total;

    prev_idle_time = idle_time;
    prev_total_time = total_time;

    return usage_percent;
}

void recursive_cpu_usage(){
    FILE* fp = NULL;
    unsigned long long int idle_time = 0, total_time = 0;
    char buffer[1024] = {0};
    int count = 0;

    if((fp = fopen("/proc/stat", "r")) == NULL){
        perror("Unable to open file /proc/stat");
        exit(-1);
    }

    fgets(buffer, sizeof(buffer), fp);

    while(buffer[count] != ' ') count++;

    count++;

    while(buffer[count] != ' '){
        idle_time = idle_time * 10 + buffer[count] - '0'; count++;
    }

    for(int i = 0; i < 3; i++){
        while(buffer[count] != ' ') count++;
        count++;
        while(buffer[count] != ' ') total_time = total_time * 10 + buffer[count++] - '0';   
    }

    printf("CPU Usage: %.2f %c \r", cpu_usage(idle_time, total_time), '%');

    fclose(fp);

    sleep(1);

    recursive_cpu_usage();
}

int main(){
    recursive_cpu_usage();
    return 0;
}