//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    float download_time, upload_time, download_speed, upload_speed;
    double download_bitrate, upload_bitrate, download_size, upload_size;
    time_t t;
    srand((unsigned)time(&t));

    printf("Welcome to the Futuristic Internet Speed Test Application\n\n");

    // Calculating download speed and time taken
    download_size = (double)((rand()%1000)+1000); // Generating random download size between 1 to 2 MB
    download_bitrate = (double)((rand()%5)+5); // Generating random download bitrate between 5 to 10 Mbps
    download_time = download_size/download_bitrate; // Calculating download time in seconds
    download_speed = (download_size/1024)/download_time; // Converting download size to KB and calculating KB/s

    // Displaying download speed results
    printf("Your download speed: %.2f KB/s\n", download_speed);
    printf("Time taken to download %.2f MB: %.2f seconds\n\n", download_size/1024, download_time);

    // Calculating upload speed and time taken
    upload_size = (double)((rand()%500)+500); // Generating random upload size between 0.5 to 1 MB
    upload_bitrate = (double)((rand()%2)+2); // Generating random upload bitrate between 2 to 4 Mbps
    upload_time = upload_size/upload_bitrate; // Calculating upload time in seconds
    upload_speed = (upload_size/1024)/upload_time; // Converting upload size to KB and calculating KB/s

    // Displaying upload speed results
    printf("Your upload speed: %.2f KB/s\n", upload_speed);
    printf("Time taken to upload %.2f MB: %.2f seconds\n\n", upload_size/1024, upload_time);

    return 0;
}