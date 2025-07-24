//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Happy Internet Speed Test!\n");
    printf("Checking your connection speed... Please wait...\n");

    float download_speed;
    float upload_speed;

    // simulate test results
    download_speed = (float) (rand() % 10000) / 100.0; // random download speed between 0 and 100 Mbps
    upload_speed = (float) (rand() % 5000) / 100.0; // random upload speed between 0 and 50 Mbps

    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    if (download_speed >= 50 && upload_speed >= 25) {
        printf("Your internet speed is AWESOME! You can do anything you want to do online with this speed. Keep it up! :)\n");
    } else if (download_speed >= 25 && upload_speed >= 10) {
        printf("Your internet speed is GOOD! You can stream movies, play games, and do other activities online with this speed. Keep improving! :)\n");
    } else if (download_speed >= 10 && upload_speed >= 5) {
        printf("Your internet speed is OKAY! You can browse the web and check email with this speed. Consider upgrading for better performance. :)\n");
    } else if (download_speed < 10 || upload_speed < 5) {
        printf("Your internet speed is SLOW! You may experience long load times, buffering, and other issues with this speed. Consider upgrading for better performance. :( \n");
    }

    printf("Thank you for using the Happy Internet Speed Test! Have a wonderful day!\n");

    return 0;
}