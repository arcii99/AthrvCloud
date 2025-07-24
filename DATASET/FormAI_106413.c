//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(long double sec){
    clock_t end_wait = clock() + sec * CLOCKS_PER_SEC;
    while (clock() < end_wait);
}

int main(){
    int red, yellow, green, count = 0;
    char answer;
    srand(time(0));
    printf("Post-apocalyptic Traffic Light Controller\n");
    printf("--------------------------------------------\n");
    do {
        red = rand() % 10 + 1;
        yellow = rand() % 4 + 1;
        green = rand() % 11 + 2;
        printf("Red Light (Stop): %d seconds\n", red);
        wait(red);
        printf("Yellow Light (Prepare to Go): %d seconds\n", yellow);
        wait(yellow);
        printf("Green Light (Go): %d seconds\n", green);
        wait(green);
        count++;
        printf("Total number of cycles: %d \n", count);
        printf("Would you like to continue? (Y/N) ");
        scanf(" %c", &answer);
    } while (answer == 'Y' || answer == 'y');
    printf("Thanks for using the Traffic Light Controller\n");
    return 0;
}