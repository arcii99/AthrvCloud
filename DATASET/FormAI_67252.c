//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RED     0
#define YELLOW  1
#define GREEN   2

#define S       1
#define NS      0
#define EW      2
#define SN      3

#define INTERVAL    1
#define YELLOW_TIME 3
#define GREEN_TIME  10

int main ()
{
    srand(time(0));

    int ns_light = GREEN;
    int ew_light = RED;

    int ns_cars = 0;
    int ew_cars = 0;

    int count = 0;
    int yellow = 0;

    while(1)
    {
        // Traffic update
        
        if (rand() % 5 == 0) ns_cars++;
        if (rand() % 5 == 0) ew_cars++;

        if (ns_light == GREEN && ns_cars > 0)
        {
            ns_cars--;
        }
        else if (ew_light == GREEN && ew_cars > 0)
        {
            ew_cars--;
        }
        else if (ns_light == YELLOW || ew_light == YELLOW)
        {
            yellow++;
            if (yellow == YELLOW_TIME) {
                yellow = 0;
                if (ns_light == YELLOW) {
                    ns_light = RED;
                    ew_light = GREEN;
                } else {
                    ns_light = GREEN;
                    ew_light = RED;
                }
            }
        }
        else
        {
            if (ns_light == RED) {
                ns_light = GREEN;
                ew_light = RED;
            } else {
                ns_light = RED;
                ew_light = GREEN;
            }
        }

        // Output
        printf("\n");
        printf("     %s\n", (ns_light == RED) ? "RED" : (ns_light == YELLOW) ? "YELLOW" : "GREEN");
        printf("  NS %s (%d cars)\n", (ns_light == RED || ns_light == YELLOW) ? " " : "*", ns_cars);
        printf("\n");
        printf("  EW %s (%d cars)\n", (ew_light == RED || ew_light == YELLOW) ? " " : "*", ew_cars);
        printf("     %s\n", (ew_light == RED) ? "RED" : (ew_light == YELLOW) ? "YELLOW" : "GREEN");

        count++;
        sleep(INTERVAL);
        system("clear");
    }

    return 0;
}