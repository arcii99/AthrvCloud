//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_SPEED 0.1
#define MAX_SPEED 1000

double get_random_number(double min, double max)
{
    double range = max - min;
    double rand_num = ((double)rand() / RAND_MAX) * range + min;
    return rand_num;
}

bool is_internet_slow(double speed)
{
    if (speed < MIN_SPEED) {
        return true;
    }
    return false;
}

bool is_internet_fast(double speed)
{
    if (speed > MAX_SPEED) {
        return true;
    }
    return false;
}

void test_internet_speed()
{
    srand(time(NULL)); // initialize random number generator

    double speed = get_random_number(MIN_SPEED, MAX_SPEED);

    if (is_internet_slow(speed)) {
        printf("Your internet speed is too slow!\n");
    } else if (is_internet_fast(speed)) {
        printf("Wow! Your internet speed is blazing fast!\n");
    } else {
        printf("Your internet speed is %.2f Mbps. ", speed);
        printf("This is considered average.\n");
    }
}

int main()
{
    printf("Welcome to the Internet Speed Test.\n");
    printf("Press any key to start the test.\n");
    getchar(); // wait for user to press any key
    test_internet_speed();
    return 0;
}