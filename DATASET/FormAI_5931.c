//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int prob = rand() % 101;

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("Please answer the following questions with surrealistic statements:\n");

    char answer[50];
    printf("What color is your soul?\n");
    scanf("%s", answer);

    int num;
    printf("What is your favorite number?\n");
    scanf("%d", &num);

    char food[50];
    printf("What is your favorite food?\n");
    scanf("%s", food);

    int len = strlen(food);
    char last_letter = food[len-1];

    int result = (last_letter + num) % 100;

    printf("\nCalculating probability...\n\n");

    for (int i = 0; i < 5; i++) {
        printf(".");
        sleep(1);
    }

    printf("\n\nThe probability of an alien invasion is: %d%%\n", result);

    if (result > prob) {
        printf("It seems that an alien invasion is becoming more likely... Beware, %s!\n", answer);
    } else {
        printf("You're in luck, %s! The probability of an alien invasion is still low.\n", answer);
    }

    return 0;
}