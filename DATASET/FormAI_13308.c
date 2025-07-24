//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Genius Internet Speed Test!\n");
    printf("Press Enter to begin...\n");
    getchar(); // wait for input
    printf("\n");

    // generate random download and upload speeds
    srand(time(NULL));
    float download_speed = (float)rand()/(float)(RAND_MAX/100);
    float upload_speed = (float)rand()/(float)(RAND_MAX/100);

    printf("Testing Download Speed...\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);

    printf("Testing Upload Speed...\n");
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    // check the user's internet plan against the speeds
    printf("\nWhat is your internet plan's maximum download speed?\n");
    float plan_download_speed;
    scanf("%f", &plan_download_speed);
    if (download_speed >= plan_download_speed) {
        printf("Congratulations! You are receiving your plan's maximum download speed.\n");
    } else {
        printf("Sorry, it appears your download speed is slower than your plan's maximum speed.\n");
    }

    printf("\nWhat is your internet plan's maximum upload speed?\n");
    float plan_upload_speed;
    scanf("%f", &plan_upload_speed);
    if (upload_speed >= plan_upload_speed) {
        printf("Congratulations! You are receiving your plan's maximum upload speed.\n");
    } else {
        printf("Sorry, it appears your upload speed is slower than your plan's maximum speed.\n");
    }

    printf("\nThank you for using the Genius Internet Speed Test!\n");

    return 0;
}