//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int i, j, k;
    long long speed;
    printf("Starting internet speed test...\n\n");

    // Generate random sample data
    srand(time(NULL));
    int samples[10000];
    for(i = 0; i < 10000; i++) {
        samples[i] = rand() % 1000;
    }

    // Shuffle sample data randomly
    for(i = 0; i < 10000; i++) {
        j = rand() % 10000;
        k = rand() % 10000;
        int temp = samples[j];
        samples[j] = samples[k];
        samples[k] = temp;
    }

    // Measure download speed
    printf("Measuring download speed...\n");
    clock_t start = clock();
    for(i = 0; i < 10000; i++) {
        sleep(1);
        speed += samples[i];
    }
    clock_t end = clock();
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    double download_speed = (double) speed / time_elapsed;
    printf("Download speed: %lf KBps\n", download_speed);

    // Shuffle sample data again
    for(i = 0; i < 10000; i++) {
        j = rand() % 10000;
        k = rand() % 10000;
        int temp = samples[j];
        samples[j] = samples[k];
        samples[k] = temp;
    }

    // Measure upload speed
    printf("\nMeasuring upload speed...\n");
    start = clock();
    for(i = 0; i < 10000; i++) {
        sleep(1);
        speed += samples[i];
    }
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    double upload_speed = (double) speed / time_elapsed;
    printf("Upload speed: %lf KBps\n", upload_speed);

    // Check if speeds are suspiciously low
    if(download_speed < 5) {
        printf("\nWarning: download speed is suspiciously low. Possible ISP throttling or network issues.\n");
    }
    if(upload_speed < 0.5) {
        printf("\nWarning: upload speed is suspiciously low. Possible ISP throttling or network issues.\n");
    }

    printf("\nSpeed test complete.\n");
    return 0;
}