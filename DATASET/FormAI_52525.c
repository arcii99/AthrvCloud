//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
    long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];
    
    for(;;){
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
        fclose(fp);
        sleep(1);
        
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
        fclose(fp);
        
        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
        loadavg *= 100;
        
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("%02d:%02d:%02d CPU Usage: %.2Lf%%\n", t->tm_hour, t->tm_min, t->tm_sec, loadavg);
    }
    
    return 0;
}