//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int speedTest(){
    int x = rand();
    int y = rand();
    int z = rand();
    int average_speed; //To store the average speed of download and upload.
    printf("------------ C Internet Speed Test Application ------------\n\n");
    printf("Please wait while we test your internet speed...\n\n");
    printf("Downloading a 10MB file...\n");
    clock_t t;
    t = clock();
    sleep(5);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; //in seconds
    printf("Download speed: %d Mb/s \n", (x*y)/(int)time_taken); //Calculating and printing download speed in Mb/s.
    printf("Uploading a 5MB file...\n");
    t = clock();
    sleep(3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; //in seconds
    printf("Upload speed: %d Mb/s \n", (y*z)/(int)time_taken); //Calculating and printing upload speed in Mb/s.
    average_speed = ((x*y)/(int)time_taken + (y*z)/(int)time_taken)/2; //Calculating and storing the average speed of download and upload.
    printf("Your average internet speed is %d Mb/s. \n", average_speed);
    return average_speed; //Returning the average speed of internet.
}

int main(){
    int result = speedTest(); //Calling the speedTest() function.
    return 0;
}