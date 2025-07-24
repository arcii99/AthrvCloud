//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Internet Speed Test!\n");
    
    int download_speed, upload_speed, latency;
    
    //Generate random speeds and latency
    srand(time(NULL));
    download_speed = rand() % 101;
    upload_speed = rand() % 101;
    latency = rand() % 51;
    
    printf("\nTesting Download Speed...\n");
    printf("Your Download Speed: %d Mbps\n", download_speed);
    
    printf("\nTesting Upload Speed...\n");
    printf("Your Upload Speed: %d Mbps\n", upload_speed);
    
    printf("\nTesting Latency...\n");
    printf("Your Latency: %d ms\n", latency);
    
    //Speed classifications
    if (download_speed >= 90 && upload_speed >= 75 && latency <= 20)
        printf("\nExcellent! Your internet speeds are perfect!\n");
    else if (download_speed >= 70 && upload_speed >= 50 && latency <= 40)
        printf("\nGood job! Your internet speeds are good.\n");
    else if (download_speed >= 50 && upload_speed >= 25 && latency <= 60)
        printf("\nYour internet speeds are average.\n");
    else
        printf("\nYour internet speeds need improvement.\n");
    
    return 0;
}