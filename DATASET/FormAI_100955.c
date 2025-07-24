//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("Welcome to the Shocking Internet Speed Test Application\n\n");

    int download_speed = 0;
    int upload_speed = 0;
    int latency = 0;
    
    time_t start_time, end_time;
    printf("Press any key to start the test...\n");
    getchar();

    printf("\nTesting your download speed...\n");

    // Simulate download speed test by generating random number
    srand(time(NULL));
    start_time = time(NULL);
    for (int i = 0; i < 10; i++) {
        int speed = rand() % 100 + 1;
        printf("Downloading...%d Mbps\n", speed);
        download_speed += speed;
        sleep(1);
    }
    end_time = time(NULL);
    download_speed /= 10;
    printf("\nAverage download speed is %d Mbps\n", download_speed);

    printf("\nTesting your upload speed...\n");

    // Simulate upload speed test by generating random number
    srand(time(NULL));
    start_time = time(NULL);
    for (int i = 0; i < 10; i++) {
        int speed = rand() % 50 + 1;
        printf("Uploading...%d Mbps\n", speed);
        upload_speed += speed;
        sleep(1);
    }
    end_time = time(NULL);
    upload_speed /= 10;
    printf("\nAverage upload speed is %d Mbps\n", upload_speed);

    printf("\nTesting your latency...\n");

    // Simulate latency test by generating random number
    srand(time(NULL));
    start_time = time(NULL);
    for (int i = 0; i < 10; i++) {
        int latency_time = rand() % 200 + 1;
        printf("Pinging...%d ms\n", latency_time);
        latency += latency_time;
        sleep(1);
    }
    end_time = time(NULL);
    latency /= 10;
    printf("\nAverage latency is %d ms\n", latency);

    printf("\nThank you for using the Shocking Internet Speed Test Application!\n");

    return 0;
}