//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print random task messages
void print_task_message() {
    int random_num = rand() % 5;
    switch (random_num) {
        case 0:
            printf("You get to write a new feature today! Hooray!\n");
            break;
        case 1:
            printf("You're stuck with debugging today. Better luck tomorrow!\n");
            break;
        case 2:
            printf("It's your turn to do code review. Enjoy!\n");
            break;
        case 3:
            printf("Today, you get to write documentation. Fun!\n");
            break;
        case 4:
            printf("You have to deploy today's build. Good luck with that!\n");
            break;
    }
}

// Main function to schedule tasks
int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the C Task Scheduler!\n\n");

    // Loop through 5 days of tasks
    for (int day = 1; day <= 5; day++) {
        printf("Day %d tasks:\n", day);
        for (int hour = 1; hour <= 8; hour++) {
            printf("Hour %d: ", hour);
            print_task_message();
        }
        printf("\n");
    }

    printf("Congratulations! You made it through the week!\n");

    return 0;
}