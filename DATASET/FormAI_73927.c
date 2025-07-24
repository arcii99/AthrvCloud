//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_servers, i, j;
    float max_uptime;
    printf("Welcome to the Website Uptime Monitor!\n\n");
    printf("Please enter the number of servers you wish to monitor:\n");
    scanf("%d", &num_servers);
    printf("Please enter the maximum uptime you would like to set (in decimal format):\n");
    scanf("%f", &max_uptime);
    
    float uptime[num_servers];
    srand(time(0));
    
    for(i=0; i<num_servers; i++) {
        uptime[i] = (float)rand()/(float)(RAND_MAX/max_uptime);
    }
    
    printf("\nServer\tUptime\n");
    for(i=0; i<num_servers; i++) {
        printf("%d\t%.4f\n", i+1, uptime[i]);
    }
    
    printf("\n");
    for(i=0; i<num_servers; i++) {
        if(uptime[i] < max_uptime) {
            printf("***WARNING***\nServer %d has an uptime of only %.4f, which is below the maximum allowed uptime of %.4f!\n", i+1, uptime[i], max_uptime);
        }
    }
    
    return 0;
}