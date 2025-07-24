//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <math.h>

// function to calculate internet speed
float internet_speed(float download_rate, float upload_rate)
{
    float speed = (download_rate + upload_rate) / 2;
    return speed;
}

int main()
{
    float download_rate, upload_rate;
    
    // input download rate
    printf("Enter download rate in Mbps: ");
    scanf("%f", &download_rate);
    
    // input upload rate
    printf("Enter upload rate in Mbps: ");
    scanf("%f", &upload_rate);
    
    // calculate internet speed
    float speed = internet_speed(download_rate, upload_rate);
    
    // display internet speed
    printf("\nYour internet speed is %.2f Mbps\n", speed);
    
    return 0;
}