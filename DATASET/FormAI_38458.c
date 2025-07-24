//FormAI DATASET v1.0 Category: Date and time ; Style: funny
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Funny Time Program!\n\n");
    printf("This program will show you the current date and time, but with a funny twist.\n\n");
    printf("Get ready to laugh (hopefully)! Press any key to continue...\n");
    getchar();
    
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    int year = currentTime->tm_year + 1900;
    int month = currentTime->tm_mon + 1;
    int day = currentTime->tm_mday;
    int hour = currentTime->tm_hour;
    int minute = currentTime->tm_min;
    int second = currentTime->tm_sec;

    if(hour == 4 && minute == 20) {
        printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d \n\n", month, day, year, hour, minute, second);
        printf("Haha, it's 4:20! You know what that means?\n\n");
        printf("It's time to blaze it up! (just kidding, please don't do anything illegal)\n");
    } else if (hour == 23 && minute == 59) {
        printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d \n\n", month, day, year, hour, minute, second);
        printf("It's almost midnight! This is your last chance to do something crazy before the day is over.\n");
        printf("Quick, run outside and yell 'I'm a beautiful unicorn' at the top of your lungs. I dare you...\n");
    } else if (hour >= 23 || hour <= 5) {
        printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d \n\n", month, day, year, hour, minute, second);
        printf("It's pretty late/early right now. You should probably be sleeping instead of running this program...\n");
        printf("But since you're here, want to hear a joke? Why don't scientists trust atoms?\n");
        printf("Because they make up everything! HAHAHAHAHA.\n");
    } else if (day == 1 && month == 4) { 
        printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d \n\n", month, day, year, hour, minute, second);
        printf("Happy April Fool's Day! Did you trick anyone this year?\n");
        printf("I tried to convince my friend that I was a robot, but he didn't believe me. I guess I need to work on my acting skills...\n"); 
    } else {
        printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d \n\n", month, day, year, hour, minute, second);
        printf("Nothing funny to report right now. Just a normal date and time.\n");
        printf("But hey, at least you got to spend some time with me! That's always a good time, right?...\n");
    }

    return 0;
}