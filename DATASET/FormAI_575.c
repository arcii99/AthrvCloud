//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main () {

    int download_speed, upload_speed, ping;

    printf("Welcome to the Internet Speed Test Application!\n");

    // Simulating download speed test
    printf("Running download speed test...\n");

    // Simulating download speed test by generating random number between 10 and 100 (Mbps)
    srand(time(0));
    download_speed = (rand() % 91) + 10;
    printf("Download speed test complete. Your download speed is %d Mbps.\n", download_speed);

    sleep(1);

    // Simulating upload speed test
    printf("Running upload speed test...\n");

    // Simulating upload speed test by generating random number between 2 and 20 (Mbps)
    upload_speed = (rand() % 19) + 2;
    printf("Upload speed test complete. Your upload speed is %d Mbps.\n", upload_speed);

    sleep(1);

    // Simulating ping test
    printf("Running ping test...\n");

    // Simulating ping test by generating random number between 10 and 100 (ms)
    ping = (rand() % 91) + 10;
    printf("Ping test complete. Your ping is %d ms.\n", ping);

    return 0;
}