//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int *arr, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    // Initializing the array with numbers from 1 to 20
    int arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }

    printf("Welcome to the Memory Game!\n\n");
    printf("Instructions: \n");
    printf("1. You will be shown a sequence of numbers.\n");
    printf("2. Memorize the sequence as best as you can.\n");
    printf("3. When the sequence is no longer visible, enter the sequence you remembered.\n");
    printf("4. If the sequence you entered is correct, you move on to the next round.\n");
    printf("5. If the sequence you entered is incorrect, you lose and the game ends.\n");
    printf("Let's begin!\n\n");

    int round = 1;
    while (1)
    {
        // Shuffle the array before displaying
        shuffle(arr, 20);

        // Display the sequence
        printf("Round %d: ", round);
        for (int i = 0; i < 10 + round; i++)
        {
            printf("%d ", arr[i]);
            fflush(stdout);
            // Adding a delay of 1 second before showing the next number
            for (int j = 0; j < 100000000; j++);
        }
        printf("\n");

        // Get the user's input and check if it is correct
        printf("Enter the sequence: ");
        int input[30];
        for (int i = 0; i < 10 + round; i++)
        {
            scanf("%d", &input[i]);
        }
        int flag = 1;
        for (int i = 0; i < 10 + round; i++)
        {
            if (input[i] != arr[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("Correct! Moving on to the next round...\n\n");
            round++;
            // Increase the speed of displaying the sequence after each round
            if (round % 3 == 0 && round <= 10)
            {
                printf("Difficulty increased!\n");
                for (int i = 0; i < 300000000; i++);
            }
        }
        else
        {
            printf("Wrong answer! Game over.\n");
            printf("You made it to round %d.\n", round);
            break;
        }
    }

    return 0;
}