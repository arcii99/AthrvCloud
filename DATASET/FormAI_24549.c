//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed;
    int downloadTime, uploadTime;
    clock_t begin, end;
    double downloadElapsedTime, uploadElapsedTime;

    // Check download speed
    printf("Testing download speed...\n");
    begin = clock(); // Start timing download
    system("curl --silent --output /dev/null https://speedtest.wdc01.softlayer.com/downloads/test500.zip");
    end = clock(); // End timing download
    downloadElapsedTime = (double)(end - begin) / CLOCKS_PER_SEC; // Calculate elapsed time in seconds
    downloadTime = (int)(500.0 / downloadElapsedTime / 1024.0); // Calculate download speed in Mbps
    printf("Download speed: %d Mbps\n", downloadTime);

    // Check upload speed
    printf("Testing upload speed...\n");
    begin = clock(); // Start timing upload
    system("curl --silent --upload-file /dev/zero https://speedtest.wdc01.softlayer.com:8443/speedtest/upload.php?x");
    end = clock(); // End timing upload
    uploadElapsedTime = (double)(end - begin) / CLOCKS_PER_SEC; // Calculate elapsed time in seconds
    uploadTime = (int)(500.0 / uploadElapsedTime / 1024.0); // Calculate upload speed in Mbps
    printf("Upload speed: %d Mbps", uploadTime);

    return 0;
}