//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_speed() {
    int speed_limit = 100; // set the maximum speed limit as 100 Mbps
    int speed = 0;
    int time_taken = 0;
    time_t start_time, end_time;
    double diff;

    start_time = time(NULL); // get the current time in seconds

    // download a file of size 100 MB to test internet speed
    system("wget -O /dev/null http://speedtest.dal01.softlayer.com/downloads/test100.zip");

    end_time = time(NULL); // get the time when the download completes
    diff = difftime(end_time, start_time);

    time_taken = (int) diff; // calculate the time taken to download the file in seconds

    if (time_taken == 0) {
        // if time taken is less than 1 second, set it to 1 second to avoid division by zero
        time_taken = 1;
    }

    speed = (100 / time_taken) * 8; // calculate the internet speed in Mbps

    if (speed > speed_limit) {
        return speed_limit; // if speed is greater than maximum speed limit, return maximum speed limit
    } else {
        return speed; // otherwise return the actual speed
    }
}

int main() {
    int speed = test_speed();

    printf("Your internet speed is %d Mbps.\n", speed);

    return 0;
}