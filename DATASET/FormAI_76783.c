//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C Internet Speed Test!\n");

    // Randomly generate download speed between 1 and 100 Mbps
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    printf("Your download speed: %d Mbps\n", download_speed);

    // Prompt user to enter their upload speed
    printf("Enter your upload speed (in Mbps): ");
    int user_upload_speed;
    scanf("%d", &user_upload_speed);

    // Calculate user's ping time
    int ping_time = rand() % 100 + 1;
    printf("Your ping time: %d ms\n", ping_time);

    // Determine if user's speeds meet recommended requirements
    if (download_speed >= 30 && user_upload_speed >= 5 && ping_time <= 50) {
        printf("Congratulations! Your internet speed meets recommended requirements.\n");
    } else {
        printf("Your internet speed does not meet recommended requirements.\n");
    }

    return 0;
}