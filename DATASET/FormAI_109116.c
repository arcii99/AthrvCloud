//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int delay = 0;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Welcome to the Minimalist Internet Speed Test!\n");
    printf("This test will check how fast you can download data from the internet.\n");
    printf("Please wait while we prepare the download...\n");
    printf("Press any key to start the test.\n");
    getchar();
    
    // Download Speed Test
    start = clock();
    for(i = 0; i < 5; i++) {
        printf("Downloading file %d...\n", i+1);
        count = 0;
        for(j = 1; j <= 1024; j++) {
            for(k = 1; k <= 1024; k++) {
                delay = delay + j;
                delay = delay + k;
                count++;
            }
        }
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        speed = (1024 * count) / cpu_time_used;
        printf("File %d downloaded in %f seconds. Speed: %d KB/s\n", i+1, cpu_time_used, speed);
        delay = 0;
    }
    end = clock();
    
    // Result
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The test completed in %f seconds. Your average download speed is %d KB/s.\n", cpu_time_used, speed / 5);
    
    return 0;
}