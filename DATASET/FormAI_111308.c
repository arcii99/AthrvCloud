//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_TIME 240

int main() {
    srand(time(NULL));

    int baggage[MAX_BAGGAGE];
    int time[MAX_BAGGAGE];

    int num_bags, total_time;

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    printf("\nBags\tTime\n");
    for(int i = 0; i < num_bags; i++) {
        baggage[i] = rand() % 50 + 1;
        time[i] = rand() % MAX_TIME + 1;
        printf("%d\t%d\n", baggage[i], time[i]);
    }

    total_time = 0;
    for(int i = 0; i < num_bags; i++) {
        total_time += time[i];
    }

    printf("\nTotal time (in minutes) = %d\n", total_time);

    return 0;
}