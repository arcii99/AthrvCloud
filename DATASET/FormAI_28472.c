//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Romeo and Juliet
/* Romeo and Juliet's Traffic Light Controller */

#include <stdio.h>
#include <stdlib.h>

/* Define traffic light states */
#define RED     1
#define YELLOW  2
#define GREEN   3

/* Define traffic light durations */
#define RED_DURATION        10
#define YELLOW_DURATION     5
#define GREEN_DURATION      15

/* Define traffic light transition timings */
#define RED_TO_GREEN_TIME   5
#define GREEN_TO_YELLOW_TIME    2
#define YELLOW_TO_RED_TIME  3

/* Define Romeo's traffic light structure */
struct RomeoTrafficLight {
    int state;
    int timer;
};

/* Define Juliet's traffic light structure */
struct JulietTrafficLight {
    int state;
    int timer;
};

/* Romeo's traffic light controller function */
void RomeoController(struct RomeoTrafficLight *light) {
    switch (light->state) {
        case RED:
            printf("Romeo: Oh heavy light, why art thou red?\n");
            if (light->timer >= RED_DURATION) {
                light->timer = 0;
                light->state = GREEN;
            }
            break;
        case YELLOW:
            printf("Romeo: What light through yonder window breaks? It is the east, and Juliet is the sun!\n");
            if (light->timer >= YELLOW_DURATION) {
                light->timer = 0;
                light->state = RED;
            }
            break;
        case GREEN:
            printf("Romeo: But soft! What light through yonder window breaks? It is the east, and Juliet is the sun!\n");
            if (light->timer >= GREEN_DURATION) {
                light->timer = 0;
                light->state = YELLOW;
            }
            break;
    }
}

/* Juliet's traffic light controller function */
void JulietController(struct JulietTrafficLight *light) {
    switch (light->state) {
        case RED:
            printf("Juliet: O Romeo, Romeo, wherefore art thou Romeo?\n");
            if (light->timer >= RED_DURATION) {
                light->timer = 0;
                light->state = GREEN;
            }
            break;
        case YELLOW:
            printf("Juliet: My bounty is as boundless as the sea, My love as deep; the more I give to thee,The more I have, for both are infinite.\n");
            if (light->timer >= YELLOW_DURATION) {
                light->timer = 0;
                light->state = RED;
            }
            break;
        case GREEN:
            printf("Juliet: Good night, good night! parting is such sweet sorrow, That I shall say good night till it be morrow.\n");
            if (light->timer >= GREEN_DURATION) {
                light->timer = 0;
                light->state = YELLOW;
            }
            break;
    }
}

/* Main traffic light controller program */
int main() {
    /* Initialize traffic lights */
    struct RomeoTrafficLight Romeo = { RED, 0 };
    struct JulietTrafficLight Juliet = { GREEN, 0 };

    /* Run traffic light controller */
    while (1) {
        RomeoController(&Romeo);
        JulietController(&Juliet);

        /* Check if transition timings are met */
        if (Romeo.state == RED && Juliet.timer >= GREEN_TO_YELLOW_TIME) {
            Juliet.timer = 0;
            Juliet.state = YELLOW;
        } else if (Juliet.state == YELLOW && Romeo.timer >= YELLOW_TO_RED_TIME) {
            Romeo.timer = 0;
            Romeo.state = YELLOW;
        } else if (Romeo.state == GREEN && Juliet.timer >= RED_TO_GREEN_TIME) {
            Juliet.timer = 0;
            Juliet.state = RED;
        }

        /* Increment timers */
        Romeo.timer++;
        Juliet.timer++;

        /* Wait for 1 second */
        system("sleep 1");
    }

    return 0;
}