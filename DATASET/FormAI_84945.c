//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DOWNLOAD_SPEED 100 // in Megabits per second
#define MAX_UPLOAD_SPEED 10 // in Megabits per second

double download_speed() {
    double speed = ((double) rand() / RAND_MAX) * MAX_DOWNLOAD_SPEED;
    return speed;
}

double upload_speed() {
    double speed = ((double) rand() / RAND_MAX) * MAX_UPLOAD_SPEED;
    return speed;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Internet Speed Test\n\n");

    printf("Testing Download Speed...");
    double download = download_speed();
    printf(" %.2f Mbps\n", download);

    printf("Testing Upload Speed...");
    double upload = upload_speed();
    printf(" %.2f Mbps\n", upload);

    if (download >= 50 && upload >= 5) {
        printf("Great news! Your internet speeds are excellent.\n");
    } else if (download >= 30 && upload >= 3) {
        printf("Your internet could be faster, but it's still pretty decent.\n");
    } else if (download >= 10 && upload >= 1) {
        printf("Your internet speeds are quite slow. You may want to consider upgrading.\n");
    } else {
        printf("Your internet speeds are very slow. You really need to upgrade.\n");
    }

    return 0;
}