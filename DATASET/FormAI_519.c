//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); // seed for random numbers
    int download_speed = rand() % 100; // random download speed between 0 and 100 Mbps
    int upload_speed = rand() % 50; // random upload speed between 0 and 50 Mbps

    printf("Welcome to the post-apocalyptic internet speed test! \n");
    printf("Testing download speed ... \n");
    printf("Your download speed is %d Mbps. \n", download_speed);
    printf("Testing upload speed ... \n");
    printf("Your upload speed is %d Mbps. \n", upload_speed);

    if(download_speed < 5 || upload_speed < 2){
        printf("Oh no! Your internet speed is too slow for this post-apocalyptic world. You need to upgrade your connection or risk being eaten by zombies. \n");
    }
    else if(download_speed > 70 && upload_speed > 40){
        printf("Congratulations! You have lightning-fast internet speed. You are well-equipped to survive in this post-apocalyptic world. \n");
    }
    else{
        printf("Your internet speed is average. You might be able to get by, but you'll need to watch your back. \n");
    }

    return 0;
}