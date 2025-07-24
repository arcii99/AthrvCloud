//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int speed = 0;
    int delay = 0;
    int strength = 0;
    int max_speed = 100;
    int min_speed = 1;
    int max_delay = 5000;
    int min_delay = 1;
    srand(time(0));
    
    printf("Scanning for internet connection...\n\n");
    delay = rand() % (max_delay - min_delay + 1) + min_delay;
    printf("Establishing connection...\n");
    for (int i = 0; i < delay; i += 1000)
    {
        printf("%d seconds remaining...\n", (delay - i) / 1000);
        sleep(1);
    }
    printf("\nConnection established!\n");
    
    printf("\nRunning speed test...\n");
    for (int i = 0; i < 3; i++)
    {
        delay = rand() % (max_delay - min_delay + 1) + min_delay;
        printf("\nUploading data...\n");
        for (int j = 0; j < delay; j += 1000)
        {
            printf("%d seconds remaining...\n", (delay - j) / 1000);
            sleep(1);
        }
        speed = rand() % (max_speed - min_speed + 1) + min_speed;
        printf("\nUpload speed: %d Mbps.\n", speed);
        strength += speed;
        delay = rand() % (max_delay - min_delay + 1) + min_delay;
        printf("\nDownloading data...\n");
        for (int j = 0; j < delay; j += 1000)
        {
            printf("%d seconds remaining...\n", (delay - j) / 1000);
            sleep(1);
        }
        speed = rand() % (max_speed - min_speed + 1) + min_speed;
        printf("\nDownload speed: %d Mbps.\n", speed);
        strength += speed;
    }
    
    printf("\nTest complete!\n");
    printf("Overall strength: %d Mbps.\n", strength);
    
    if (strength >= 150)
    {
        printf("Your internet strength is strong enough to withstand any post-apocalyptic scenario. Congratulations!\n");
    }
    else if (strength >= 100)
    {
        printf("Your internet strength is relatively strong, but may still struggle in a post-apocalyptic scenario.\n");
    }
    else
    {
        printf("Your internet strength is weak and would likely fail in a post-apocalyptic scenario. Consider upgrading your connection.\n");
    }
    return 0;
}