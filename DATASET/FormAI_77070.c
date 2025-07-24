//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double cal_speed(int download_time) {
    /* Calculation for internet speed in Mbps */
    double speed = 100.0 / download_time;

    return speed;
}

int main() {
    /* Welcome message */
    printf("Welcome to Internet Speed Test Application!\n\n");

    /* Variable declaration */
    time_t start, end;
    int download_time;
    double speed;

    /* Start timer */
    time(&start);

    /* Simulating download time */
    srand(time(0));
    int random_num = (rand() % 5) + 1;
    sleep(random_num);

    /* End timer */
    time(&end);

    /* Calculate download time */
    download_time = difftime(end, start);

    /* Calculate internet speed */
    speed = cal_speed(download_time);

    /* Display result */
    printf("Download Time: %d seconds\n", download_time);
    printf("Internet Speed: %.2f Mbps\n", speed);

    return 0;
}