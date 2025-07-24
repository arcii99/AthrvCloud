//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    printf("Welcome to the Internet Speed Test Application\n");
    
    printf("Please wait while we connect to the server...\n");
    // Simulating server connection delay
    int server_connect_time = rand() % 5 + 1;
    sleep(server_connect_time);
    
    printf("Connection established!\n\n");
    
    printf("Press enter to begin the test...");
    getchar();
    
    // Simulating download speed test
    printf("Testing download speed...\n");
    int download_speed = rand() % 100 + 1;
    printf("Download speed is %d MB/s\n", download_speed);
    
    // Simulating upload speed test
    printf("Testing upload speed...\n");
    int upload_speed = rand() % 50 + 1;
    printf("Upload speed is %d MB/s\n", upload_speed);
    
    // Displaying final result
    printf("\nDownload speed: %d MB/s\n", download_speed);
    printf("Upload speed: %d MB/s\n", upload_speed);
    
    // Providing suggestions for improvement
    if(download_speed < 10){
        printf("\nYour download speed is slow. Please check your internet speed plan or contact your service provider.\n");
    }
    else if(download_speed < 50){
        printf("\nYour download speed is average. You can consider upgrading your internet speed plan for better experience.\n");
    }
    else{
        printf("\nYour download speed is excellent. Keep enjoying fast internet!\n");
    }
    
    if(upload_speed < 5){
        printf("\nYour upload speed is slow. Please check your internet speed plan or contact your service provider.\n");
    }
    else if(upload_speed < 20){
        printf("\nYour upload speed is average. You can consider upgrading your internet speed plan for better experience.\n");
    }
    else{
        printf("\nYour upload speed is excellent. Keep enjoying fast internet!\n");
    }
    
    return 0;
}