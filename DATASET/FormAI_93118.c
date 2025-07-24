//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surreal_header() {
    printf("#################################\n");
    printf("# Welcome to the Appointment Scheduler #\n");
    printf("#################################\n\n");
}

void scheduler() {
    srand(time(NULL));
    int appoint_num = rand() % 10 + 1;

    char* appointment[10] = {
        "Flying with the sharks",
        "Relaxing on a marshmallow",
        "Hand gliding through a strawberry field",
        "Scuba diving in a cup of tea",
        "Volcano surfing on a piece of bread",
        "Cloud watching on a unicycle",
        "Exploring a galaxy made of cheese",
        "Rafting down a river of syrup",
        "Sand castle building on a mushroom",
        "Learning to juggle with fireballs"
    };

    printf("You have an appointment to: %s\n\n", appointment[appoint_num]);
}

void surreal_question() {
    printf("Would you like to schedule another appointment? (yes/no): ");
}

int main() {
    surreal_header();

    char answer[10];

    do {
        scheduler();
        surreal_question();
        scanf("%s", answer);
    } while (strcmp(answer, "yes") == 0);

    printf("Exiting the Appointment Scheduler...\n");
    return 0;
}