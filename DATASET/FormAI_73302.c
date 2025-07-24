//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function calculates the internet speed
float calculate_speed(int download_speed, int upload_speed) {
    float speed;
    speed = ((float) download_speed / (float) upload_speed) * 100.0;
    return speed;
}

int main() {
    int download_speed, upload_speed;
    
    // Randomly generate download and upload speed values
    srand(time(0));
    download_speed = rand() % 100 + 1;
    upload_speed = rand() % 100 + 1;
    
    // Display the download and upload speed values
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);
    
    // Call the function to calculate the internet speed
    float speed = calculate_speed(download_speed, upload_speed);
    
    // Display the internet speed value
    printf("Your internet speed is: %0.2f Mbps\n", speed);
    
    return 0;
}