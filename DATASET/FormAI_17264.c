//FormAI DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, count = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess a number between 1 to 100\n");
    
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess > num)
            printf("Lower number please!\n");
        else if(guess < num)
            printf("Higher number please!\n");
      
        count++;
    }while(guess != num);

    printf("Congratulations! You guessed the number in %d attempts.\n", count);

    return 0;
}