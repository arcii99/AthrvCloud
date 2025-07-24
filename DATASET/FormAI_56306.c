//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int bytes = 100000000; // 100 megabytes
    int speed = 0; // initialize speed to 0
    
    printf("Starting internet speed tester...\n");
    printf("This will download %d bytes...\n", bytes);
    
    clock_t start_time = clock(); // start the clock timer
    
    // simulate downloading the bytes
    for (int i = 0; i < bytes; i++) {
        int r = rand() % 256; // generate random byte
        speed += r; // add byte to speed
    }
    
    clock_t end_time = clock(); // stop the clock timer
    
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // calculate time
    double speed_in_mbps = (speed / elapsed_time) * 8 / 1000000; // calculate speed in Mbps
    
    // print results
    printf("Download complete!\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Speed: %.2f Mbps\n", speed_in_mbps);
    
    return 0; // exit program
}