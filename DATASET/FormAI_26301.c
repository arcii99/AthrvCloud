//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set up random number generator
    srand(time(NULL));
    
    // generate download and upload speeds between 1-100 Mbps
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    
    // print out speeds to user
    printf("Your download speed is %d Mbps.\n", download_speed);
    printf("Your upload speed is %d Mbps.\n", upload_speed);
    
    // check if speeds are above average
    int download_above_avg = download_speed > 50;
    int upload_above_avg = upload_speed > 50;
    
    // print out results to user
    if (download_above_avg && upload_above_avg) {
        printf("Congratulations! Your internet speeds are above average.\n");
    } else if (download_above_avg) {
        printf("Your download speed is above average, but your upload speed is below average.\n");
    } else if (upload_above_avg) {
        printf("Your upload speed is above average, but your download speed is below average.\n");
    } else {
        printf("Unfortunately, both your download and upload speeds are below average.\n");
    }
    
    // end program
    return 0;
}