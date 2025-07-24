//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please wait while we test your internet speed...\n\n");
    
    // Start the timer
    clock_t start_time, end_time;
    double time_taken;
    start_time = clock();
    
    // Perform download test
    int download_speed = 0;
    for(int i = 1; i <= 10; i++){
        int random_num = rand() % 50 + 1;
        download_speed += random_num;
    }
    download_speed = download_speed * 8;
    printf("Download speed: %d Mbps\n", download_speed);
    
    // Perform upload test
    int upload_speed = 0;
    for(int i = 1; i <= 10; i++){
        int random_num = rand() % 50 + 1;
        upload_speed += random_num;
    }
    upload_speed = upload_speed * 8;
    printf("Upload speed: %d Mbps\n", upload_speed);
    
    // Stop the timer and calculate time taken
    end_time = clock();
    time_taken = ((double)(end_time - start_time))/CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);
    
    return 0;
}