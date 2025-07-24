//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* Behold, a website uptime monitor */
/* Written in a style as old as time */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    int count = 0;
    bool isUp = true;
    char* website = "www.juliet.com";

    printf("Oh wondrous site, %s,\n", website);

    while (count < 5) {
        int random = rand() % 2; // flip a coin
        if (random == 0 && isUp) { // site is down
            isUp = false;
            printf("Oh cruel fate, that %s should go down,\n", website);
        } else if (random == 1 && !isUp) { // site is up
            isUp = true;
            printf("Hark! %s has risen from the dead!\n", website);
        }
        count++; // increment attempt count
    }

    if (!isUp) { // site is still down after 5 attempts
        printf("Lo! Alas! %s is no more,\n", website);
        printf("But fear not, for with code we can restore\n");
        printf("A website uptime monitor, may it be,\n");
        printf("To bring sweet life back to %s for thee.\n", website);
    } else { // site is still up after 5 attempts
        printf("%s stands tall, strong, and true,\n", website);
        printf("With nary a fault, for all to view.\n");
    }

    return 0;
}