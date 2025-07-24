//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(0));
    int rand_num, red_time, yellow_time, green_time;

    printf("Welcome to the Happy Traffic Light Controller Program!\n\n");

    printf("Enter the duration time for the red light (in seconds): ");
    scanf("%d", &red_time);

    printf("Enter the duration time for the yellow light (in seconds): ");
    scanf("%d", &yellow_time);

    printf("Enter the duration time for the green light (in seconds): ");
    scanf("%d", &green_time);

    while(1) {
        printf("\nRED LIGHT\n");
        for(int i=red_time; i>0; i--) {
            printf("%d seconds remaining\n", i);
            sleep(1);
        }

        printf("\nYELLOW LIGHT\n");
        for(int i=yellow_time; i>0; i--) {
            printf("%d seconds remaining\n", i);
            sleep(1);
        }

        printf("\nGREEN LIGHT\n");
        for(int i=green_time; i>0; i--) {
            printf("%d seconds remaining\n", i);
            sleep(1);
        }
    }

    return 0;
}