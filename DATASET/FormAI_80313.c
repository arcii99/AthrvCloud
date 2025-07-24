//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set random number generator seed to current time

    int fuel = 1000;
    int distance = 0;
    int aliens = 0;

    while (fuel > 0 && distance < 100000) { // travel through space until either fuel or distance runs out
        int event = rand() % 4 + 1; // randomly determine event: 1=asteroid field, 2=alien encounter, 3=space debris, 4=clear space

        switch (event) {
            case 1:
                fuel -= 100; // dodge asteroid field and lose 100 fuel
                printf("Whew! We made it through the asteroid field but lost 100 fuel!\n\n");
                break;
            case 2:
                aliens++; // encounter aliens and log it
                printf("Uh oh, we just ran into some aliens! They seem friendly though.\n\n");
                break;
            case 3:
                fuel -= 50; // avoid space debris and lose 50 fuel
                printf("We had to maneuver around some space debris, but we lost 50 fuel in the process.\n\n");
                break;
            case 4:
                distance += 500; // move forward through clear space
                fuel -= 25; // consume fuel
                printf("Smooth sailing through clear space, we moved 500 light years and lost 25 fuel.\n\n");
                break;
        }

        if (aliens == 3) { // end game if aliens encountered three times
            printf("Uh oh, our peaceful encounter with the aliens took a hostile turn. Game over.\n");
            return 0;
        }

        printf("Fuel remaining: %d\n", fuel);
        printf("Distance traveled: %d\n\n", distance);
    }

    if (fuel <= 0) { // end game if out of fuel
        printf("We ran out of fuel! Game over.\n");
        return 0;
    }
    else { // end game if reached destination
        printf("We made it to our destination! Congratulations, you completed the space adventure!\n");
        return 0;
    }
}