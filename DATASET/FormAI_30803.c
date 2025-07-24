//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int temp = 0;
    FILE *fp;
    char path[50];

    while(1) {
        fp = popen("cat /sys/class/thermal/thermal_zone0/temp", "r");
        if (fp == NULL) {
            printf("Error: Failed to get temperature\n" );
            exit(1);
        }
        fgets(path, sizeof(path), fp);
        temp = atoi(path)/1000;
        pclose(fp);

        if (temp >= 80) {
            printf("Temperature is at %dC! Cooling needed!\n", temp);
            // Fan or Cooling action can be taken here
        } else {
            printf("Temperature is at %dC\n", temp);
        }

        sleep(5);
    }

    return 0;
}