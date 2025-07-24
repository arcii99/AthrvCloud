//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <unistd.h>

void calculateCPU(){
    FILE* fp = fopen("/proc/stat","r");
    char cpu_line[128];
    int cpu_fields[10];
    int cpu_time_sum = 0;

    //read first line of cpu stats
    fgets(cpu_line,sizeof(cpu_line),fp);
    sscanf(cpu_line,"%*s %d %d %d %d %d %d %d %d %d %d",
           &cpu_fields[0],&cpu_fields[1],&cpu_fields[2],&cpu_fields[3],&cpu_fields[4],
           &cpu_fields[5],&cpu_fields[6],&cpu_fields[7],&cpu_fields[8],&cpu_fields[9]);
    
    for(int i = 0; i < 10;i++){
        cpu_time_sum += cpu_fields[i];
    }
    
    sleep(2);
    fseek(fp,0,SEEK_SET);

    fgets(cpu_line,sizeof(cpu_line),fp);
    sscanf(cpu_line,"%*s %d %d %d %d %d %d %d %d %d %d",
           &cpu_fields[0],&cpu_fields[1],&cpu_fields[2],&cpu_fields[3],&cpu_fields[4],
           &cpu_fields[5],&cpu_fields[6],&cpu_fields[7],&cpu_fields[8],&cpu_fields[9]);

    int cpu_diff_sum = 0;
    for(int i = 0; i < 10;i++){
        cpu_diff_sum += (cpu_fields[i]-cpu_time_sum);
    }
    double cpu_usage = 100.0 * ((double)cpu_diff_sum/cpu_time_sum);    
    
    printf("Current CPU usage: %3.2f%%\n", cpu_usage);
    fclose(fp);
    calculateCPU();
}

int main(){
    calculateCPU();
    return 0;
}