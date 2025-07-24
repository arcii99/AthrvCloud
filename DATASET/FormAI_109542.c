//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MB 1024 * 1024
#define SEC_PER_MS 1000
#define BUFFER_SIZE 10 * MB // 10MB buffer size for download test

int main() {
    float download_speed = 0.0f;
    printf("C Internet Speed Test Application\n");

    // Test upload speed
    clock_t start_time = clock();
    printf("Testing upload speed...\n");
    
    // Simulating a file upload by delaying for 1 second
    sleep(1);
    clock_t end_time = clock();
    
    float upload_speed = (float) CLOCKS_PER_SEC / (float) (end_time - start_time);
    printf("Upload Speed: %.2f kbps\n", upload_speed);

    // Test download speed
    srand(time(0)); // Seed random number generator for random data generation
    char* data = (char*) malloc(BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = rand() % 256; // Generate random data
    }

    printf("Testing download speed...\n");
    start_time = clock();
    // Simulating a file download by copying the randomly generated data to another buffer
    char* buffer = (char*) malloc(BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = data[i];
    }
    end_time = clock();

    download_speed = ((float) (BUFFER_SIZE / SEC_PER_MS)) / ((float) (end_time - start_time));
    printf("Download Speed: %.2f Mbps\n", download_speed);

    free(data);
    free(buffer);
    return 0;
}