//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RollDice() ((rand() % 6) + 1)

int main()
{
    srand(time(NULL));
    int total_rolls = 0;
    int roll_sum = 0;
    int num_rolls;

    while (1)
    {
        printf("Enter the number of rolls (or 0 to exit): ");
        scanf("%d", &num_rolls);
        if (num_rolls == 0)
            break;

        total_rolls += num_rolls;

        for (int i = 1; i <= num_rolls; i++)
        {
            int roll1 = RollDice();
            int roll2 = RollDice();
            int sum = roll1 + roll2;

            printf("Roll %d: %d + %d = %d\n", i, roll1, roll2, sum);
            roll_sum += sum;
        }

        printf("Total Sum: %d\n", roll_sum);
        printf("Average: %d\n", roll_sum / total_rolls);
        printf("\n");
    }

    printf("Total Number of Times Rolled: %d\n", total_rolls);

    return 0;
}