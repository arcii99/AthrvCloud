//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed, count = 1, time_elapsed = 0;
    double distance = 0;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please enter the speed at which you think you can download information (in MB/s): ");
    scanf("%d", &speed);

    printf("Starting Test...");

    while (distance < 500) {
        printf(".");
        fflush(stdout);
        srand(time(NULL));

        int random_speed = rand() % 10 + (speed - 5);
        double distance_travelled = random_speed * 0.5;
        distance += distance_travelled;
        time_elapsed += 1;

        if (count % 10 == 0) {
            printf("\nYour current download speed is %.2f MB/s\n", random_speed);
        }

        count++;
    }

    printf("\nTest Complete!\n");

    if (time_elapsed <= 10) {
        printf("Your internet speed is lightning fast at %.2f MB/s!\n", speed);
    } else if (time_elapsed <= 20) {
        printf("Your internet speed is decent at %.2f MB/s.\n", (distance / (time_elapsed * 0.5)));
    } else {
        printf("Your internet speed is slow at %.2f MB/s. Contact your internet service provider.\n", (distance / (time_elapsed * 0.5)));
    }

    return 0;
}