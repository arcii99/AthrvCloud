//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int downloadSpeed;
    int uploadSpeed;
    srand(time(0));
    downloadSpeed = rand() % 1000 + 1;
    uploadSpeed = rand() % 1000 + 1;
    
    printf("Welcome to the Internet Speed Test.\n");
    printf("Calculating your internet speed...\n");
    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n", uploadSpeed);
    
    if(downloadSpeed < 10 || uploadSpeed < 10)
    {
        printf("Your internet connection is extremely slow. Please contact your internet service provider.\n");
    }
    else if(downloadSpeed < 50 || uploadSpeed < 50)
    {
        printf("Your internet connection is slow. Consider upgrading to a faster plan.\n");
    }
    else if(downloadSpeed < 100 || uploadSpeed < 100)
    {
        printf("Your internet connection is average speed.\n");
    }
    else
    {
        printf("Congratulations! Your internet connection is blazing fast!\n");
    }
    
    return 0;
}