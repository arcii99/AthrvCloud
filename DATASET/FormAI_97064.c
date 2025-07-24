//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h> 
#include <time.h>

int main() 
{ 
    printf("*************************************************************\n");
    printf("             SHAPE-SHIFTING INTERNET SPEED TEST\n");
    printf("*************************************************************\n\n");
    printf("Press any key to start the test...");
    getchar(); // wait for user input

    srand(time(NULL)); // seed the random number generator

    double stability_factor = (rand() % 11) + 5; // generate a random stability factor between 5 and 15
    double download_speed = (rand() % 201) + 100; // generate a random download speed between 100 and 300 Mbps
    double upload_speed = (rand() % 51) + 50; // generate a random upload speed between 50 and 100 Mbps

    printf("\nMeasuring internet stability... \n");
    printf("Your connection stability factor is %.1f/10\n\n", stability_factor);

    printf("Starting download test... \n");
    int time_elapsed_download = (rand() % 6) + 10; // simulate download test taking between 10 and 15 seconds
    double download_size = (download_speed / 8) * time_elapsed_download; // convert speed to MB/s and calculate amount downloaded
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Download size: %.2f MB\n", download_size);
    printf("Download test took %d seconds\n\n", time_elapsed_download);

    printf("Starting upload test... \n");
    int time_elapsed_upload = (rand() % 6) + 10; // simulate upload test taking between 10 and 15 seconds
    double upload_size = (upload_speed / 8) * time_elapsed_upload; // convert speed to MB/s and calculate amount uploaded
    printf("Upload speed: %.2f Mbps\n", upload_speed);
    printf("Upload size: %.2f MB\n", upload_size);
    printf("Upload test took %d seconds\n\n", time_elapsed_upload);

    printf("Test complete!\n\n");
    printf("Overall Score: %.1f/10\n", stability_factor);
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Download Size: %.2f MB\n", download_size);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("Upload Size: %.2f MB\n", upload_size);

    return 0; 
}