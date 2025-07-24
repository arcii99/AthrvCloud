//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int speed = 0;
    srand(time(NULL));
    int randomNum1 = rand() % 101; //generate a random number between 0 and 100
    int randomNum2 = rand() % 101;
    int randomNum3 = rand() % 101;

    printf("Welcome to the Brave Internet Speed Test App!\n\n");
    printf("Testing your download speed...please wait...\n\n");
    sleep(3); //simulate a delay in testing

    printf("Download speed: %d Mbps\n", randomNum1);
    if (randomNum1 > 50) {
        printf("Great job! Your download speed is higher than the national average!\n\n");
    } else {
        printf("Your download speed is below the national average. Consider upgrading your internet plan.\n\n");
    }

    printf("Testing your upload speed...please wait...\n\n");
    sleep(3); //simulate a delay in testing

    printf("Upload speed: %d Mbps\n", randomNum2);
    if (randomNum2 > 50) {
        printf("Awesome! Your upload speed is higher than the national average!\n\n");
    } else {
        printf("Your upload speed is below the national average. Consider upgrading your internet plan.\n\n");
    }

    printf("Testing your ping...please wait...\n\n");
    sleep(3); //simulate a delay in testing

    printf("Ping: %d ms\n", randomNum3);
    if (randomNum3 < 20) {
        printf("Wow! Your ping is super fast! Impressive!\n\n");
    } else {
        printf("Your ping could be faster. Consider using a wired connection instead of WiFi.\n\n");
    }

    //calculate overall speed rating based on download, upload, and ping speeds
    speed = (randomNum1 + randomNum2) / 2;
    if (randomNum3 < 20) {
        speed += 10;
    } else if (randomNum3 < 50) {
        speed += 5;
    }

    printf("Overall speed rating: %d\n", speed);
    if (speed > 75) {
        printf("Congratulations! Your internet speed is excellent! Keep up the good work!\n");
    } else if (speed > 50) {
        printf("Your internet speed is above average, but has some room for improvement. Consider upgrading your internet plan.\n");
    } else {
        printf("Your internet speed is below average. Consider upgrading your internet plan or troubleshooting the issue.\n");
    }

    return 0;
}