//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void delay(int seconds){
    time_t start_time = time(NULL);
    while((time(NULL) - start_time) < seconds);
}

int main(){

    int speed = 0;

    printf("Welcome to the Internet Speed Test!\n");
    printf("Your internet connection is very important in the post-apocalyptic world.\n");
    printf("Let's start the test...\n\n");

    for(int i = 5; i > 0; i--){
        printf("Test will begin in %d seconds...\n", i);
        delay(1);
    }

    for(int i = 0; i < 10; i++){
        printf("Testing speed...Please wait...\n");
        delay(2);
        speed += (rand()%10) + 1;
    }

    speed /= 10;

    printf("\n\nTest complete!\n");
    printf("Your internet speed is %d Mbps\n", speed);

    if(speed < 2){
        printf("Sorry to say but your internet connection is too slow. It may not be suitable for post-apocalyptic use.\n");
    } else if(speed >= 2 && speed < 5){
        printf("Your internet connection is decent. It should suffice for most basic post-apocalyptic needs.\n");
    } else if(speed >= 5 && speed < 10){
        printf("Your internet connection is strong. This will be more than enough for most post-apocalyptic requirements.\n");
    } else {
        printf("Congratulations, Your internet connection is blazing fast! It will ensure you stay ahead in the post-apocalyptic world.\n");
    }

    return 0;
}