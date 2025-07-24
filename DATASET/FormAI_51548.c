//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int speed = rand() % 101;
    printf("My love, let me test our internet speed before we start our romantic movie night.\n");

    if (speed == 0)
    {
        printf("Oh no, our internet is down. Let's fix it together.\n");
    }
    else if (speed < 50)
    {
        printf("Our internet speed is slow, but that's okay, we can still snuggle closely and enjoy our movie.\n");
    }
    else if (speed < 80)
    {
        printf("Our internet speed is decent, we should be able to watch our movie with minimal buffering.\n");
    }
    else
    {
        printf("Wow, our internet speed is super fast! We can watch multiple movies in one night!\n");
    }
    
    printf("Our current internet speed is: %d Mbps\n", speed);

    return 0;
}