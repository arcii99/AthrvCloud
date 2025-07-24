//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Welcome to the Magical Arithmetic Adventure! \n");
    printf("Please enter the first number (between 1 and 100): ");
    scanf("%d", &num1);

    printf("\nPlease enter the second number (between 1 and 100): ");
    scanf("%d", &num2);

    printf("\nPlease enter the third number (between 1 and 100): ");
    scanf("%d", &num3);

    // Magical Calculation
    int result = (((num1 + num2) * num3) / 2) - (num3 * 3);

    printf("\n\nThe Magical Result is: %d \n\n", result);


    printf("You may go for extra credit and try again. \n");

    int answer;
    printf("\nAre you up for it? (Enter 1 for Yes / 0 for No): ");
    scanf("%d", &answer);

    if(answer == 1) {
        printf("\nPlease enter the first number (between 1 and 100): ");
        scanf("%d", &num1);

        printf("\nPlease enter the second number (between 1 and 100): ");
        scanf("%d", &num2);

        printf("\nPlease enter the third number (between 1 and 100): ");
        scanf("%d", &num3);

         // Magical Calculation Part 2
        int result2 = ((num1 * num2) % num3) * 2;

        printf("\n\nThe Second Magical Result is: %d \n\n", result2); 
    }

    printf("Thank you for playing the Magical Arithmetic Adventure!");

    return 0;
}

// I hope you enjoyed the adventure!