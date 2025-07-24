//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int rand_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate Internet speed
float calculate_speed(float time) {
    float speed, file_size = 100.0; // 100MB file size assumed
    speed = (file_size / time) * 8.0; // In Megabits per second
    return speed;
}

int main() {
    srand(time(NULL)); // Initializing random seed
    float time_taken;
    int download_speed, upload_speed, ping;
    printf("Welcome to the Internet Speed Test Application\n\n");
    // Generating random download speed, upload speed and ping values
    download_speed = rand_num(5, 100);
    upload_speed = rand_num(3, 50);
    ping = rand_num(1, 20);
    printf("Testing download speed: %d Mbps\n", download_speed);
    printf("Testing upload speed: %d Mbps\n", upload_speed);
    printf("Testing ping: %d ms\n\n", ping);
    printf("Press any key to start test...");
    getchar();
    printf("Testing...\n");
    // Generating random time for download and upload tests
    time_taken = rand_num(10, 40) + (float)rand_num(0, 9) / 10.0;
    printf("Download test completed in %.1f seconds\n", time_taken);
    printf("Calculating download speed...\n");
    float download = calculate_speed(time_taken);
    printf("Download speed: %.2f Mbps\n\n", download);
    time_taken = rand_num(10, 40) + (float)rand_num(0, 9) / 10.0;
    printf("Upload test completed in %.1f seconds\n", time_taken);
    printf("Calculating upload speed...\n");
    float upload = calculate_speed(time_taken);
    printf("Upload speed: %.2f Mbps\n\n", upload);
    printf("Ping test completed in %d ms\n\n", ping);
    printf("Test completed!\n");
    return 0;
}