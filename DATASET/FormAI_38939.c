//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <time.h>

int main()
{
    //Let's start by creating a tm struct to hold the current time values

    struct tm current_time;

    //We will need the number of seconds since the epoch, which is January 1, 1970, so let's use time() function

    time_t seconds_since_epoch = time(NULL);

    //Now let's fill the current_time struct with our values by using localtime() function

    localtime_r(&seconds_since_epoch, &current_time);

    //Next, we will use strftime() function to format our time string

    char time_string[50];

    strftime(time_string, sizeof(time_string), "Current time: %I:%M %p\n", &current_time);

    //Finally, let's print the time string to the console

    printf("%s", time_string);

    //Let's make this program even more curious by adding some user input! 

    char name[30];

    printf("Hi there! What should I call you? ");

    //We will use fgets() function to get the user's name input

    fgets(name, sizeof(name), stdin);

    printf("Hello, %s", name);

    //And let's add some more curious features by generating a random number and displaying an interesting fact about it!

    int random_num;
    srand(time(NULL)); //Seed the random number generator with the current time

    random_num = rand() % 100; //Generate a random number between 0 and 99

    printf("Did you know that %d is the number of elements in the set of all possible chess games?\n", random_num);

    return 0;
}