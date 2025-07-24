//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int speed = rand() % 101;
    bool isRomantic = true;
    
    if (isRomantic) {
        printf("My love, let me test the speed of your heart with this internet speed test application:\n\n");
        printf("Testing download speed...\n");
        printf("Download speed: %d Mbps\n", speed);
        printf("Wow, that's fast! Just like the beating of my heart when I'm with you.\n\n");
        printf("Testing upload speed...\n");
        printf("Upload speed: %d Mbps\n", speed/2);
        printf("Even though our love may sometimes be slow to upload, it's always worth the wait.\n\n");
        printf("Thank you for taking this test with me. I love you more than all the Mbps in the world.\n");
    } else {
        printf("Testing download speed...\n");
        printf("Download speed: %d Mbps\n", speed);
        printf("Testing upload speed...\n");
        printf("Upload speed: %d Mbps\n", speed/2);
    }
    
    return 0;
}