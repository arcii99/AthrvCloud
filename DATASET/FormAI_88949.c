//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int runway1[50], runway2[50], runway3[50], runway4[50], runway5[50];
int counter = 0;
int clock_time = 0;

void add_bags() {
    int random_time = rand() % 5 + 1;
    if (counter < 50) {
        if (random_time == 1) {
            runway1[counter] = random_time;
            printf("Added a bag to Runway 1 at time %d\n", clock_time);
            counter++;
        } else if (random_time == 2) {
            runway2[counter] = random_time;
            printf("Added a bag to Runway 2 at time %d\n", clock_time);
            counter++;
        } else if (random_time == 3) {
            runway3[counter] = random_time;
            printf("Added a bag to Runway 3 at time %d\n", clock_time);
            counter++;
        } else if (random_time == 4) {
            runway4[counter] = random_time;
            printf("Added a bag to Runway 4 at time %d\n", clock_time);
            counter++;
        } else if (random_time == 5) {
            runway5[counter] = random_time;
            printf("Added a bag to Runway 5 at time %d\n", clock_time);
            counter++;
        }
    }
}

void remove_bags() {
    if (runway1[0] == 1) {
        printf("Removed a bag from Runway 1 at time %d\n", clock_time);
        for (int i = 0; i < counter; i++) {
            runway1[i] = runway1[i + 1];
        }
        counter--;
    } else if (runway2[0] == 2) {
        printf("Removed a bag from Runway 2 at time %d\n", clock_time);
        for (int i = 0; i < counter; i++) {
            runway2[i] = runway2[i + 1];
        }
        counter--;
    } else if (runway3[0] == 3) {
        printf("Removed a bag from Runway 3 at time %d\n", clock_time);
        for (int i = 0; i < counter; i++) {
            runway3[i] = runway3[i + 1];
        }
        counter--;
    } else if (runway4[0] == 4) {
        printf("Removed a bag from Runway 4 at time %d\n", clock_time);
        for (int i = 0; i < counter; i++) {
            runway4[i] = runway4[i + 1];
        }
        counter--;
    } else if (runway5[0] == 5) {
        printf("Removed a bag from Runway 5 at time %d\n", clock_time);
        for (int i = 0; i < counter; i++) {
            runway5[i] = runway5[i + 1];
        }
        counter--;
    }
}

int main() {
    srand(time(NULL));
    while (clock_time < 60) {
        add_bags();
        remove_bags();
        clock_time++;
    }
    return 0;
}