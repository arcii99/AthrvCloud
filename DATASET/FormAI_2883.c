//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red_time = 10, yellow_time = 2, green_time = 10;
    int i, j;

    printf("\n Traffic Light Control Program\n");

    while(1) {

        printf("\n\nRED LIGHT\n");

        for(i=0; i<red_time; i++) {
            for(j=0; j<60; j++) {
                printf("\rTime Left : %02d:%02d", red_time-i-1, 59-j);
                fflush(stdout);
                sleep(1);
            }
        }

        printf("\n\nYELLOW LIGHT\n");

        for(i=0; i<yellow_time; i++) {
            for(j=0; j<60; j++) {
                printf("\rTime Left : %02d:%02d", yellow_time-i-1, 59-j);
                fflush(stdout);
                sleep(1);
            }
        }

        printf("\n\nGREEN LIGHT\n");

        for(i=0; i<green_time; i++) {
            for(j=0; j<60; j++) {
                printf("\rTime Left : %02d:%02d", green_time-i-1, 59-j);
                fflush(stdout);
                sleep(1);
            }
        }
    }
    return 0;
}