//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int downloadSpeed, uploadSpeed;
    srand(time(NULL));

    downloadSpeed = rand() % 101;
    uploadSpeed = rand() % 101;

    printf("Welcome to the Happy Internet Speed Test Application!\n");
    printf("We will test your download and upload speeds and give you a happy result!\n\n");

    printf("Press any key to start the test...\n");
    getchar();

    printf("Testing download speed...\n");
    printf("Your download speed is %d Mbps\n", downloadSpeed);

    printf("\nTesting upload speed...\n");
    printf("Your upload speed is %d Mbps\n\n", uploadSpeed);

    if (downloadSpeed > 50 && uploadSpeed > 50) {
        printf("Great news! Your internet speed is lightning fast. You can do anything you want online with ease.\n");
        printf("Keep smiling and enjoy the speed!\n");
    } else if (downloadSpeed > 25 && uploadSpeed > 25) {
        printf("Good news! Your internet speed is decent. You can do most things online without any problems.\n");
        printf("Keep smiling and enjoy the speed!\n");
    } else {
        printf("Uh oh! Your internet speed is slow. You may experience lag and buffering while browsing or streaming.\n");
        printf("Don't worry, we're sure your internet will pick up the speed soon! Keep smiling!\n");
    }

    return 0;
}