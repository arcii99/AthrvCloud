//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // seed the random number generator
    
    float download_speed, upload_speed;
    float download_time, upload_time;
    float download_data, upload_data;
    float download_rate, upload_rate;

    // generate random download and upload speeds
    float max_speed = 100; // in Mbps
    float min_speed = 1; // in Mbps
    float range = max_speed - min_speed;
    download_speed = (float) rand() / RAND_MAX * range + min_speed;
    upload_speed = (float) rand() / RAND_MAX * range + min_speed;

    // get user input for amount of data to download and upload
    float download_size, upload_size;

    printf("Enter the amount of data to download (in MB): ");
    scanf("%f", &download_size);

    printf("Enter the amount of data to upload (in MB): ");
    scanf("%f", &upload_size);

    // calculate download and upload times
    download_data = download_size * pow(10, 6); // convert to bits
    download_time = download_data / (download_speed * pow(10, 6)); // convert to seconds
    upload_data = upload_size * pow(10, 6); // convert to bits
    upload_time = upload_data / (upload_speed * pow(10, 6)); // convert to seconds

    // calculate download and upload rates
    download_rate = download_data / download_time; // in bps
    upload_rate = upload_data / upload_time; // in bps

    // print results
    printf("\nDownload speed: %0.2f Mbps\n", download_speed);
    printf("Download size: %0.2f MB\n", download_size);
    printf("Download time: %0.2f seconds\n", download_time);
    printf("Download rate: %0.2f bps\n", download_rate);
    printf("\nUpload speed: %0.2f Mbps\n", upload_speed);
    printf("Upload size: %0.2f MB\n", upload_size);
    printf("Upload time: %0.2f seconds\n", upload_time);
    printf("Upload rate: %0.2f bps\n", upload_rate);

    return 0;
}