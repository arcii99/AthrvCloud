//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    long double idle, totalPrev, total, usage;
    
    while(1) {
        fp = fopen("/proc/stat", "r");
        fgets(buffer, BUFFER_SIZE, fp);
        fclose(fp);
        
        int n = sscanf(buffer, "cpu %Lf %Lf %Lf %Lf", &totalPrev, &idle, &total, &usage);
        if (n < 4) {
            printf("Error: Unable to read CPU usage.\n");
            continue;
        }
        
        sleep(1);
        
        fp = fopen("/proc/stat", "r");
        fgets(buffer, BUFFER_SIZE, fp);
        fclose(fp);
        
        n = sscanf(buffer, "cpu %Lf %Lf %Lf %Lf", &total, &idle, &total, &usage);
        if (n < 4) {
            printf("Error: Unable to read CPU usage.\n");
            continue;
        }
        
        long double diff = (total + idle) - (totalPrev + idle);
        long double usagePercent = 100.0 * (diff - (total - totalPrev)) / diff;
        
        printf("\rCPU Usage | %.2Lf%%", usagePercent);
        fflush(stdout);
    }
    
    return 0;
}