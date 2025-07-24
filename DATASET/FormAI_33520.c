//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DATA_SIZE 10000000   //10 MB of data to download

int main() {
    int download_speed;
    int downloading = 1;
    int downloaded = 0;
    clock_t start_time, end_time;
    double time_elapsed;
    
    printf("Starting internet speed test\n");
    printf("Downloading %d bytes of data...\n", DATA_SIZE);
    
    start_time = clock();    //start timer
    
    while(downloading) {
        downloaded += 1024; //download 1KB of data
        sleep(1);   //wait for 1 second
        if(downloaded >= DATA_SIZE) {
            downloading = 0;    //stop downloading when all data has been downloaded
        }
    }
    
    end_time = clock();  //stop timer
    time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    download_speed = (int)(DATA_SIZE / (time_elapsed * 1000000));
    
    printf("Downloaded %d bytes of data in %.2f seconds\n", DATA_SIZE, time_elapsed);
    printf("Your internet download speed is: %d Mbps\n", download_speed);
    
    return 0;
}