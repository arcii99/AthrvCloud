//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("This program will measure your download and upload speeds,\n");
    printf("and give you an estimate of your internet speed.\n\n");

    // First, we prompt the user to input the size of a test file they would like to download
    // (we'll use this to calculate their download speed)
    int file_size;
    printf("Please enter the size of test file you would like to download (in MB): ");
    scanf("%d", &file_size);

    // Then, we generate a random download time (in seconds) based on their chosen file size
    srand(time(NULL));
    int download_time = rand() % 11 + (file_size / 2);

    // We convert the download time from seconds to minutes and seconds for ease of reading
    int download_minutes = download_time / 60;
    int download_seconds = download_time % 60;
    printf("\nYour download took %d minutes and %d seconds.\n", download_minutes, download_seconds);

    // We prompt the user to enter the size of a test file they would like to upload
    // (we'll use this to calculate their upload speed)
    printf("\nPlease enter the size of test file you would like to upload (in MB): ");
    scanf("%d", &file_size);

    // We generate a random upload time (in seconds) based on their chosen file size
    int upload_time = rand() % 11 + (file_size / 2);

    // We convert the upload time from seconds to minutes and seconds for ease of reading
    int upload_minutes = upload_time / 60;
    int upload_seconds = upload_time % 60;
    printf("\nYour upload took %d minutes and %d seconds.\n\n", upload_minutes, upload_seconds);

    // Finally, we calculate and display the user's estimated internet speed
    double download_speed = (double)file_size / download_time;
    double upload_speed = (double)file_size / upload_time;
    printf("Your estimated download speed is %.2f MB/s.\n", download_speed);
    printf("Your estimated upload speed is %.2f MB/s.\n", upload_speed);

    return 0;
}