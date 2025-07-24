//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

struct internet_speed {
    float download_speed;
    float upload_speed;
};

struct internet_speed test_internet_speed() {
    sleep(5); // wait for 5 seconds to get accurate results
    
    // generate random download and upload speeds within a certain range
    float download_speed = ((float)rand()/(float)(RAND_MAX)) * (100 - 40) + 40;
    float upload_speed = ((float)rand()/(float)(RAND_MAX)) * (50 - 10) + 10;
    
    struct internet_speed speed;
    speed.download_speed = download_speed;
    speed.upload_speed = upload_speed;
    
    return speed;
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    printf("--- Internet Speed Test ---\n");
    printf("This program will test your internet speed by measuring your download and upload speeds.\n\n");
    
    printf("Press enter to begin the test...");
    getchar(); // wait for user to press enter
    
    printf("\nTesting download speed...");
    struct internet_speed speed = test_internet_speed();
    printf("\nDownload speed: %.2f Mbps", speed.download_speed);
    
    printf("\n\nTesting upload speed...");
    speed = test_internet_speed();
    printf("\nUpload speed: %.2f Mbps", speed.upload_speed);
    
    printf("\n\nSpeed test complete!\n");
    
    return 0;
}