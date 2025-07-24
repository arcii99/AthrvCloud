//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include<stdio.h>
#include<time.h>

int main()
{
    float speed;
    time_t start, end;

    printf("Welcome to the Internet Speed Test Application\n");

    printf("Press Enter to begin the test...");
    getchar();

    printf("Testing download speed...\n");

    time(&start);
    //Function to simulate downloading speed
    for(int i = 1; i < 100000000; i++);
    time(&end);

    printf("Download speed test completed in %d seconds.\n", (int)(end-start));

    printf("Press Enter to begin the upload speed test...");
    getchar();

    printf("Testing upload speed...\n");

    time(&start);
    //Function to simulate uploading speed
    for(int i = 1; i < 100000000; i++);
    time(&end);

    printf("Upload speed test completed in %d seconds.\n", (int)(end-start));

    speed = (100/(float)(end-start));

    printf("Your Internet speed is: %0.2f Mbps", speed);
}