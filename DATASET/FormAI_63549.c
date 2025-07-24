//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    double download_speed, upload_speed;
    time_t start, end;
    int download_size, upload_size;

    printf("Welcome to the Ken Thompson Internet Speed Test Application!\n\nEnter the size of the file you wish to download (in MB): ");
    scanf("%d", &download_size);

    printf("Enter the size of the file you wish to upload (in MB): ");
    scanf("%d", &upload_size);

    printf("\nTesting download speed...\n");
    time(&start);

    // Simulating download process
    for (int i = 0; i < download_size*1000000; i++);
    
    time(&end);
    download_speed = ((double)download_size*1000000)/(difftime(end, start)*1024*1024);

    printf("Download speed: %f Mbps\n", download_speed);

    printf("\nTesting upload speed...\n");
    time(&start);

    // Simulating upload process
    for (int i = 0; i < upload_size*1000000; i++);

    time(&end);
    upload_speed = ((double)upload_size*1000000)/(difftime(end, start)*1024*1024);

    printf("Upload speed: %f Mbps\n\n", upload_speed);

    printf("Thank you for using the Ken Thompson Internet Speed Test Application!\n");

    return 0;
}