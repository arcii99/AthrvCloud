//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int downloadSpeed, uploadSpeed, ping;
    clock_t start, end;
    double time_taken;

    printf("Welcome to the Internet Speed Test Application\n\n");

    printf("Testing Download Speed...\n");
    start = clock(); //start the clock for download speed test
    //simulate download speed test
    for (int i = 0; i < 10000000; i++) {
        continue;
    }
    end = clock(); //stop the clock for download speed test
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    downloadSpeed = (int)(10000 / time_taken); //calculate download speed in kilobits per second
    printf("Your Download Speed is: %d kbps\n\n", downloadSpeed);

    printf("Testing Upload Speed...\n");
    start = clock(); //start the clock for upload speed test
    //simulate upload speed test
    for (int i = 0; i < 10000000; i++) {
        continue;
    }
    end = clock(); //stop the clock for upload speed test
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    uploadSpeed = (int)(10000 / time_taken); //calculate upload speed in kilobits per second
    printf("Your Upload Speed is: %d kbps\n\n", uploadSpeed);

    printf("Testing Ping...\n");
    start = clock(); //start the clock for ping test
    //simulate ping test
    for (int i = 0; i < 100000000; i++) {
        continue;
    }
    end = clock(); //stop the clock for ping test
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    ping = (int)(1000 * time_taken); //calculate ping time in milliseconds
    printf("Your Ping is: %d ms\n\n", ping);

    printf("Thank you for using the Internet Speed Test Application!\n");

    return 0;
}