//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int passengers = 0, broken_bags = 0, total_bags = 0, conveyor_bags = 0;
int bag_loss_chance = 10, conveyor_speed = 5, max_conveyor_bags = 20;
int max_passengers = 50, max_bags = 2, max_time = 60, max_break_chance = 50;

void passenger_arrival();
int random_bag_count();
int random_break_chance();
int random_delay();
void new_bag();
void conveyor_belt();
void broken_bag();
void end_simulation();

int main() {
    printf("Airport Baggage Handling Simulation\n");
    printf("Number of Passengers: %d\n", max_passengers);
    printf("Maximum Number of Bags per Passenger: %d\n", max_bags);
    printf("Maximum Simulation Time (minutes): %d\n", max_time);
    printf("Chance of Bag Getting Lost: %d%%\n", bag_loss_chance);
    printf("Conveyor Belt Speed (bags/minute): %d\n", conveyor_speed);
    printf("Maximum Number of Bags on Conveyor Belt: %d\n", max_conveyor_bags);
    printf("Chance of a Bag Being Broken: %d%%\n\n", max_break_chance);

    int current_time = 0;
    srand(time(0));

    while (current_time <= max_time) {
        passenger_arrival();
        conveyor_belt();
        current_time++;
    }

    end_simulation();

    return 0;
}

void passenger_arrival() {
    if (passengers < max_passengers) {
        int new_passengers = rand() % 10;

        if (new_passengers + passengers > max_passengers) {
            new_passengers = max_passengers - passengers;
        }

        printf("%d new passengers arrive at the airport.\n\n", new_passengers);

        for (int i = 0; i < new_passengers; i++) {
            int bags = random_bag_count();
            total_bags += bags;
            printf("Passenger %d has %d bags.\n", passengers + 1, bags);

            for (int j = 0; j < bags; j++) {
                new_bag();
            }

            printf("\n");
            passengers++;
        }
    }
}

int random_bag_count() {
    return rand() % max_bags + 1;
}

int random_break_chance() {
    return rand() % max_break_chance + 1;
}

int random_delay() {
    return rand() % 3 + 1;
}

void new_bag() {
    if (rand() % 100 < bag_loss_chance) {
        printf("Bag has been lost.\n");
    } else {
        printf("Bag added to conveyor belt.\n");
        conveyor_bags++;
    }
}

void conveyor_belt() {
    if (conveyor_bags >= max_conveyor_bags) {
        printf("Conveyor belt is full. Bags may be lost or delayed.\n");
        conveyor_bags = max_conveyor_bags;
    }

    for (int i = 0; i < conveyor_speed; i++) {
        if (conveyor_bags > 0) {
            int break_chance = random_break_chance();

            if (break_chance <= 10) {
                printf("A bag has been broken on the conveyor belt.\n");
                broken_bag();
            } else {
                printf("A bag has been removed from the conveyor belt.\n");
                conveyor_bags--;
            }
        }
    }
}

void broken_bag() {
    broken_bags++;

    if (conveyor_bags > 0) {
        printf("Another bag has been removed from the conveyor belt.\n");
        conveyor_bags--;
    }
}

void end_simulation() {
    printf("Simulation has ended.\n");
    printf("%d passengers served.\n", passengers);
    printf("%d bags processed.\n", total_bags);
    printf("%d bags lost.\n", total_bags - conveyor_bags - broken_bags);
    printf("%d bags delayed.\n", max_conveyor_bags - conveyor_bags);
    printf("%d bags broken.\n", broken_bags);
}