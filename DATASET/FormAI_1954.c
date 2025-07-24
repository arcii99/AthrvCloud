//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Initializing the time variables
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Ask the user for their time travel destination
    printf("Where would you like to travel in time? (in years) ");
    int years;
    scanf("%d", &years);

    // Calculating the destination time
    int destination_year = current_time->tm_year + years;
    struct tm destination_time = *current_time;
    destination_time.tm_year = destination_year;

    // Generate a random love message for the past/future partner
    const char *love_messages[] = {
        "I love you more than anything, even time itself.",
        "I'm so happy to be able to share this time with you.",
        "You are my past, present and future.",
        "I knew I would find you in any time and any place.",
        "I would wait for centuries just to be with you.",
        "My love for you is timeless.",
        "Every moment spent with you is a moment well spent."
    };

    int message_count = sizeof(love_messages)/sizeof(love_messages[0]);
    int message_index = rand() % message_count;

    // Output the time and love message to the user
    char date_string[100];
    strftime(date_string, sizeof(date_string), "%Y-%m-%d %H:%M:%S", &destination_time);

    printf("\nYou have traveled in time to: %s\n", date_string);
    printf("The love message for your partner is:\n%s\n", love_messages[message_index]);

    return 0;
}