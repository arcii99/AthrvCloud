//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to measure internet speed
void measure_speed(){
    int download_speed, upload_speed;
    time_t start_time, end_time;
    double total_time, speed;
    printf("Measuring download speed...\n");
    start_time = time(NULL); // start timer
    // simulate downloading a file of size 10MB
    for(int i=0; i<10*1024*1024; i++){ 
        // do nothing
    }
    end_time = time(NULL); // end timer
    total_time = end_time - start_time;
    speed = (10 / total_time) * 8; // convert to megabits per second
    printf("Download speed: %.2f Mbps\n", speed);
    printf("Measuring upload speed...\n");
    start_time = time(NULL); // start timer
    // simulate uploading a file of size 5MB
    for(int i=0; i<5*1024*1024; i++){
        // do nothing
    }
    end_time = time(NULL); // end timer
    total_time = end_time - start_time;
    speed = (5 / total_time) * 8; // convert to megabits per second
    printf("Upload speed: %.2f Mbps\n", speed);
}

int main(){
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press enter to begin...\n");
    getchar(); // wait for user to enter key
    measure_speed();
    printf("Thank you for using the Internet Speed Test Application!\n");
    return 0;
}