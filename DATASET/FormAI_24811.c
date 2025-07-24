//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int download_speed, upload_speed;
    char confirm;

    srand(time(NULL));
    download_speed = rand() % 200 + 1;
    upload_speed = rand() % 100 + 1;

    printf("***Futuristic Internet Speed Test***\n\n");
    printf("System is generating download and upload speed...\n");
    sleep(3);
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n\n", upload_speed);

    printf("Are you satisfied with your Internet connection? (Y/N): ");
    scanf(" %c", &confirm); // space added before %c to clear buffer

    if (confirm == 'N' || confirm == 'n') {
        printf("We apologize for the inconvenience.\n");
        printf("Please contact your service provider for assistance.\n");
    } else {
        printf("Thank you for using our Internet speed test application!\n");
    }

    return 0;
}