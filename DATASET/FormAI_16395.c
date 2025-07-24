//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SERVER_SPEED 1000 // in megabits per second (Mbps)

int main(void) {
    srand(time(NULL)); //seed for random number generator
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press any key to begin the test\n");
    getchar();
    
    int download_speed = rand() % 1000 + 1; // random download speed between 1 and 1000 Mbps
    int upload_speed = rand() % 1000 + 1; // random upload speed between 1 and 1000 Mbps
    
    printf("Testing download speed...\n");
    for(int i = 0; i < 10; i++) { // simulate downloading 10 files
        int file_size = rand() % 100 + 1; // random file size between 1 and 100 megabytes
        int download_time = file_size / download_speed * 1000; // time in milliseconds
        printf("File %d downloaded in %d milliseconds\n", i+1, download_time);
    }
    
    printf("\nTesting upload speed...\n");
    for(int i = 0; i < 10; i++) { // simulate uploading 10 files
        int file_size = rand() % 100 + 1; // random file size between 1 and 100 megabytes
        int upload_time = file_size / upload_speed * 1000; // time in milliseconds
        printf("File %d uploaded in %d milliseconds\n", i+1, upload_time);
    }
    
    printf("\nTest complete!\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    
    int latency = rand() % 100 + 1; // random latency between 1 and 100 milliseconds
    printf("Latency/ping: %d milliseconds\n", latency);
    
    float server_load = (download_speed + upload_speed) / (float)SERVER_SPEED * 100;
    printf("Server load: %.2f%%\n", server_load);
    
    return 0; // exit program
}