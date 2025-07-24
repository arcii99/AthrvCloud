//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press ENTER to start the test...\n");
    getchar();
    
    int download_speed, upload_speed;
    srand(time(NULL));
    download_speed = (rand() % 100) + 1;
    sleep(1);
    upload_speed = (rand() % 100) + 1;
    
    printf("\nCalculating results...\n");
    sleep(2);
    printf("Your download speed: %d Mb/s\n", download_speed);
    printf("Your upload speed: %d Mb/s\n", upload_speed);
    
    if (download_speed > 50 && upload_speed > 50) {
        printf("Congratulations! Your internet speed is lightning fast!\n");
    } else if (download_speed > 20 && upload_speed > 20) {
        printf("Your internet speed is decent, but could be better.\n");
    } else {
        printf("Uh-oh, looks like your internet speed is slower than average.\n");
    }
    
    return 0;
}