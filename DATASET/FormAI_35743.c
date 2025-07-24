//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int random_num, count = 0;

    srand(time(NULL));

    printf("Welcome to the automated fortune teller!\n");
    printf("I know everything about you and your future...\n");

    while(count < 3) {
        printf("\nEnter a number between 1 and 10: ");

        int user_input;
        scanf("%d", &user_input);

        if(user_input < 1 || user_input > 10) {
            printf("\nInvalid input. Please try again.\n");
            continue;
        }

        random_num = rand() % 10 + 1;

        if(random_num == user_input) {
            printf("\nYou have a strong connection with destiny...\n");
        } else if(random_num < user_input) {
            printf("\nYour future is bright, but be careful...\n");
        } else if(random_num > user_input) {
            printf("\nYou are in great danger! Seek help immediately...\n");
        }

        count++;
    }

    printf("\nYou have exhausted all your chances...\n");
    printf("Thank you for using the automated fortune teller...\n");

    return 0;
}