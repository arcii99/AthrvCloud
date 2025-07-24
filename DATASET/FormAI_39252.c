//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Surprise! You have stumbled upon an Intrusion Detection System.\n");
    printf("This program will monitor the system and detect any unexpected events.\n");

    srand(time(NULL)); //seed random number generator

    int randNum = rand() % 10; //generate a random number between 0 and 9

    if (randNum < 5) {
        printf("Intrusion detected! Please take appropriate action.\n");
    } else {
        printf("No intrusion detected. Everything seems to be running smoothly.\n");
    }

    return 0;
}