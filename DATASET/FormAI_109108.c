//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 
 * This program simulates an Internet Speed Test Application. 
 * The user is prompted to enter their current download speed, 
 * and the program generates a random upload speed. 
 * The program then compares the two speeds to determine 
 * the overall internet speed.
 */

int main() {

    int download_speed;
    float upload_speed;
    char units[20];
    srand(time(NULL)); // seed for random number generation

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("\nPlease enter your current download speed: ");
    scanf("%d %s", &download_speed, units);

    // generate random upload speed
    upload_speed = (float) (rand() % (1000 - 100 + 1) + 100) / 10;

    // print out speeds
    printf("\nYour download speed is: %d %s", download_speed, units);
    printf("\nYour upload speed is: %.1f Mbps", upload_speed);

    // determine overall internet speed
    if (download_speed >= 50 && upload_speed >= 5)
        printf("\n\nCongratulations, you have a FAST internet connection!");
    else if (download_speed >= 20 && upload_speed >= 2)
        printf("\n\nYou have a MODERATE internet connection.");
    else
        printf("\n\nYour internet connection is SLOW. Consider upgrading your plan.");

    return 0;
}