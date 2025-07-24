//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInternetSpeed(){
   // Logic to calculate internet speed
   int speed = rand() % 100; // generating random number between 0-100
   return speed;
}

int main(){
    srand(time(0)); // seed for random number generator
    int downloadSpeed = getInternetSpeed(); // getting the download speed
    int uploadSpeed = getInternetSpeed(); // getting the upload speed
    
    printf("Welcome to the Internet Speed Test Application\n");
    printf("Your Download Speed: %d Mbps\n", downloadSpeed);
    printf("Your Upload Speed: %d Mbps\n\n", uploadSpeed);
    printf("Processing...\n");

    // Checking the download speed
    if (downloadSpeed < 25){
        printf("Your Download Speed is slow. Try Troubleshooting your network or call your service provider.\n");
    }
    else if (downloadSpeed >= 25 && downloadSpeed < 50){
        printf("Your Download Speed is average. You can perform most online activities such as streaming videos and surfing the web.\n");
    }
    else{
        printf("Your Download Speed is fast. You can perform all online activities with ease such as streaming 4K videos and playing multiplayer games online.\n");
    }

    // Checking the upload speed
    if (uploadSpeed < 5){
        printf("Your Upload Speed is slow. This may lead to slower sending/receiving files.\n");
    }
    else if (uploadSpeed >= 5 && uploadSpeed < 15){
        printf("Your Upload Speed is average. You can easily share your files and documents online.\n");
    }
    else{
        printf("Your Upload Speed is fast. This will provide high-speed file sharing and make video calls much clearer.\n");
    }

    return 0;
}