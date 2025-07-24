//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int uptime = 0;
    int rand_num;
    srand(time(0));
    
    printf("Enter the URL to monitor:\n");
    char url[100];
    scanf("%s", url);
    
    printf("Monitoring %s...\n", url);
    printf("Uptime: %d%%\n", uptime);
    
    while(1) {
        rand_num = rand() % 10;
        if(rand_num == 5) {
            printf("%s is down!\n", url);
            break;
        }
        else {
            uptime += 10;
            printf("Uptime: %d%%\n", uptime);
            sleep(1);
        }
    }
    
    printf("%s is back up!\n", url);
    printf("Uptime: %d%%\n", uptime);
    
    return 0;
}