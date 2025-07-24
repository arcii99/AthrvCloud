//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned int i, j;
    double elapsed_time;
    clock_t start, end;
    
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("This program will simulate a download to test your internet speed.\n");
    printf("Please enter the size of the download in MB (e.g. 100 for 100MB): ");
    scanf("%u", &i);
    
    printf("\nTesting download speed of %u MB...\n\n", i);
    
    start = clock();
    
    for (j=0; j<i*1024*1024; j++)
    {
        rand();
    }
    
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Download completed!\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Estimated download speed: %.2f Mbps\n", i*8/elapsed_time);
    
    return 0;
}