//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download, upload, latency;
    srand(time(NULL));
    download = rand() % 100 + 1;
    upload = rand() % 100 + 1;
    latency = rand() % 100 + 1;

    printf("***CYBERPUNK INTERNET SPEED TEST***\n\n");
    printf("Testing download speed... %d Mbps\n", download);
    printf("Testing upload speed... %d Mbps\n", upload);
    printf("Testing latency... %d ms\n\n", latency);

    printf("Test complete!\n\n");
    printf("Your connection is ");
    if(download < 20 || upload < 10 || latency > 70) {
        printf("TERMINAL. Your connection is not powerful enough to survive in this world. Consider upgrading or risk being left behind.\n");
    }
    else if(download < 50 || upload < 25 || latency > 50) {
        printf("SHODDY. Your connection could use some work, but it will suffice for most everyday use.\n");
    }
    else if(download < 80 || upload < 50 || latency > 30) {
        printf("DECENT. Your connection is above average and should be able to handle most tasks.\n");
    }
    else {
        printf("PERFECT. Your connection is powerful enough to rule the network and dominate the digital world.\n");
    }

    return 0;
}