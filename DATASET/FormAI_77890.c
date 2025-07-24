//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("\n*******************************************************");
    printf("\n\tWelcome to the Internet Speed Test Application");
    printf("\n*******************************************************");

    // Variable declaration
    int download_speed, upload_speed;
    srand(time(0)); // used for generating random value
    download_speed = rand() % 101; // Randomly generating download speed from 0 to 100
    upload_speed = rand() % 101; // Randomly generating upload speed from 0 to 100

    printf("\n\nYour Download Speed is: %d Mbps", download_speed);
    printf("\nYour Upload Speed is: %d Mbps", upload_speed);

    // Calculating overall speed using a formula
    int speed = (download_speed + upload_speed) / 2;

    printf("\n\n**********************************************************");
    printf("\nOverall Speed: %d Mbps", speed);
    printf("\n**********************************************************");

    if(speed <= 20){
        printf("\n\nYour internet speed is slow, you might face difficulties in streaming videos and uploading/downloading files.");
    }else if(speed > 20 && speed <= 50){
        printf("\n\nYour internet speed is average, you can browse internet, stream videos and download files with decent speed.");
    }else if(speed > 50 && speed <= 90){
        printf("\n\nYour internet speed is good, you can do almost everything with this speed like streaming ultra HD videos, video conferencing, gaming etc.");
    }else{
        printf("\n\nWow! Your internet speed is super fast, you can do anything you want without worrying about buffering or lagging.");
    }

    printf("\n\n***********************************************************");
    printf("\nThank You for using our Internet Speed Test Application!");
    printf("\n***********************************************************");

    return 0;
}