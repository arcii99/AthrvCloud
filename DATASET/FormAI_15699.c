//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int speed_test() {
    // initialize variables
    int download_speed, upload_speed;
    // generate random download speed between 1-100 Mbps
    download_speed = rand() % 100 + 1;
    // generate random upload speed between 1-50 Mbps
    upload_speed = rand() % 50 + 1;
    // display results to user
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed); 
    // determine if speeds meet user's expectations
    if (download_speed >= 50 && upload_speed >= 25) {
        printf("Congratulations! Your internet speeds meet or exceed the recommended minimums.\n");
    } else {
        printf("Warning! Your internet speeds do not meet the recommended minimums.\n");
    }
    return 0;
}

int main() {
    // seed random number generator with current time
    srand(time(NULL));
    // call speed_test function
    speed_test();
    return 0;
}