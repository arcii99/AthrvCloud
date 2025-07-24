//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed = 0;
    int delay = 0;
    int size = 1000000000;

    printf("Welcome to the Mind-Bending Internet Speed Test!\n");
    printf("Your connection speed will now be determined...\n\n");

    srand(time(NULL));
    speed = (rand() % 100) + 1;

    printf("Your connection speed is %d Mbps.\n", speed);

    delay = 1000000 / speed;

    printf("Preparing to test speed by downloading %d bytes...\n", size);

    int start_time = clock();

    for (int i = 0; i < size; i++) {
        // Simulate download by adding delay
        for (int j = 0; j < delay; j++) {}
    }

    int end_time = clock();
    double download_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Download completed in %.2lf seconds.\n", download_time);
    printf("Your download speed is %.2lf Mbps.\n", (double)(size / download_time * 8) / 1000000);

    return 0;
}