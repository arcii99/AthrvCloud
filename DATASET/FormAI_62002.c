//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_num, user_input, count = 0, time_taken;
    clock_t start, end;

    printf("Welcome to the Typing Speed Test Program\n");
    printf("In this program, a random number will be generated and you have to type it as fast as possible.\n");
    printf("Press any key to start\n");
    getchar();
    printf("\n\n");

    while (count < 3) {
        start = clock();

        random_num = rand() % 1000;
        printf("Your number is: %d\n", random_num);

        scanf("%d", &user_input);

        end = clock();

        time_taken = (end - start) * 1000 / CLOCKS_PER_SEC;

        if (user_input != random_num) {
            printf("Incorrect, please try again!\n");
        } else {
            printf("Correct!\n");
            count++;
            printf("Time Taken: %dms\n\n", time_taken);
        }
    }

    printf("Congratulations! You have completed the Typing Speed Test Program.\n");

    return 0;
}