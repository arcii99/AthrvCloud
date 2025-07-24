//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Grateful Numbers game!\n");

    int player_num;
    srand(time(NULL));
    int c_num = rand() % 100;
    int prev_gratitude = 0;

    while (1){
        printf("Enter a positive integer between 1 and 100: ");
        scanf("%d", &player_num);

        if (player_num < 1 || player_num > 100)
            printf("Invalid input. Please enter a positive integer between 1 and 100.\n");
        else {
            int gratitude = abs(player_num - c_num);
            if (gratitude == 0){
                printf("You have guessed the Grateful Number! Congratulations!\n");
                break;
            }
            else if (gratitude <= prev_gratitude)
                printf("Gratitude increasing! You're getting warmer!\n");
            else 
                printf("Gratitude decreasing. You're getting colder.\n");

            prev_gratitude = gratitude;
        }
    }

    printf("Thank you for playing the Grateful Numbers game! Have a grateful day!\n");

    return 0;
}