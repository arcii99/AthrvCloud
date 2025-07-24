//FormAI DATASET v1.0 Category: Date and time ; Style: surprised
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *local_time;
    char time_string[80];

    // get the current time
    current_time = time(NULL);
    local_time = localtime(&current_time);

    // format the time as a string
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    // print out the time
    printf("The current time is: %s\n", time_string);

    // be amazed by the time again
    printf("Wait, let me double check... That's really the time? I'm so impressed!\n");

    // wait for a second
    printf("Now let me just wait for a second...\n");
    sleep(1);

    // get the time again
    current_time = time(NULL);
    local_time = localtime(&current_time);

    // format the time as a string again
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    // print out the new time
    printf("Okay, now the time is: %s\n", time_string);

    // be even more amazed by the time
    printf("My mind is blown by how accurate and precise this time thing is. How does it do it?!\n");

    // end the program with awe
    printf("I think I need to lie down and process this mind-bending experience. Thanks for sharing!\n");

    return 0;
}