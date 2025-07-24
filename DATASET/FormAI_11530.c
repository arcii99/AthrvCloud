//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function generates a random download speed between 1 and 100 Mbps
int generateDownloadSpeed() {
    return (rand() % 100) + 1;
}

// This function generates a random upload speed between 1 and 50 Mbps
int generateUploadSpeed() {
    return (rand() % 50) + 1;
}

int main() {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random download speed and upload speed
    int downloadSpeed = generateDownloadSpeed();
    int uploadSpeed = generateUploadSpeed();

    // Display the speeds to the user
    printf("Your Download Speed: %d Mbps\n", downloadSpeed);
    printf("Your Upload Speed: %d Mbps\n", uploadSpeed);

    // Prompt the user to enter their expected speeds
    printf("Enter your expected download speed: ");
    int expectedDownloadSpeed;
    scanf("%d", &expectedDownloadSpeed);

    printf("Enter your expected upload speed: ");
    int expectedUploadSpeed;
    scanf("%d", &expectedUploadSpeed);

    // Compare the expected speeds with the actual speeds and display the result
    if (expectedDownloadSpeed < downloadSpeed || expectedUploadSpeed < uploadSpeed) {
        printf("Sorry, your internet speed is slower than expected.\n");
    } else {
        printf("Congratulations, your internet speed meets or exceeds your expectations!\n");
    }

    return 0;
}