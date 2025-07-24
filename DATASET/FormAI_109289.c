//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
/*
 * The Case of the Lost Internet Speed
 *
 * Detective: Mr. Holmes
 * Date: September 15, 2021
 *
 * Description: A program to test the internet speed
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min_speed = 1; // minimum speed in Mbps
    int max_speed = 100; // maximum speed in Mbps
    int random_speed;
    char answer;

    printf("Greetings! I am Mr. Holmes, and I've been called to investigate a case of lost internet speed.\n");
    printf("To assist me in my investigation, I will need to test your current internet speed.\n");
    printf("This test will take approximately 1 minute to complete.\n\n");

    printf("Are you ready to begin the speed test? (y/n): ");
    scanf(" %c", &answer);

    if (answer != 'y' && answer != 'Y')
    {
        printf("Perhaps we can reschedule for a later time. Goodbye!\n");
        return 0;
    }

    printf("Please wait while we test your internet speed...\n\n");

    // generate a random speed within the range of min_speed and max_speed
    srand(time(NULL));
    random_speed = (rand() % (max_speed - min_speed + 1)) + min_speed;

    printf("Your internet speed is %.2f Mbps.\n", (float)random_speed);

    printf("\nThank you for participating in this speed test. Goodbye!\n");

    return 0;
}