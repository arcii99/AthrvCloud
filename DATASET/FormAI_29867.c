//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this struct is used to define the fortune message
typedef struct {
    char *message;
    int max_range;
} Fortune;

// function that returns a random number between min and max
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function that returns a random message from the Fortune list
char* get_fortune(Fortune f[], int n) {
    int max_range = 0;
    for (int i = 0; i < n; i++) {
        max_range += f[i].max_range;
    }
    int r = get_random_number(1, max_range);
    for (int i = 0; i < n; i++) {
        r -= f[i].max_range;
        if (r <= 0) {
            return f[i].message;
        }
    }
    return NULL;
}

int main() {
    // initializing the fortunes
    Fortune f[] = {
        {"You will face challenges, but you will overcome them.", 10},
        {"Good things are coming your way.", 5},
        {"You will meet someone new and exciting soon.", 8},
        {"Don't give up on your dreams.", 6},
        {"A new opportunity will arise soon.", 7},
        {"You will receive good news in the near future.", 4},
        {"A journey will soon be taken by you.", 5},
        {"A new friend will soon enter your life.", 6},
        {"Your hard work will pay off in the end.", 9},
        {"Change is on the horizon for you.", 6},
        {"Be kind to others and good things will happen to you.", 7},
        {"Your future is bright, keep working towards your goals.", 4},
        {"Luck is on your side.", 5},
        {"Follow your intuition, it will lead you in the right direction.", 8},
        {"Your creativity will be at an all-time high in the near future.", 6},
        {"Listen to the advice of those around you.", 7},
        {"Your positivity will attract positivity.", 5},
        {"Take a leap of faith and good things will come.", 6},
        {"Don't be afraid to take risks.", 7},
        {"Your perseverance will lead to success.", 9},
        {"You will find love in unexpected places.", 5},
        {"Your determination will bring you great accomplishments.", 8},
        {"Stay true to yourself and your dreams.", 6},
        {"Good things come to those who wait.", 7},
        {"Don't let setbacks discourage you, keep pushing forward.", 9}
    };
    int n_fortunes = sizeof(f) / sizeof(Fortune);

    // seeding the random number generator
    srand(time(NULL));

    // getting the fortune and printing it to the console
    char *fortune = get_fortune(f, n_fortunes);
    printf("Your fortune for today is: \"%s\"\n", fortune);

    return 0;
}