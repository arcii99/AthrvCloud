//FormAI DATASET v1.0 Category: Random ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the C Random Example Program!\n\n");
    printf("Today, we will be generating some random numbers using the rand() function.\n");
    printf("But here's the catch, we will only be generating numbers between -7 and 13.\n");
    printf("Why, you ask? Well, why not? Let's add some spice to this boring random number program.\n");
    printf("So, let's dive right in!\n\n");

    int randNumber;
    int count = 1;

    printf("Random Numbers:\n");

    while(count <= 20){
        randNumber = rand()%21 - 7;
        printf("%d ", randNumber);
        count++;
    }

    printf("\n\nNow, let's add some more randomness to the program.\n");
    printf("Introducing the Sleep function, which will pause the program for a random amount of time.\n");
    printf("We will also throw in a random seed, just to keep things interesting.\n\n");

    srand(time(NULL));
    count = 1;

    printf("More Random Numbers:\n");

    while(count <= 20){
        randNumber = rand()%21 - 7;
        printf("%d ", randNumber);
        int sleepTime = rand()%5 + 1;
        printf("(Pausing for %d seconds...)\n", sleepTime);
        sleep(sleepTime);
        count++;
    }

    printf("\n\nWell folks, that's all for today's program!\n");
    printf("Hope you had some laughs and learned a thing or two about the rand() function.\n");
    printf("Until next time, keep it random!\n");

    return 0;
}